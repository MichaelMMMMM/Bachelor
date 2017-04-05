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
