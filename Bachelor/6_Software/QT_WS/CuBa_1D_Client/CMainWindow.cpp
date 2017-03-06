#include "CMainWindow.h"

CMainWindow::CMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    mMenuBarPtr = menuBar();
    mExperimentMenuPtr = mMenuBarPtr->addMenu("Select Experiment");
    QAction* mSensorCalibrationActionPtr = new QAction("Run Sensor-Calibration", this);
    mExperimentMenuPtr->addAction(mSensorCalibrationActionPtr);
    QObject::connect(mSensorCalibrationActionPtr, SIGNAL(triggered()),
                     this, SLOT(runSensorCalibration()));
    QAction* mADCCalibrationActionPtr = new QAction("Run ADC-Calibration", this);
    mExperimentMenuPtr->addAction(mADCCalibrationActionPtr);
    QObject::connect(mADCCalibrationActionPtr, SIGNAL(triggered()),
                     this, SLOT(runADCCalibration()));
    QAction* mControlActionPtr = new QAction("Run Control-Test", this);
    mExperimentMenuPtr->addAction(mControlActionPtr);
    QObject::connect(mControlActionPtr, SIGNAL(triggered()),
                     this, SLOT(runControlTest()));

    mStackedWidgetPtr           = new QStackedWidget;
    mStartWidgetPtr             = new QWidget;
    mSensorCalibrationWidgetPtr = new CSensorCalibrationWidget;
    mADCCalibrationWidgetPtr    = new CADCCalibrationWidget;
    mControlWidgetPtr           = new CControlWidget;

    mStackedWidgetPtr->addWidget(mStartWidgetPtr);
    mStackedWidgetPtr->addWidget(mSensorCalibrationWidgetPtr);
    mStackedWidgetPtr->addWidget(mADCCalibrationWidgetPtr);
    mStackedWidgetPtr->addWidget(mControlWidgetPtr);
    this->setCentralWidget(mStackedWidgetPtr);
    this->showMaximized();

    mRxThreadPtr = new CRxThread;

    QObject::connect(mRxThreadPtr, SIGNAL(sensorDataReceived(const CSensorData&)),
                     mSensorCalibrationWidgetPtr, SLOT(sensorDataReceived(const CSensorData&)));
    QObject::connect(mSensorCalibrationWidgetPtr, SIGNAL(startMeasurement()),
                     mRxThreadPtr, SLOT(runSensorMeasurement()));
    QObject::connect(mSensorCalibrationWidgetPtr, SIGNAL(endMeasurement()),
                     mRxThreadPtr, SLOT(endMeasurement()));

    QObject::connect(mRxThreadPtr, SIGNAL(adcDataReceived(const CSensorData&)),
                     mADCCalibrationWidgetPtr, SLOT(adcDataReceived(const CSensorData&)));
    QObject::connect(mADCCalibrationWidgetPtr, SIGNAL(runADCMeasurement()),
                     mRxThreadPtr, SLOT(runADCMeasurement()));
    QObject::connect(mADCCalibrationWidgetPtr, SIGNAL(endMeasurement()),
                     mRxThreadPtr, SLOT(endMeasurement()));
    QObject::connect(mADCCalibrationWidgetPtr, SIGNAL(setRPM(float)),
                     mRxThreadPtr, SLOT(setRPM(float)));

    QObject::connect(mRxThreadPtr, SIGNAL(phiDataReceived(const CPhi&)),
                     mControlWidgetPtr, SLOT(phiDataReceived(const CPhi&)));
    QObject::connect(mRxThreadPtr, SIGNAL(phi__dDataReceived(const CPhi__d&)),
                     mControlWidgetPtr, SLOT(phi__dDataReceived(const CPhi__d&)));
    QObject::connect(mRxThreadPtr, SIGNAL(psi__dDataReceived(const CPsi__d&)),
                     mControlWidgetPtr, SLOT(psi__dDataReceived(const CPsi__d&)));
    QObject::connect(mControlWidgetPtr, SIGNAL(phiOffsetChanged(float)),
                     mRxThreadPtr, SLOT(phiOffsetChanged(float)));
    QObject::connect(mControlWidgetPtr, SIGNAL(phi__dOffsetChanged(float)),
                     mRxThreadPtr, SLOT(phi__dOffsetChanged(float)));
    QObject::connect(mControlWidgetPtr, SIGNAL(psi__dOffsetChanged(float)),
                     mRxThreadPtr, SLOT(psi__dOffsetChanged(float)));
    QObject::connect(mControlWidgetPtr, SIGNAL(filterChanged(EFilter)),
                     mRxThreadPtr, SLOT(filterChanged(EFilter)));
    QObject::connect(mControlWidgetPtr, SIGNAL(highpassFlagChanged(bool)),
                     mRxThreadPtr, SLOT(highpassFlagChanged(bool)));
    QObject::connect(mControlWidgetPtr, SIGNAL(lqrFlagChanged(bool)),
                     mRxThreadPtr, SLOT(lqrFlagChanged(bool)));
    QObject::connect(mControlWidgetPtr, SIGNAL(obsFlagChanged(bool)),
                     mRxThreadPtr, SLOT(obsFlagChanged(bool)));

    mRxThreadPtr->start();
}
CMainWindow::~CMainWindow()
{

}
void CMainWindow::runSensorCalibration()
{
    mStackedWidgetPtr->setCurrentWidget(mSensorCalibrationWidgetPtr);
}
void CMainWindow::runADCCalibration()
{
    mStackedWidgetPtr->setCurrentWidget(mADCCalibrationWidgetPtr);
}
void CMainWindow::runControlTest()
{
    mStackedWidgetPtr->setCurrentWidget(mControlWidgetPtr);
    mRxThreadPtr->runControlTest();
}
