#include "CCornerBalance.h"

CCornerBalance::CCornerBalance() : mRunningFlag(false)
{
    this->createPlots();
    this->createControls();
}
void CCornerBalance::createPlots()
{
    QVector<QString> labels; labels.append("Phi_2"); labels.append("Phi_3");
    QVector<QPen> pens; pens.append(QPen(Qt::blue)); pens.append(QPen(Qt::red));
    mPhiPlotPtr = new CPlot(2, "Phi_i in rad", "Phi_1 and Phi_2", labels, pens);
    labels.clear(); labels.append("UK_1"); labels.append("UK_2"); labels.append("UK_3");
    pens.append(QPen(Qt::green));
    mUKPlotPtr  = new CPlot(3, "UK_i in rad/sec", "UK_1, UK_2 and UK_3", labels, pens);
    labels.clear(); labels.append("UR_1"); labels.append("UR_2"); labels.append("UR_3");
    mURPlotPtr  = new CPlot(3, "UR_i in rad/sec", "UR_1, UR_2 and UR_3", labels, pens);
    labels.clear(); labels.append("TM_1"); labels.append("TM_2"); labels.append("TM_3");
    mUPlotPtr   = new CPlot(3, "TM_i in Nm", "TM_1, TM_2 and TM_3", labels, pens);

    mPlotLayoutPtr->addWidget(mPhiPlotPtr->getPlotPtr(), 0, 0);
    mPlotLayoutPtr->addWidget(mUKPlotPtr->getPlotPtr(), 0, 1);
    mPlotLayoutPtr->addWidget(mURPlotPtr->getPlotPtr(), 1, 0);
    mPlotLayoutPtr->addWidget(mUPlotPtr->getPlotPtr(), 1, 1);
}
void CCornerBalance::createControls()
{
    mStartButtonPtr = new QPushButton("Start Control");
    QObject::connect(mStartButtonPtr, SIGNAL(clicked()),
                     this, SLOT(startButtonSLOT()));
    mControlLayoutPtr->addWidget(mStartButtonPtr);

    mSaveButtonPtr = new QPushButton("Save Data");
    QObject::connect(mSaveButtonPtr, SIGNAL(clicked()),
                     this, SLOT(saveButtonSLOT()));
    mControlLayoutPtr->addWidget(mSaveButtonPtr);

    mReloadButtonPtr = new QPushButton("Reload Configuration");
    QObject::connect(mReloadButtonPtr, SIGNAL(clicked()),
                     this, SLOT(reloadButtonSLOT()));
    mControlLayoutPtr->addWidget(mReloadButtonPtr);

    mControlLayoutPtr->addStretch();
}
void CCornerBalance::startButtonSLOT()
{
    if(mRunningFlag == false)
    {
        mRunningFlag = true;
        mStartButtonPtr->setText("Stop Control");
        mPhiPlotPtr->reset();
        mUKPlotPtr->reset();
        mURPlotPtr->reset();
        mUPlotPtr->reset();
        emit runCornerBalanceSIG();
    }
    else
    {
        mRunningFlag = false;
        mStartButtonPtr->setText("Start Control");
        emit stopCornerBalanceSIG();
    }
}
void CCornerBalance::saveButtonSLOT()
{
    QVector<std::string> varNames; varNames.append("phi2"); varNames.append("phi3");
    mPhiPlotPtr->saveCSV("CornerBalance/phi.csv", varNames, true);
    varNames.clear(); varNames.append("uk1"); varNames.append("uk2"); varNames.append("uk3)");
    mUKPlotPtr->saveCSV("CornerBalance/uk.csv", varNames, true);
    varNames.clear(); varNames.append("ur1"); varNames.append("ur2"); varNames.append("ur3");
    mURPlotPtr->saveCSV("CornerBalance/ur.csv", varNames, true);
    varNames.clear(); varNames.append("tm1"); varNames.append("tm2"); varNames.append("tm3");
    mUPlotPtr->saveCSV("CornerBalance/tm.csv", varNames, true);
}
void CCornerBalance::reloadButtonSLOT()
{
    emit reloadConfigSIG();
}
void CCornerBalance::CompLQR3DPhiReceivedSLOT(double time, QVector<double> data)
{
    mPhiPlotPtr->addData(time, data);
}
void CCornerBalance::CompLQR3DUKReceivedSLOT(double time, QVector<double> data)
{
    mUKPlotPtr->addData(time, data);
}
void CCornerBalance::CompLQR3DURRecievedSLOT(double time, QVector<double> data)
{
    mURPlotPtr->addData(time, data);
}
void CCornerBalance::CompLQR3DTMReceivedSLOT(double time, QVector<double> data)
{
    mUPlotPtr->addData(time, data);
}

