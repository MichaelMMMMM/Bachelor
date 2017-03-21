#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H
#include <CRxThread.h>
#include <QMainWindow>
#include <QStackedWidget>
#include "CSensorCalibWidget.h"
#include "CADCWidget.h"
#include "CControlWidget.h"
#include "CEdgeBalanceWidget.h"

class CMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    CMainWindow(QWidget *parent = 0);
    ~CMainWindow();
public slots:
    void selectSensorCalibration();
    void selectADCCalibration();
    void selectLQRControl();
    void selectEdgeBalanceSLOT();
private:
    CRxThread* mRxThreadPtr;

    QMenuBar*           mMenuBarPtr;
    QMenu*              mExperimentMenuPtr;
    QStackedWidget*     mStackedWidgetPtr;
    QWidget*            mStartWidgetPtr;
    CSensorCalibWidget* mSensorCalibWidgetPtr;
    CADCCalibWidget*    mADCCalibWidgetPtr;
    CControlWidget*     mControlWidgetPtr;
    CEdgeBalanceWidget* mEdgeBalanceWidgetPtr;
};

#endif // CMAINWINDOW_H
