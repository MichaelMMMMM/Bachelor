#ifndef CSENSORCALIBRATION_H
#define CSENSORCALIBRATION_H
#include "CExperimentWidget.h"
#include "CPlot.h"
#include <QPushButton>
#include <QSpinBox>

class CSensorCalibration : public CExperimentWidget
{
    Q_OBJECT
signals:
    void startSensorCalibrationSIG();
    void endMeasurementSIG();
public slots:
    void sensor1DataReceivedSLOT();
    void sensor2DataReceivedSLOT();
    void sensor3DataReceivedSLOT();
    void sensor4DataReceivedSLOT();
    void sensor5DataReceivedSLOT();
    void sensor6DataReceivedSLOT();

    void startButtonClickedSLOT();
    void numberOfValuesChangedSLOT(int newValue);
public:
    CSensorCalibration();
private:
    void createPlots();
    void createControls();
private:
    int mNumberOfValues;

    QPushButton* mStartButtonPtr;

    QHBoxLayout* mValuesLayoutPtr;
    QLabel*      mValuesLabelPtr;
    QSpinBox*    mValuesSpinBoxPtr;

    CPlot*  mSensor1PlotPtr;
    CPlot*  mSensor2PlotPtr;
    CPlot*  mSensor3PlotPtr;
    CPlot*  mSensor4PlotPtr;
    CPlot*  mSensor5PlotPtr;
    CPlot*  mSensor6PlotPtr;

};

#endif // CSENSORCALIBRATION_H
