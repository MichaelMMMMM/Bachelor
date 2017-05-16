#ifndef CADCWIDGET_H
#define CADCWIDGET_H

#include <QWidget>
#include "qcustomplot.h"
#include "CADCData.h"
#include "CTorqueData.h"

class CADCCalibWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CADCCalibWidget();
    void saveCSV();
signals:
    void startADCCalib();
    void endADCCalib();
    void setTorque(const CTorqueData& data);
public slots:
    void startClicked();
    void onADCDataReceived(const CADCData&);
private:
    int  mDrawCounter;
    bool mSavedFlag;

    QHBoxLayout*    mCentralLayoutPtr;
    QWidget*        mLeftWidgetPtr;
    QGridLayout*    mLeftLayoutPtr;
    QWidget*        mRightWidgetPtr;
    QVBoxLayout*    mRightLayoutPtr;
    QHBoxLayout*    mTorqueInputLayoutPtr;
    QLabel*         mTorqueInputLabelPtr;
    QDoubleSpinBox* mTorqueInputPtr;
    QPushButton*    mStartButtonPtr;

    QCustomPlot* mADC1PlotPtr;
    QCustomPlot* mADC2PlotPtr;
    QCustomPlot* mADC3PlotPtr;

    QVector<double> mTime;
    QVector<double> mADC1Value;
    QVector<double> mADC2Value;
    QVector<double> mADC3Value;
};

#endif // CADCWIDGET_H
