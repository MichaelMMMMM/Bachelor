#ifndef CADCCALIBRATIONWIDGET_H
#define CADCCALIBRATIONWIDGET_H
#include "qcustomplot.h"
#include "Global.h"
#include "CSensorData.h"

#include <QWidget>

class CADCCalibrationWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CADCCalibrationWidget();
    void saveCSV();
signals:
    void setRPM(float rpm);
    void runADCMeasurement();
    void endMeasurement();
public slots:
    void startClicked();
    void adcDataReceived(const CSensorData& data);
    void setDatapoints(int newValue);
    void setRPM(int newValue);
private:
    QVector<double> mTime;
    QVector<double> mADCValue;
    Int32 mNbrOfDatapoints;
    Int32 mRPM;
    bool mSaveFlag;

    QHBoxLayout* mCentralLayoutPtr;
    QWidget* mLeftWidgetPtr;
    QGridLayout* mLeftLayoutPtr;
    QCustomPlot* mADCPlotPtr;

    QWidget* mRightWidgetPtr;
    QVBoxLayout* mRightLayoutPtr;

    QHBoxLayout* mDatapointsLayoutPtr;
    QLabel*      mDatapointsLabelPtr;
    QSpinBox*    mDatapointsInputPtr;

    QHBoxLayout* mRPMInputLayoutPtr;
    QLabel*      mRPMLabelPtr;
    QSpinBox*    mRPMInputPtr;

    QPushButton* mStartButtonPtr;
};

#endif // CADCCALIBRATIONWIDGET_H
