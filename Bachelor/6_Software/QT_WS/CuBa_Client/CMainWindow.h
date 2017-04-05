#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H
#include <QMainWindow>
#include <QStackedWidget>
#include "CSensorCalibration.h"
#include "CADCCalibration.h"

class CMainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void selectSensorCalibrationSLOT();
    void selectADCCalibrationSLOT();
public:
    CMainWindow(QWidget *parent = 0);
    ~CMainWindow();
private:
    void createToolbar();
private:
    QStackedWidget*     mStackedWidgetPtr;

    QWidget*            mDummyPtr;
    CSensorCalibration* mSensorCalibrationPtr;
    CADCCalibration*    mADCCalibrationPtr;
};

#endif // CMAINWINDOW_H
