#ifndef CCONTROLWIDGET_H
#define CCONTROLWIDGET_H
#include "qcustomplot.h"
#include "CTorqueData.h"
#include "CStateData.h"
#include <QWidget>

class CControlWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CControlWidget(QWidget *parent = 0);
    void drawPlots();
    void drawGData();
    void drawUKData();
    void drawURData();
    void drawTorqueData();
signals:
    void runControlTest();
    void stopControlTest();
    void setCompFilterFlag(bool flag);
    void setOffsetFilterFlag(bool flag);
public slots:
    void startButtonClicked();
    void gDataReceived(const CGData& data);
    void ukDataReceived(const CUKData& data);
    void urDataReceived(const CURData& data);
    void torqueDataReceived(const CTorqueData& data);
    void gDisplayClicked(bool state);
    void saveData();
    void onCompFilterBoxClicked();
    void onOffsetBoxClicked();
private:
    int mDrawCounter;
    bool mRunningFlag;
    bool mGDisplayFlag;

    QHBoxLayout*        mCentralLayoutPtr;
    QWidget*            mLeftWidgetPtr;
    QGridLayout*        mLeftLayoutPtr;
    QWidget*            mRightWidgetPtr;
    QVBoxLayout*        mRightLayoutPtr;

    QPushButton*        mStartButtonPtr;
    QCheckBox*          mGDisplayCheckBoxPtr;
    QPushButton*        mSaveButtonPtr;
    QCheckBox*          mCompFilterBoxPtr;
    QCheckBox*          mOffsetBoxPtr;

    QCustomPlot*        mGPlotPtr;
    QCustomPlot*        mUKPlotPtr;
    QCustomPlot*        mURPlotPtr;
    QCustomPlot*        mTorquePlotPtr;

    QVector<CTorqueData> mTorqueData;
    QVector<CGData>      mGData;
    QVector<CUKData>     mUKData;
    QVector<CURData>     mURData;

    QVector<double>     mGTime;
    QVector<double>     mG_k1;
    QVector<double>     mG_k2;
    QVector<double>     mG_k3;

    QVector<double>     mUKTime;
    QVector<double>     mUK_k1;
    QVector<double>     mUK_k2;
    QVector<double>     mUK_k3;

    QVector<double>     mURTime;
    QVector<double>     mUR_k1;
    QVector<double>     mUR_k2;
    QVector<double>     mUR_k3;

    QVector<double>     mTorqueTime;
    QVector<double>     mTM1;
    QVector<double>     mTM2;
    QVector<double>     mTM3;
};

#endif // CCONTROLWIDGET_H
