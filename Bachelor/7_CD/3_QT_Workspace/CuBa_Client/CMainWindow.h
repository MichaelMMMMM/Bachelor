#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H
#include <QMainWindow>
#include <QStackedWidget>
#include <CRxThread.h>
#include "CSensorCalibration.h"
#include "CADCCalibration.h"
#include "CEdgeBalance.h"
#include "CCornerBalance.h"

class CMainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void selectSensorCalibrationSLOT();
    void selectADCCalibrationSLOT();
    void selectEdgeBalanceSLOT();
    void selectCornerBalanceSLOT();
public:
    CMainWindow(QWidget *parent = 0);
    ~CMainWindow();
private:
    void createToolbar();
    void createRxThread();
private:
    CRxThread*          mRxThreadPtr;
    QStackedWidget*     mStackedWidgetPtr;

    QWidget*            mDummyPtr;
    CSensorCalibration* mSensorCalibrationPtr;
    CADCCalibration*    mADCCalibrationPtr;
    CEdgeBalance*       mEdgeBalancePtr;
    CCornerBalance*     mCornerBalancePtr;
};

#endif // CMAINWINDOW_H
