#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H
#include <CRxThread.h>
#include <QMainWindow>
#include <QStackedWidget>
#include "CSensorCalibWidget.h"
#include "CADCWidget.h"

class CMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    CMainWindow(QWidget *parent = 0);
    ~CMainWindow();
public slots:
    void selectSensorCalibration();
    void selectADCCalibration();
private:
    CRxThread* mRxThreadPtr;

    QMenuBar*           mMenuBarPtr;
    QMenu*              mExperimentMenuPtr;
    QStackedWidget*     mStackedWidgetPtr;
    QWidget*            mStartWidgetPtr;
    CSensorCalibWidget* mSensorCalibWidgetPtr;
    CADCCalibWidget*    mADCCalibWidgetPtr;
};

#endif // CMAINWINDOW_H
