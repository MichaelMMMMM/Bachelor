#include "CControlWidget.h"

CControlWidget::CControlWidget() : mDrawCounter(0)
{
    mCentralLayoutPtr = new QHBoxLayout;
    this->setLayout(mCentralLayoutPtr);

    mLeftWidgetPtr = new QWidget;
    QSizePolicy leftSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    leftSizePolicy.setHorizontalStretch(4);
    mLeftWidgetPtr->setSizePolicy(leftSizePolicy);

    mRightWidgetPtr = new QWidget;
    QSizePolicy rightSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    rightSizePolicy.setHorizontalStretch(1);
    mRightWidgetPtr->setSizePolicy(rightSizePolicy);

    mCentralLayoutPtr->addWidget(mLeftWidgetPtr);
    mCentralLayoutPtr->addWidget(mRightWidgetPtr);

    mLeftLayoutPtr = new QGridLayout;
    mLeftWidgetPtr->setLayout(mLeftLayoutPtr);

    mPhiPlotPtr     = new QCustomPlot;
    mPhi__dPlotPtr  = new QCustomPlot;
    mPsi__dPlotPtr  = new QCustomPlot;

    mPhiPlotPtr->addGraph();
    mPhiPlotPtr->xAxis->setLabel("Time [s]");
    mPhiPlotPtr->yAxis->setLabel("Phi [deg]");
    mPhiPlotPtr->replot();

    mPhi__dPlotPtr->addGraph();
    mPhi__dPlotPtr->xAxis->setLabel("Time [s]");
    mPhi__dPlotPtr->yAxis->setLabel("Phi__d [deg/s]");
    mPhi__dPlotPtr->replot();

    mPsi__dPlotPtr->addGraph();
    mPsi__dPlotPtr->xAxis->setLabel("Time [s]");
    mPsi__dPlotPtr->yAxis->setLabel("Psi__d [deg/s]");
    mPsi__dPlotPtr->replot();

    mLeftLayoutPtr->addWidget(mPhiPlotPtr, 0, 0);
    mLeftLayoutPtr->addWidget(mPhi__dPlotPtr, 0, 1);
    mLeftLayoutPtr->addWidget(mPsi__dPlotPtr, 1, 1);

    mRightLayoutPtr = new QVBoxLayout;
    mRightWidgetPtr->setLayout(mRightLayoutPtr);

    mPhiOffsetLayoutPtr = new QHBoxLayout;
    mPhiOffsetInputPtr  = new QDoubleSpinBox;
    mPhiOffsetInputPtr->setDecimals(5);
    mPhiOffsetInputPtr->setValue(0.13);
    mPhiOffsetInputPtr->setMaximum(0.78);
    mPhiOffsetInputPtr->setMinimum(-0.78);
    mPhiOffsetInputPtr->setSingleStep(0.00001);
    mPhiOffsetLabelPtr  = new QLabel(QString(QChar(0xc6, 0x03)) + QString(" Offset:"));
    mPhiOffsetButtonPtr = new QPushButton("Adjust Offset");
    mPhiOffsetLayoutPtr->addWidget(mPhiOffsetLabelPtr);
    mPhiOffsetLayoutPtr->addWidget(mPhiOffsetInputPtr);
    mPhiOffsetLayoutPtr->addWidget(mPhiOffsetButtonPtr);
    mRightLayoutPtr->addLayout(mPhiOffsetLayoutPtr);
    QObject::connect(mPhiOffsetButtonPtr, SIGNAL(clicked()),
                     this, SLOT(phiOffsetButtonClicked()));

    mPhi__dOffsetLayoutPtr = new QHBoxLayout;
    mPhi__dOffsetLabelPtr  = new QLabel(QString("d") + QString(QChar(0xc6, 0x03)) + QString("/dt Offset"));
    mPhi__dOffsetInputPtr  = new QDoubleSpinBox;
    mPhi__dOffsetInputPtr->setDecimals(5);
    mPhi__dOffsetInputPtr->setValue(0.0);
    mPhi__dOffsetInputPtr->setMaximum(15.0);
    mPhi__dOffsetInputPtr->setMinimum(-15.0);
    mPhi__dOffsetInputPtr->setSingleStep(0.0001);
    mPhi__dOffsetButtonPtr = new QPushButton("Adjust Offset");
    mPhi__dOffsetLayoutPtr->addWidget(mPhi__dOffsetLabelPtr);
    mPhi__dOffsetLayoutPtr->addWidget(mPhi__dOffsetInputPtr);
    mPhi__dOffsetLayoutPtr->addWidget(mPhi__dOffsetButtonPtr);
    mRightLayoutPtr->addLayout(mPhi__dOffsetLayoutPtr);
    QObject::connect(mPhi__dOffsetButtonPtr, SIGNAL(clicked()),
                     this, SLOT(phi__dOffsetButtonClicked()));

    mPsi__dOffsetLayoutPtr = new QHBoxLayout;
    mPsi__dOffsetLabelPtr  = new QLabel(QString("d") + QString(QChar(0xc8, 0x03)) + QString("/dt Offset"));
    mPsi__dOffsetInputPtr  = new QDoubleSpinBox;
    mPsi__dOffsetInputPtr->setDecimals(5);
    mPsi__dOffsetInputPtr->setValue(0.0);
    mPsi__dOffsetInputPtr->setMaximum(100.0);
    mPsi__dOffsetInputPtr->setMinimum(-100.0);
    mPsi__dOffsetInputPtr->setSingleStep(0.001);
    mPsi__dOffsetButtonPtr = new QPushButton("Adjust Offset");
    mPsi__dOffsetLayoutPtr->addWidget(mPsi__dOffsetLabelPtr);
    mPsi__dOffsetLayoutPtr->addWidget(mPsi__dOffsetInputPtr);
    mPsi__dOffsetLayoutPtr->addWidget(mPsi__dOffsetButtonPtr);
    mRightLayoutPtr->addLayout(mPsi__dOffsetLayoutPtr);
    QObject::connect(mPsi__dOffsetButtonPtr, SIGNAL(clicked()),
                     this, SLOT(psi__dOffsetButtonClicked()));

    mPhiFilterGroupPtr      = new QGroupBox(QString(QChar(0xc6, 0x03)) + QString("-Filter Selection"));
    mPhiFilterLayoutPtr     = new QVBoxLayout;
    mPhiFilterNoneButtonPtr = new QRadioButton("None");
    mPhiFilterCompButtonPtr = new QRadioButton("Complementary");
    mPhiFilterCompButtonPtr->setChecked(true);
    mPhiFilterLayoutPtr->addWidget(mPhiFilterNoneButtonPtr);
    mPhiFilterLayoutPtr->addWidget(mPhiFilterCompButtonPtr);
    mPhiFilterGroupPtr->setLayout(mPhiFilterLayoutPtr);
    mPhiFilterGroupPtr->setStyleSheet("border:1px solid gray;  margin: 0.2em; padding: 0 3px 0 3px; border-radius: 9px;");
    mPhiFilterNoneButtonPtr->setStyleSheet("border: 0px; padding: 20px 0 0 0;");
    mPhiFilterCompButtonPtr->setStyleSheet("border: 0px; padding: 0 0 0 0;");
    mRightLayoutPtr->addWidget(mPhiFilterGroupPtr);
    QObject::connect(mPhiFilterNoneButtonPtr, SIGNAL(clicked(bool)),
                     this, SLOT(phiFilterSelected(bool)));
    QObject::connect(mPhiFilterCompButtonPtr, SIGNAL(clicked(bool)),
                     this, SLOT(phiFilterSelected(bool)));

    mPhi__dFilterGroupPtr           = new QGroupBox(QString("d") + QString(QChar(0xc6, 0x03)) + QString("/dt-Filter Selection"));
    mPhi__dFilterLayoutPtr          = new QVBoxLayout;
    mPhi__dFilterNoneButtonPtr      = new QRadioButton("None");
    mPhi__dFilterPT1_5HzButtonPtr   = new QRadioButton("PT1 (5Hz)");
    mPhi__dFilterPT1_10HzButtonPtr  = new QRadioButton("PT1 (10Hz)");
    mPhi__dFilterNoneButtonPtr->setChecked(true);
    mPhi__dFilterLayoutPtr->addWidget(mPhi__dFilterNoneButtonPtr);
    mPhi__dFilterLayoutPtr->addWidget(mPhi__dFilterPT1_5HzButtonPtr);
    mPhi__dFilterLayoutPtr->addWidget(mPhi__dFilterPT1_10HzButtonPtr);
    mPhi__dFilterGroupPtr->setLayout(mPhi__dFilterLayoutPtr);
    mPhi__dFilterGroupPtr->setStyleSheet("border:1px solid gray; margin: 0.2em; padding: 0 3px 0 3px; border-radius: 9px;");
    mPhi__dFilterNoneButtonPtr->setStyleSheet("border: 0px; padding: 20px 0 0 0;");
    mPhi__dFilterPT1_5HzButtonPtr->setStyleSheet("border: 0px; padding: 0 0 0 0;");
    mPhi__dFilterPT1_10HzButtonPtr->setStyleSheet("border: 0px; padding: 0 0 0 0;");
    mRightLayoutPtr->addWidget(mPhi__dFilterGroupPtr);
    QObject::connect(mPhi__dFilterNoneButtonPtr, SIGNAL(clicked(bool)),
                     this, SLOT(phi__dFilterSelected(bool)));
    QObject::connect(mPhi__dFilterPT1_5HzButtonPtr, SIGNAL(clicked(bool)),
                     this, SLOT(phi__dFilterSelected(bool)));
    QObject::connect(mPhi__dFilterPT1_10HzButtonPtr, SIGNAL(clicked(bool)),
                     this, SLOT(phi__dFilterSelected(bool)));

    mPsi__dFilterGroupPtr           = new QGroupBox(QString("d") + QString(QChar(0xc8, 0x03)) + QString("/dt-Filter Selection"));
    mPsi__dFilterLayoutPtr          = new QVBoxLayout;
    mPsi__dFilterNoneButtonPtr      = new QRadioButton("None");
    mPsi__dFilterPT1_5HzButtonPtr   = new QRadioButton("PT1 (5Hz)");
    mPsi__dFilterPT1_10HzButtonPtr  = new QRadioButton("PT1 (10Hz)");
    mPsi__dFilterNoneButtonPtr->setChecked(true);
    mPsi__dFilterLayoutPtr->addWidget(mPsi__dFilterNoneButtonPtr);
    mPsi__dFilterLayoutPtr->addWidget(mPsi__dFilterPT1_5HzButtonPtr);
    mPsi__dFilterLayoutPtr->addWidget(mPsi__dFilterPT1_10HzButtonPtr);
    mPsi__dFilterGroupPtr->setLayout(mPsi__dFilterLayoutPtr);
    mPsi__dFilterGroupPtr->setStyleSheet("border:1px solid gray; margin: 0.2em; padding: 0 3px 0 3px; border-radius: 9px;");
    mPsi__dFilterNoneButtonPtr->setStyleSheet("border: 0px; padding: 20px 0 0 0;");
    mPsi__dFilterPT1_5HzButtonPtr->setStyleSheet("border: 0px; padding: 0 0 0 0;");
    mPsi__dFilterPT1_10HzButtonPtr->setStyleSheet("border: 0px; padding: 0 0 0 0;");
    mRightLayoutPtr->addWidget(mPsi__dFilterGroupPtr);
    QObject::connect(mPsi__dFilterNoneButtonPtr, SIGNAL(clicked(bool)),
                     this, SLOT(psi__dFilterSelected(bool)));
    QObject::connect(mPsi__dFilterPT1_5HzButtonPtr, SIGNAL(clicked(bool)),
                     this, SLOT(psi__dFilterSelected(bool)));
    QObject::connect(mPsi__dFilterPT1_10HzButtonPtr, SIGNAL(clicked(bool)),
                     this, SLOT(psi__dFilterSelected(bool)));

    mHighpassCheckBoxPtr = new QCheckBox("Enable Highpass-Filters");
    mHighpassCheckBoxPtr->setChecked(false);
    mRightLayoutPtr->addWidget(mHighpassCheckBoxPtr);
    QObject::connect(mHighpassCheckBoxPtr, SIGNAL(clicked(bool)),
                     this, SLOT(highpassCheckboxToggled(bool)));

    mControlGroupPtr    = new QGroupBox("Controller-Selection");
    mControlLayoutPtr   = new QVBoxLayout;
    mControlGroupPtr->setLayout(mControlLayoutPtr);
    mLQRButtonPtr       = new QRadioButton("LQR-Controller");
    mLQRButtonPtr->setChecked(true);
    mCascButtonPtr      = new QRadioButton("Cascade-Controller");
    mControlLayoutPtr->addWidget(mLQRButtonPtr);
    mControlLayoutPtr->addWidget(mCascButtonPtr);
    mControlGroupPtr->setStyleSheet("border:1px solid gray; margin: 0.2em; padding: 0 3px 0 3px; border-radius: 9px;");
    mLQRButtonPtr->setStyleSheet("border: 0px; padding: 20px 0 0 0;");
    mCascButtonPtr->setStyleSheet("border: 0px; padding: 0 0 0 0;");
    mRightLayoutPtr->addWidget(mControlGroupPtr);
    QObject::connect(mLQRButtonPtr, SIGNAL(clicked()),
                     this, SLOT(controllerGroupClicked()));
    QObject::connect(mCascButtonPtr, SIGNAL(clicked()),
                     this, SLOT(controllerGroupClicked()));

    mRightLayoutPtr->addStretch();
}
void CControlWidget::controllerGroupClicked()
{
    if(mLQRButtonPtr->isChecked() == true)
    {
        emit lqrFlagChanged(true);
    }
    else if(mCascButtonPtr->isChecked() == true)
    {
        emit lqrFlagChanged(false);
    }
}

