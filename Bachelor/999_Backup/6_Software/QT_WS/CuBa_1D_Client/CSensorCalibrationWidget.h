#ifndef CSENSORCALIBRATIONWIDGET_H
#define CSENSORCALIBRATIONWIDGET_H
#include "CSensorPlotGrid.h"
#include <QWidget>
#include "Global.h"
#include "CSensorData.h"

class QPushButton;
class QLabel;

class CSensorCalibrationWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CSensorCalibrationWidget();

signals:
    void startMeasurement();
    void endMeasurement();
public slots:
    void startMeasurementClicked();
    void measurementFinished();
    void sensorDataReceived(const CSensorData& data);
private:
    QHBoxLayout* mLayoutPtr;
    QWidget* mLeftWidgetPtr;                //Widget to hold the SensorPlotGrid-Layout
    CSensorPlotGrid* mSensorPlotGridPtr;
    QWidget* mRightWidgetPtr;               //Widget to hold the VBoxLayout, which contains buttons etc.
    QVBoxLayout* mRightLayoutPtr;

    QHBoxLayout* mDatapointsInputLayoutPtr;
    QLabel* mDatapointsLabelPtr;
    QSpinBox* mDatapointsInputPtr;

    QHBoxLayout* mPhiInputLayoutPtr;
    QLabel* mPhiLabelPtr;
    QSpinBox* mPhiInputPtr;

    QPushButton* mStartButtonPtr;
};

#endif // CSENSORCALIBRATIONWIDGET_H
