#include "CMainWindow.h"

CMainWindow::CMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->createToolbar();

    mStackedWidgetPtr       = new QStackedWidget;
    mDummyPtr               = new QWidget;
    mSensorCalibrationPtr   = new CSensorCalibration;
    mADCCalibrationPtr      = new CADCCalibration;
    mEdgeBalancePtr         = new CEdgeBalance;
    mCornerBalancePtr       = new CCornerBalance;

    mStackedWidgetPtr->addWidget(mDummyPtr);
    mStackedWidgetPtr->addWidget(mSensorCalibrationPtr);
    mStackedWidgetPtr->addWidget(mADCCalibrationPtr);
    mStackedWidgetPtr->addWidget(mEdgeBalancePtr);
    mStackedWidgetPtr->addWidget(mCornerBalancePtr);

    this->createRxThread();

    this->setCentralWidget(mStackedWidgetPtr);
    this->showMaximized();
}
void CMainWindow::createToolbar()
{
    auto menuBarPtr     = menuBar();
    auto experimentPtr  = menuBarPtr->addMenu("Select Experiment");
    auto sensorCalibPtr = new QAction("Run Sensor-Calibration", menuBarPtr);
    experimentPtr->addAction(sensorCalibPtr);
    QObject::connect(sensorCalibPtr, SIGNAL(triggered()),
                     this, SLOT(selectSensorCalibrationSLOT()));

    auto adcCalibPtr    = new QAction("Run ADC-Calibration", menuBarPtr);
    experimentPtr->addAction(adcCalibPtr);
    QObject::connect(adcCalibPtr, SIGNAL(triggered()),
                     this, SLOT(selectADCCalibrationSLOT()));

    auto edgePtr        = new QAction("Run Edge-Balancing", menuBarPtr);
    experimentPtr->addAction(edgePtr);
    QObject::connect(edgePtr, SIGNAL(triggered()),
                     this, SLOT(selectEdgeBalanceSLOT()));

    auto cornerPtr      = new QAction("Run Corner-Balancing", menuBarPtr);
    experimentPtr->addAction(cornerPtr);
    QObject::connect(cornerPtr, SIGNAL(triggered()),
                     this, SLOT(selectCornerBalanceSLOT()));
}
void CMainWindow::createRxThread()
{
    mRxThreadPtr = new CRxThread;

    //SensorCalibration
    QObject::connect(mSensorCalibrationPtr, SIGNAL(startSensorCalibrationSIG()),
                     mRxThreadPtr, SLOT(runSensorCalibration()));
    QObject::connect(mSensorCalibrationPtr, SIGNAL(endMeasurementSIG()),
                     mRxThreadPtr, SLOT(endMeasurement()));
    QObject::connect(mRxThreadPtr, SIGNAL(sensor1DataReceived(double, const CMPUData&)),
                     mSensorCalibrationPtr, SLOT(sensor1DataReceivedSLOT(double, const CMPUData&)));
    QObject::connect(mRxThreadPtr, SIGNAL(sensor2DataReceived(double, const CMPUData&)),
                     mSensorCalibrationPtr, SLOT(sensor2DataReceivedSLOT(double, const CMPUData&)));
    QObject::connect(mRxThreadPtr, SIGNAL(sensor3DataReceived(double, const CMPUData&)),
                     mSensorCalibrationPtr, SLOT(sensor3DataReceivedSLOT(double, const CMPUData&)));
    QObject::connect(mRxThreadPtr, SIGNAL(sensor4DataReceived(double, const CMPUData&)),
                     mSensorCalibrationPtr, SLOT(sensor4DataReceivedSLOT(double, const CMPUData&)));
    QObject::connect(mRxThreadPtr, SIGNAL(sensor5DataReceived(double, const CMPUData&)),
                     mSensorCalibrationPtr, SLOT(sensor5DataReceivedSLOT(double, const CMPUData&)));
    QObject::connect(mRxThreadPtr, SIGNAL(sensor6DataReceived(double, const CMPUData&)),
                     mSensorCalibrationPtr, SLOT(sensor6DataReceivedSLOT(double, const CMPUData&)));
    //ADCCalibration
    QObject::connect(mADCCalibrationPtr, SIGNAL(startADCCalibrationSIG()),
                     mRxThreadPtr, SLOT(runADCCalibrationSLOT()));
    QObject::connect(mADCCalibrationPtr, SIGNAL(endMeasurementSIG()),
                     mRxThreadPtr, SLOT(endMeasurement()));
    QObject::connect(mRxThreadPtr, SIGNAL(adcDataReceivedSIG(double, const CADCData&)),
                     mADCCalibrationPtr, SLOT(adcDataReceivedSLOT(double, const CADCData&)));

    //Edge-Balance
    QObject::connect(mEdgeBalancePtr, SIGNAL(runEdgeBalanceSIG()),
                     mRxThreadPtr, SLOT(runEdgeBalanceSLOT()));
    QObject::connect(mEdgeBalancePtr, SIGNAL(stopEdgeBalanceSIG()),
                     mRxThreadPtr, SLOT(endMeasurement()));
    QObject::connect(mRxThreadPtr, SIGNAL(CompLQR1DDataReceivedSIG(double,QVector<double>)),
                     mEdgeBalancePtr, SLOT(compLQR1DDataReceivedSLOT(double,QVector<double>)));
    QObject::connect(mRxThreadPtr, SIGNAL(PhiObsLQR1DDataReceiveSIG(double,QVector<double>)),
                     mEdgeBalancePtr, SLOT(phiObsLQR1DDataReceivedSLOT(double,QVector<double>)));
    QObject::connect(mRxThreadPtr, SIGNAL(OffsetObsLQR1DDataReceivedSIG(double,QVector<double>)),
                     mEdgeBalancePtr, SLOT(offsetObsLQR1DDataReceivedSLOT(double,QVector<double>)));
    QObject::connect(mEdgeBalancePtr, SIGNAL(setPhiOffsetSIG(double)),
                     mRxThreadPtr, SLOT(setPhiOffsetSLOT(double)));
    QObject::connect(mEdgeBalancePtr, SIGNAL(setUKOffsetSIG(double)),
                     mRxThreadPtr, SLOT(setUKOffsetSLOT(double)));
    QObject::connect(mEdgeBalancePtr, SIGNAL(setUROffsetSIG(double)),
                     mRxThreadPtr, SLOT(setUROffsetSLOT(double)));
    QObject::connect(mEdgeBalancePtr, SIGNAL(selectControlSystemSIG(E1DControlSystem)),
                     mRxThreadPtr, SLOT(selectControlSystemSLOT(E1DControlSystem)));

    //Corner-Balance
    QObject::connect(mCornerBalancePtr, SIGNAL(runCornerBalanceSIG()),
                     mRxThreadPtr, SLOT(runCornerBalanceSLOT()));
    QObject::connect(mCornerBalancePtr, SIGNAL(stopCornerBalanceSIG()),
                     mRxThreadPtr, SLOT(endMeasurement()));
    QObject::connect(mRxThreadPtr, SIGNAL(CompLQR3DPhiReceivedSIG(double,QVector<double>)),
                     mCornerBalancePtr, SLOT(CompLQR3DPhiReceivedSLOT(double,QVector<double>)));
    QObject::connect(mRxThreadPtr, SIGNAL(CompLQR3DUKReceivedSIG(double,QVector<double>)),
                     mCornerBalancePtr, SLOT(CompLQR3DUKReceivedSLOT(double,QVector<double>)));
    QObject::connect(mRxThreadPtr, SIGNAL(CompLQR3DURReceivedSIG(double,QVector<double>)),
                     mCornerBalancePtr, SLOT(CompLQR3DURRecievedSLOT(double,QVector<double>)));
    QObject::connect(mRxThreadPtr, SIGNAL(CompLQR3DTMReceivedSIG(double,QVector<double>)),
                     mCornerBalancePtr, SLOT(CompLQR3DTMReceivedSLOT(double,QVector<double>)));
    QObject::connect(mCornerBalancePtr, SIGNAL(reloadConfigSIG()),
                     mRxThreadPtr, SLOT(reloadConfigSLOT()));

    mRxThreadPtr->start();
}

CMainWindow::~CMainWindow()
{

}
void CMainWindow::selectSensorCalibrationSLOT()
{
    mStackedWidgetPtr->setCurrentWidget(mSensorCalibrationPtr);
}
void CMainWindow::selectADCCalibrationSLOT()
{
    mStackedWidgetPtr->setCurrentWidget(mADCCalibrationPtr);
}
void CMainWindow::selectEdgeBalanceSLOT()
{
    mStackedWidgetPtr->setCurrentWidget(mEdgeBalancePtr);
}
void CMainWindow::selectCornerBalanceSLOT()
{
    mStackedWidgetPtr->setCurrentWidget(mCornerBalancePtr);
}