void CControlWidget::highpassCheckboxToggled(bool flag)
{
    if(flag == true)
    {
        mPhiOffsetButtonPtr->setEnabled(false);
        mPhiOffsetInputPtr->setEnabled(false);
        mPhi__dOffsetButtonPtr->setEnabled(false);
        mPhi__dOffsetInputPtr->setEnabled(false);
        mPsi__dOffsetButtonPtr->setEnabled(false);
        mPsi__dOffsetInputPtr->setEnabled(false);
    }
    else
    {
        mPhiOffsetButtonPtr->setEnabled(true);
        mPhiOffsetInputPtr->setEnabled(true);
        mPhi__dOffsetButtonPtr->setEnabled(true);
        mPhi__dOffsetInputPtr->setEnabled(true);
        mPsi__dOffsetButtonPtr->setEnabled(true);
        mPsi__dOffsetInputPtr->setEnabled(true);
    }
    emit highpassFlagChanged(flag);
}

void CControlWidget::phiDataReceived(const CPhi &data)
{
    mPhiTime.append(static_cast<double>(data.mTime));
    mPhi_Comp.append(static_cast<double>(data.mComplementary));
    mPhi_Acc.append(static_cast<double>(data.mEstimation));

    this->drawPlots();
}
void CControlWidget::phi__dDataReceived(const CPhi__d &data)
{
    mPhi__dTime.append(static_cast<double>(data.mTime));
    mPhi__d.append(static_cast<double>(data.mEstimation));

    this->drawPlots();
}
void CControlWidget::psi__dDataReceived(const CPsi__d &data)
{
    mPsi__dTime.append(static_cast<double>(data.mTime));
    mPsi__d.append(static_cast<double>(data.mEstimation));

    this->drawPlots();
}
void CControlWidget::drawPlots()
{
    mDrawCounter++;
    if(mDrawCounter >= 15)
    {
        mDrawCounter = 0;
        if(mPhiTime.length() > 1000)
        {
            mPhiXVector = mPhiTime.mid(mPhiTime.length() - 1000);
            mPhiYVector = mPhi_Comp.mid(mPhi_Comp.length() - 1000);
            mPhiPlotPtr->graph(0)->setData(mPhiXVector, mPhiYVector);
            mPhiPlotPtr->xAxis->setRange(*std::min_element(mPhiXVector.begin(), mPhiXVector.end()),
                                         *std::max_element(mPhiXVector.begin(), mPhiXVector.end()));
            mPhiPlotPtr->yAxis->setRange(*std::min_element(mPhiYVector.begin(), mPhiYVector.end()) - 0.02,
                                         *std::max_element(mPhiYVector.begin(), mPhiYVector.end()) + 0.02);
            mPhiPlotPtr->replot();
        }
        else
        {
            mPhiPlotPtr->graph(0)->setData(mPhiTime, mPhi_Comp);
            mPhiPlotPtr->xAxis->setRange(0.0, *std::max_element(mPhiTime.begin(), mPhiTime.end()));
            mPhiPlotPtr->yAxis->setRange(*std::min_element(mPhi_Comp.begin(), mPhi_Comp.end()) - 0.02,
                                         *std::max_element(mPhi_Comp.begin(), mPhi_Comp.end()) + 0.02);
            mPhiPlotPtr->replot();
        }
        if(mPhi__dTime.length() > 1000)
        {
            mPhi__dXVector = mPhi__dTime.mid(mPhi__dTime.length() - 1000);
            mPhi__dYVector = mPhi__d.mid(mPhi__d.length() - 1000);
            mPhi__dPlotPtr->graph(0)->setData(mPhi__dXVector, mPhi__dYVector);
            mPhi__dPlotPtr->xAxis->setRange(*std::min_element(mPhi__dXVector.begin(), mPhi__dXVector.end()),
                                            *std::max_element(mPhi__dXVector.begin(), mPhi__dXVector.end()));
            mPhi__dPlotPtr->yAxis->setRange(*std::min_element(mPhi__dYVector.begin(), mPhi__dYVector.end()) - 0.05,
                                            *std::max_element(mPhi__dYVector.begin(), mPhi__dYVector.end()) + 0.05);
            mPhi__dPlotPtr->replot();
        }
        else
        {
            mPhi__dPlotPtr->graph(0)->setData(mPhi__dTime, mPhi__d);
            mPhi__dPlotPtr->xAxis->setRange(0.0, *std::max_element(mPhi__dTime.begin(),
                                                                   mPhi__dTime.end()));
            mPhi__dPlotPtr->yAxis->setRange(*std::min_element(mPhi__d.begin(), mPhi__d.end()) - 0.05,
                                            *std::max_element(mPhi__d.begin(), mPhi__d.end()) + 0.05);
            mPhi__dPlotPtr->replot();
        }
        if(mPsi__dTime.length() > 1000)
        {
            mPsi__dXVector = mPsi__dTime.mid(mPsi__dTime.length() - 1000);
            mPsi__dYVector = mPsi__d.mid(mPsi__d.length() - 1000);
            mPsi__dPlotPtr->graph(0)->setData(mPsi__dXVector, mPsi__dYVector);
            mPsi__dPlotPtr->xAxis->setRange(*std::min_element(mPsi__dXVector.begin(), mPsi__dXVector.end()),
                                            *std::max_element(mPsi__dXVector.begin(), mPsi__dXVector.end()));
            mPsi__dPlotPtr->yAxis->setRange(*std::min_element(mPsi__dYVector.begin(), mPsi__dYVector.end()) - 0.1,
                                            *std::max_element(mPsi__dYVector.begin(), mPsi__dYVector.end()) + 0.1);
            mPsi__dPlotPtr->replot();
        }
        else
        {
            mPsi__dPlotPtr->graph(0)->setData(mPsi__dTime, mPsi__d);
            mPsi__dPlotPtr->xAxis->setRange(0.0, *std::max_element(mPsi__dTime.begin(), mPsi__dTime.end()));
            mPsi__dPlotPtr->yAxis->setRange(*std::min_element(mPsi__d.begin(), mPsi__d.end()) - 0.1,
                                            *std::max_element(mPsi__d.begin(), mPsi__d.end()) + 0.1);
            mPsi__dPlotPtr->replot();
        }
    }
}
void CControlWidget::phiOffsetButtonClicked()
{
    float offset = static_cast<float>(mPhiOffsetInputPtr->value());
    emit phiOffsetChanged(offset);
}
void CControlWidget::phi__dOffsetButtonClicked()
{
    float offset = static_cast<float>(mPhi__dOffsetInputPtr->value());
    emit phi__dOffsetChanged(offset);
}
void CControlWidget::psi__dOffsetButtonClicked()
{
    float offset = static_cast<float>(mPsi__dOffsetInputPtr->value());
    emit psi__dOffsetChanged(offset);
}
void CControlWidget::phiFilterSelected(bool toggled)
{
    toggled;
    if(mPhiFilterNoneButtonPtr->isChecked() == true)
    {
        emit filterChanged(EFilter::PHI_NONE);
    }
    else if(mPhiFilterCompButtonPtr->isChecked() == true)
    {
        emit filterChanged(EFilter::PHI_COMP);
    }
}
void CControlWidget::phi__dFilterSelected(bool toggled)
{
    toggled;
    if(mPhi__dFilterNoneButtonPtr->isChecked() == true)
    {
        emit filterChanged(EFilter::PHI__D_NONE);
    }
    else if(mPhi__dFilterPT1_5HzButtonPtr->isChecked() == true)
    {
        emit filterChanged(EFilter::PHI__D_PT1_5HZ);
    }
    else if(mPhi__dFilterPT1_10HzButtonPtr->isChecked() == true)
    {
        emit filterChanged(EFilter::PHI__D_PT1_10HZ);
    }
}
void CControlWidget::psi__dFilterSelected(bool toggled)
{
    toggled;
    if(mPsi__dFilterNoneButtonPtr->isChecked() == true)
    {
        emit filterChanged(EFilter::PSI__D_NONE);
    }
    else if(mPsi__dFilterPT1_5HzButtonPtr->isChecked() == true)
    {
        emit filterChanged(EFilter::PSI__D_PT1_5HZ);
    }
    else if(mPsi__dFilterPT1_10HzButtonPtr->isChecked() == true)
    {
        emit filterChanged(EFilter::PSI__D_PT1_10HZ);
    }
}
