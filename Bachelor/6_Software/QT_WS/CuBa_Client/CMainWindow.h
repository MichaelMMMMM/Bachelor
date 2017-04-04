#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H
#include <QMainWindow>
#include <QStackedWidget>
#include "CSensorCalibration.h"

class CMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    CMainWindow(QWidget *parent = 0);
    ~CMainWindow();
private:
    QStackedWidget*     mStackedWidgetPtr;
    CSensorCalibration* mSensorCalibrationPtr;
};

#endif // CMAINWINDOW_H
