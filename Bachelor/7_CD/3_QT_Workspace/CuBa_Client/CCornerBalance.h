#ifndef CCORNERBALANCEH_H
#define CCORNERBALANCEH_H
#include "CExperimentWidget.h"
#include "CPlot.h"

class CCornerBalance : public CExperimentWidget
{
    Q_OBJECT
signals:
    void runCornerBalanceSIG();
    void stopCornerBalanceSIG();
    void reloadConfigSIG();
public slots:
    void CompLQR3DPhiReceivedSLOT(double time, QVector<double> data);
    void CompLQR3DUKReceivedSLOT(double time, QVector<double> data);
    void CompLQR3DURRecievedSLOT(double time, QVector<double> data);
    void CompLQR3DTMReceivedSLOT(double time, QVector<double> data);

    void startButtonSLOT();
    void saveButtonSLOT();
    void reloadButtonSLOT();
public:
    CCornerBalance();

private:
    void createControls();
    void createPlots();
private:
    CPlot*  mPhiPlotPtr;
    CPlot*  mUKPlotPtr;
    CPlot*  mURPlotPtr;
    CPlot*  mUPlotPtr;

    bool         mRunningFlag;
    QPushButton* mStartButtonPtr;
    QPushButton* mSaveButtonPtr;
    QPushButton* mReloadButtonPtr;
};

#endif // CCORNERBALANCEH_H
