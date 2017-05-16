#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H
#include <QMainWindow>
#include "CSensorCalibrationWidget.h"
#include "CADCCalibrationWidget.h"
#include "CRxThread.h"
#include "CControlWidget.h"

class CMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    CMainWindow(QWidget *parent = 0);
    ~CMainWindow();
public slots:
    void runSensorCalibration();
    void runADCCalibration();
    void runControlTest();
private:
    CRxThread* mRxThreadPtr;

    QMenuBar*                   mMenuBarPtr;
    QMenu*                      mExperimentMenuPtr;
    QStackedWidget*             mStackedWidgetPtr;
    QWidget*                    mStartWidgetPtr;
    CSensorCalibrationWidget*   mSensorCalibrationWidgetPtr;
    CADCCalibrationWidget*      mADCCalibrationWidgetPtr;
    CControlWidget*             mControlWidgetPtr;
};

#endif // CMAINWINDOW_H
