#include "CEdgeBalance.h"


CEdgeBalance::CEdgeBalance() : mStartedFlag(false)
{
    this->createControls();
    this->createPlots();
}
void CEdgeBalance::createPlots()
{
    QVector<QString> labels;
    labels.append("Comp-Filter"); labels.append("Phi-Observer"); labels.append("Offset-Observer");
    QVector<QPen> pens;
    pens.append(QPen(Qt::blue)); pens.append(QPen(Qt::red)); pens.append(QPen(Qt::green));
    mPhiPlotPtr = new CPlot(3, "Phi in rad", "X1/Phi", labels, pens);
    labels.clear();
    labels.append("State-Estimate"); labels.append("Phi-Observer"); labels.append("Offset-Observer");
    mUKPlotPtr  = new CPlot(3, "U_K in rad/sec", "X2/U_K", labels, pens);
    labels.clear();
    labels.append("State-Estimate"); labels.append("Phi-Observer"); labels.append("Offset-Observer");
    mURPlotPtr  = new CPlot(3, "U_R in rad/sec", "X3/U_R", labels, pens);
    labels.clear();
    labels.append("Comp-Filter + LQR"); labels.append("Phi-Observer"); labels.append("Offset-Observer");
    mUPlotPtr   = new CPlot(3, "T_M in Nm", "U/T_M", labels, pens);

    mPlotLayoutPtr->addWidget(mPhiPlotPtr->getPlotPtr(), 0, 0);
    mPlotLayoutPtr->addWidget(mUKPlotPtr->getPlotPtr(), 0, 1);
    mPlotLayoutPtr->addWidget(mURPlotPtr->getPlotPtr(), 1, 0);
    mPlotLayoutPtr->addWidget(mUPlotPtr->getPlotPtr(), 1, 1);
}
void CEdgeBalance::createControls()
{
    mStartButtonPtr = new QPushButton("Start Balancing");
    QObject::connect(mStartButtonPtr, SIGNAL(clicked()),
                     this, SLOT(startButtonSLOT()));
    mControlLayoutPtr->addWidget(mStartButtonPtr);


    mSaveButtonPtr = new QPushButton("Save Data");
    QObject::connect(mSaveButtonPtr, SIGNAL(clicked()),
                     this, SLOT(saveButtonSLOT()));
    mControlLayoutPtr->addWidget(mSaveButtonPtr);

    this->createOffsetControls();

    QFrame* radioFrame = new QFrame;
    radioFrame->setFrameStyle(QFrame::Box);
    QPalette* palette = new QPalette();
    palette->setColor(QPalette::Foreground, Qt::black);
    radioFrame->setPalette(*palette);
    QVBoxLayout* radioLayout = new QVBoxLayout;
    radioFrame->setLayout(radioLayout);

    QLabel* radioLabel  = new QLabel("Select Control-System:");
    mCompLQRButtonPtr   = new QRadioButton("Comp-Filter/LQR");
    mCompLQRButtonPtr->setChecked(true);
    mCompLQRButtonPtr->setToolTip("LQR-Controller using a Complementary-Filter for Phi.");
    mPhiObsLQRButtonPtr = new QRadioButton("Phi-Observer/LQR");
    mPhiObsLQRButtonPtr->setToolTip("LQR Controller using a Luenberger-Oberserver to estimate the state vector from the angular velocities U_K and U_R.");

    QObject::connect(mCompLQRButtonPtr, SIGNAL(clicked()),
                     this, SLOT(controlRadioButtonSLOT()));
    QObject::connect(mPhiObsLQRButtonPtr, SIGNAL(clicked()),
                     this, SLOT(controlRadioButtonSLOT()));

    radioLayout->addWidget(radioLabel);
    radioLayout->addWidget(mCompLQRButtonPtr);
    radioLayout->addWidget(mPhiObsLQRButtonPtr);

    mControlLayoutPtr->addWidget(radioFrame);

    mControlLayoutPtr->addStretch();
}
void CEdgeBalance::compLQR1DDataReceivedSLOT(double time, QVector<double> data)
{
    mPhiPlotPtr->addData(time, data.at(0), 0);
    mUKPlotPtr->addData(time, data.at(1), 0);
    mURPlotPtr->addData(time, data.at(2), 0);
    mUPlotPtr->addData(time, data.at(3), 0);
}
void CEdgeBalance::phiObsLQR1DDataReceivedSLOT(double time, QVector<double> data)
{
    mPhiPlotPtr->addData(time, data.at(0), 1);
    mUKPlotPtr->addData(time, data.at(1), 1);
    mURPlotPtr->addData(time, data.at(2), 1);
    mUPlotPtr->addData(time, data.at(3), 1);
}
void CEdgeBalance::offsetObsLQR1DDataReceivedSLOT(double time, QVector<double> data)
{
    mPhiPlotPtr->addData(time, data.at(0), 2);
    mUKPlotPtr->addData(time, data.at(1), 2);
    mURPlotPtr->addData(time, data.at(2), 2);
    mUPlotPtr->addData(time, data.at(3), 2);
}
void CEdgeBalance::startButtonSLOT()
{
    if(mStartedFlag == false)
    {
        mPhiPlotPtr->reset();
        mUKPlotPtr->reset();
        mURPlotPtr->reset();
        mUPlotPtr->reset();

        mStartedFlag = true;
        emit runEdgeBalanceSIG();
        mStartButtonPtr->setText("Stop Balancing");
    }
    else
    {
        mStartedFlag = false;
        emit stopEdgeBalanceSIG();
        mStartButtonPtr->setText("Start Balancing");
    }
}
void CEdgeBalance::saveButtonSLOT()
{
    QVector<std::string> var;
    var.append("x1_compfilter"); var.append("x1_phiobs");
    mPhiPlotPtr->saveCSV("EdgeBalance/edge_x1.csv", var);
    var.clear(); var.append("x2_estimate"); var.append("x2_phiobs");
    mUKPlotPtr->saveCSV("EdgeBalance/edge_x2.csv", var);
    var.clear(); var.append("x3_estimate"); var.append("x3_phiobs");
    mURPlotPtr->saveCSV("EdgeBalance/edge_x3.csv", var);
    var.clear(); var.append("u_comp_lqr"); var.append("u_phiobs");
    mUPlotPtr->saveCSV("EdgeBalance/edge_u.csv", var);
}
void CEdgeBalance::createOffsetControls()
{
    mOffsetWidgetPtr     = new QFrame;
    mOffsetWidgetPtr->setFrameStyle(QFrame::Box);
    QPalette* palette = new QPalette();
    palette->setColor(QPalette::Foreground, Qt::black);
    mOffsetWidgetPtr->setPalette(*palette);
    mOffsetLayoutPtr    = new QVBoxLayout;
    mOffsetWidgetPtr->setLayout(mOffsetLayoutPtr);

    mPhiOffsetLayoutPtr = new QHBoxLayout;
    mPhiOffsetLabelPtr  = new QLabel("Phi-Offset");
    mPhiOffsetInputPtr  = new QDoubleSpinBox;
    mPhiOffsetInputPtr->setMaximum(5.0);
    mPhiOffsetInputPtr->setMinimum(-5.0);
    mPhiOffsetInputPtr->setSingleStep(0.001);
    mPhiOffsetInputPtr->setDecimals(3);
    mPhiOffsetLayoutPtr->addWidget(mPhiOffsetLabelPtr);
    mPhiOffsetLayoutPtr->addWidget(mPhiOffsetInputPtr);

    mUKOffsetLayoutPtr = new QHBoxLayout;
    mUKOffsetLabelPtr  = new QLabel("U_K-Offset");
    mUKOffsetInputPtr  = new QDoubleSpinBox;
    mUKOffsetInputPtr->setMaximum(10.0);
    mUKOffsetInputPtr->setMinimum(-10.0);
    mUKOffsetInputPtr->setSingleStep(0.001);
    mUKOffsetInputPtr->setDecimals(3);
    mUKOffsetLayoutPtr->addWidget(mUKOffsetLabelPtr);
    mUKOffsetLayoutPtr->addWidget(mUKOffsetInputPtr);

    mUROffsetLayoutPtr = new QHBoxLayout;
    mUROffsetLabelPtr  = new QLabel("U_R-Offset");
    mUROffsetInputPtr  = new QDoubleSpinBox;
    mUROffsetInputPtr->setMaximum(30.0);
    mUROffsetInputPtr->setMinimum(-30.0);
    mUROffsetInputPtr->setSingleStep(0.01);
    mUROffsetInputPtr->setDecimals(2);
    mUROffsetLayoutPtr->addWidget(mUROffsetLabelPtr);
    mUROffsetLayoutPtr->addWidget(mUROffsetInputPtr);

    mOffsetButtonPtr = new QPushButton("Update Offset");
    QObject::connect(mOffsetButtonPtr, SIGNAL(clicked()),
                     this, SLOT(offsetButtonSLOT()));

    mOffsetLayoutPtr->addLayout(mPhiOffsetLayoutPtr);
    mOffsetLayoutPtr->addLayout(mUKOffsetLayoutPtr);
    mOffsetLayoutPtr->addLayout(mUROffsetLayoutPtr);
    mOffsetLayoutPtr->addWidget(mOffsetButtonPtr);
    mControlLayoutPtr->addWidget(mOffsetWidgetPtr);
}
void CEdgeBalance::offsetButtonSLOT()
{
    emit setPhiOffsetSIG(mPhiOffsetInputPtr->value());
    emit setUKOffsetSIG(mUKOffsetInputPtr->value());
    emit setUROffsetSIG(mUROffsetInputPtr->value());
}
void CEdgeBalance::controlRadioButtonSLOT()
{
    if(mCompLQRButtonPtr->isChecked() == true)
    {
        emit selectControlSystemSIG(E1DControlSystem::COMP_LQR);
    }
    else if(mPhiObsLQRButtonPtr->isChecked() == true)
    {
        emit selectControlSystemSIG(E1DControlSystem::PHI_OBS_LQR);
    }
}
