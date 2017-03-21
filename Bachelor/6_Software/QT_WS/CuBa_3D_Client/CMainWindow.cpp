#include "CMainWindow.h"
#include <QMenu>
#include <QMenuBar>

CMainWindow::CMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //Set up the Menu-Bar
    mMenuBarPtr                     = menuBar();
    mExperimentMenuPtr              = mMenuBarPtr->addMenu("Select Experiment");
    QAction* sensorCalibActionPtr   = new QAction("Run Sensor-Calibration", mMenuBarPtr);
    mExperimentMenuPtr->addAction(sensorCalibActionPtr);
    QObject::connect(sensorCalibActionPtr, SIGNAL(triggered()),
                     this, SLOT(selectSensorCalibration()));
    QAction* adcCalibActionPtr      = new QAction("Run ADC-Calibration", mMenuBarPtr);
    mExperimentMenuPtr->addAction(adcCalibActionPtr);
    QObject::connect(adcCalibActionPtr, SIGNAL(triggered()),
                     this, SLOT(selectADCCalibration()));
    QAction* controlActionPtr       = new QAction("Run LQR-Control", mMenuBarPtr);
    mExperimentMenuPtr->addAction(controlActionPtr);
    QObject::connect(controlActionPtr, SIGNAL(triggered()),
                     this, SLOT(selectLQRControl()));
    QAction* edgeBalActionPtr       = new QAction("Run Edge-Balance", mMenuBarPtr);
    mExperimentMenuPtr->addAction(edgeBalActionPtr);
    QObject::connect(edgeBalActionPtr, SIGNAL(triggered()),
                     this, SLOT(selectEdgeBalanceSLOT()));

    //Create the Stacked-Widget holding the Widgets for the different experiments
    mStackedWidgetPtr       = new QStackedWidget;
    mStartWidgetPtr         = new QWidget;
    mSensorCalibWidgetPtr   = new CSensorCalibWidget;
    mADCCalibWidgetPtr      = new CADCCalibWidget;
    mControlWidgetPtr       = new CControlWidget;
    mEdgeBalanceWidgetPtr   = new CEdgeBalanceWidget;

    mStackedWidgetPtr->addWidget(mStartWidgetPtr);
    mStackedWidgetPtr->addWidget(mSensorCalibWidgetPtr);
    mStackedWidgetPtr->addWidget(mADCCalibWidgetPtr);
    mStackedWidgetPtr->addWidget(mControlWidgetPtr);
    mStackedWidgetPtr->addWidget(mEdgeBalanceWidgetPtr);

    //Setup the Main-Window
    this->setCentralWidget(mStackedWidgetPtr);
    this->showMaximized();

    //Create the Rx-Thread
    mRxThreadPtr = new CRxThread;

    //Connect the signals and slots
    //Sensor-Calib
    QObject::connect(mSensorCalibWidgetPtr, SIGNAL(runSensorMeasurement()),
                     mRxThreadPtr, SLOT(runSensorCalibration()));
    QObject::connect(mSensorCalibWidgetPtr, SIGNAL(endMeasurement()),
                     mRxThreadPtr, SLOT(endMeasurement()));
    QObject::connect(mRxThreadPtr, SIGNAL(sensor1DataReceived(const CMPUData&)),
                     mSensorCalibWidgetPtr, SLOT(sensor1DataReceived(const CMPUData&)));
    QObject::connect(mRxThreadPtr, SIGNAL(sensor2DataReceived(const CMPUData&)),
                     mSensorCalibWidgetPtr, SLOT(sensor2DataReceived(const CMPUData&)));
    QObject::connect(mRxThreadPtr, SIGNAL(sensor3DataReceived(const CMPUData&)),
                     mSensorCalibWidgetPtr, SLOT(sensor3DataReceived(const CMPUData&)));
    QObject::connect(mRxThreadPtr, SIGNAL(sensor4DataReceived(const CMPUData&)),
                     mSensorCalibWidgetPtr, SLOT(sensor4DataReceived(const CMPUData&)));
    QObject::connect(mRxThreadPtr, SIGNAL(sensor5DataReceived(const CMPUData&)),
                     mSensorCalibWidgetPtr, SLOT(sensor5DataReceived(const CMPUData&)));
    QObject::connect(mRxThreadPtr, SIGNAL(sensor6DataReceived(const CMPUData&)),
                     mSensorCalibWidgetPtr, SLOT(sensor6DataReceived(const CMPUData&)));
    //ADC-Calib
    QObject::connect(mRxThreadPtr, SIGNAL(adcDataReceived(const CADCData&)),
                     mADCCalibWidgetPtr, SLOT(onADCDataReceived(const CADCData&)));
    QObject::connect(mADCCalibWidgetPtr, SIGNAL(startADCCalib()),
                     mRxThreadPtr, SLOT(runADCCalibration()));
    QObject::connect(mADCCalibWidgetPtr, SIGNAL(endADCCalib()),
                     mRxThreadPtr, SLOT(endMeasurement()));
    QObject::connect(mADCCalibWidgetPtr, SIGNAL(setTorque(const CTorqueData&)),
                     mRxThreadPtr, SLOT(setTorque(const CTorqueData&)));
    //Control-Test
    QObject::connect(mRxThreadPtr, SIGNAL(gDataReceived(const CGData&)),
                     mControlWidgetPtr, SLOT(gDataReceived(const CGData&)));
    QObject::connect(mRxThreadPtr, SIGNAL(ukDataReceived(const CUKData&)),
                     mControlWidgetPtr, SLOT(ukDataReceived(const CUKData&)));
    QObject::connect(mRxThreadPtr, SIGNAL(urDataReceived(const CURData&)),
                     mControlWidgetPtr, SLOT(urDataReceived(const CURData&)));
    QObject::connect(mRxThreadPtr, SIGNAL(torqueDataReceived(const CTorqueData&)),
                     mControlWidgetPtr, SLOT(torqueDataReceived(const CTorqueData&)));
    QObject::connect(mControlWidgetPtr, SIGNAL(runControlTest()),
                     mRxThreadPtr, SLOT(runControlTest()));
    QObject::connect(mControlWidgetPtr, SIGNAL(stopControlTest()),
                     mRxThreadPtr, SLOT(endMeasurement()));
    QObject::connect(mControlWidgetPtr, SIGNAL(setCompFilterFlag(bool)),
                     mRxThreadPtr, SLOT(setCompFilterFlag(bool)));
    QObject::connect(mControlWidgetPtr, SIGNAL(setOffsetFilterFlag(bool)),
                     mRxThreadPtr, SLOT(setOffsetCorrectionFlag(bool)));
    //Edge-Balance
    QObject::connect(mEdgeBalanceWidgetPtr, SIGNAL(runEdgeBalanceSIG()),
                     mRxThreadPtr, SLOT(runEdgeBalanceSLOT()));
    QObject::connect(mRxThreadPtr, SIGNAL(lqr1DDataReceivedSIG(const Data1D&)),
                     mEdgeBalanceWidgetPtr, SLOT(lqrDataReceivedSLOT(const Data1D&)));
    QObject::connect(mRxThreadPtr, SIGNAL(lqg1DDataReceivedSIG(const Data1D&)),
                     mEdgeBalanceWidgetPtr, SLOT(lqgDataReceivedSLOT(const Data1D&)));
    QObject::connect(mEdgeBalanceWidgetPtr, SIGNAL(stopEdgeBalanceSIG()),
                     mRxThreadPtr, SLOT(endMeasurement()));
    QObject::connect(mEdgeBalanceWidgetPtr, SIGNAL(setOffsetCorrectionFlagSIG(bool)),
                     mRxThreadPtr, SLOT(setOffsetCorrectionFlag(bool)));
    QObject::connect(mEdgeBalanceWidgetPtr, SIGNAL(setLQRFlagSIG(bool)),
                     mRxThreadPtr, SLOT(setLQRFlag(bool)));
    //Start the Rx-Thread
    mRxThreadPtr->start();
}

CMainWindow::~CMainWindow()
{

}
void CMainWindow::selectSensorCalibration()
{
    mStackedWidgetPtr->setCurrentWidget(mSensorCalibWidgetPtr);
}
void CMainWindow::selectADCCalibration()
{
    mStackedWidgetPtr->setCurrentWidget(mADCCalibWidgetPtr);
}
void CMainWindow::selectLQRControl()
{
    mStackedWidgetPtr->setCurrentWidget(mControlWidgetPtr);
}
void CMainWindow::selectEdgeBalanceSLOT()
{
    mStackedWidgetPtr->setCurrentWidget(mEdgeBalanceWidgetPtr);
}
