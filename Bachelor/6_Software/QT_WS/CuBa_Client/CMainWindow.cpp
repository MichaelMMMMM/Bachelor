#include "CMainWindow.h"

CMainWindow::CMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    mStackedWidgetPtr       = new QStackedWidget;
    mSensorCalibrationPtr   = new CSensorCalibration;

    mStackedWidgetPtr->addWidget(mSensorCalibrationPtr);

    this->setCentralWidget(mStackedWidgetPtr);
    this->showMaximized();

}

CMainWindow::~CMainWindow()
{

}
