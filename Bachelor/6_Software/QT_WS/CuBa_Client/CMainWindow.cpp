#include "CMainWindow.h"

CMainWindow::CMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->createToolbar();

    mStackedWidgetPtr       = new QStackedWidget;
    mDummyPtr               = new QWidget;
    mSensorCalibrationPtr   = new CSensorCalibration;
    mADCCalibrationPtr      = new CADCCalibration;

    mStackedWidgetPtr->addWidget(mDummyPtr);
    mStackedWidgetPtr->addWidget(mSensorCalibrationPtr);
    mStackedWidgetPtr->addWidget(mADCCalibrationPtr);

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
