#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H
#include "CClient.h"
#include "CSensorPlotGrid.h"
#include "CRxTask.h"
#include <QMainWindow>

class QCustomPlot;
class QPushButton;

class CMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    void update();
public:
    CMainWindow();
    CMainWindow(const CMainWindow&) = delete;
    CMainWindow& operator=(const CMainWindow&) = delete;
    ~CMainWindow() = default;
private slots:
    void buttonClicked();
private:
    CRxTask mRxTask;

    CSensorPlotGrid* mSensorPlotGrid;
    QPushButton* mButton;
};

#endif // CMAINWINDOW_H
