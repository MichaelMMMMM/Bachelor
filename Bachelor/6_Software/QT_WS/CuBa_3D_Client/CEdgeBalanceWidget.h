#ifndef CEDGEBALANCEWIDGET_H
#define CEDGEBALANCEWIDGET_H
#include "qcustomplot.h"
#include "TMatrix.h"
#include "CMessage.h"
#include <QWidget>

class CEdgeBalanceWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CEdgeBalanceWidget(QWidget *parent = 0);
    void redrawPlots();
signals:
    void runEdgeBalanceSIG();
    void stopEdgeBalanceSIG();
    void setOffsetCorrectionFlagSIG(bool flag);
    void setLQRFlagSIG(bool flag);
public slots:
    void startButtonClickedSLOT();
    void lqrDataReceivedSLOT(const Data1D& data);
    void lqgDataReceivedSLOT(const Data1D& data);
    void offsetCheckboxClicked(bool flag);
    void lqrCheckboxClickedSLOT(bool flag);
    void saveCSV();
private:
    int  mDrawCounter;
    bool mRunningFlag;
    bool mSaveFlag;

    QHBoxLayout*        mCentralLayoutPtr;
    QWidget*            mLeftWidgetPtr;
    QGridLayout*        mLeftLayoutPtr;
    QWidget*            mRightWidgetPtr;
    QVBoxLayout*        mRightLayoutPtr;

    QPushButton*        mStartButtonPtr;
    QCheckBox*          mOffsetBoxPtr;
    QCheckBox*          mLQRBoxPtr;
    QPushButton*        mSaveButtonPtr;

    QCustomPlot*        mGPlotPtr;
    QCustomPlot*        mUKPlotPtr;
    QCustomPlot*        mURPlotPtr;
    QCustomPlot*        mTMPlotPtr;

    QVector<TRVector<4U> > mLQRData;
    QVector<TRVector<4U> > mLQGData;

    QVector<double>     mTime;
    QVector<double>     mPhi;
    QVector<double>     mUK;
    QVector<double>     mUR;
    QVector<double>     mTM;

    QVector<double>     mLQRTime;
    QVector<double>     mLQGTime;

    QVector<double>     mGLQR;
    QVector<double>     mGLQG;

    QVector<double>     mUKLQR;
    QVector<double>     mUKLQG;

    QVector<double>     mURLQR;
    QVector<double>     mURLQG;

    QVector<double>     mTMLQR;
    QVector<double>     mTMLQG;

};

#endif // CEDGEBALANCEWIDGET_H
