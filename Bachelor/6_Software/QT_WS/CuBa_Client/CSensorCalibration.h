#ifndef CSENSORCALIBRATION_H
#define CSENSORCALIBRATION_H
#include "CExperimentWidget.h"
#include "CPlot.h"
#include <QPushButton>
#include <QSpinBox>
#include "CMPUData.h"

class CSensorCalibration : public CExperimentWidget
{
    Q_OBJECT
signals:
    void startSensorCalibrationSIG();
    void endMeasurementSIG();
public slots:
    void sensor1DataReceivedSLOT(double time, const CMPUData&);
    void sensor2DataReceivedSLOT(double time, const CMPUData&);
    void sensor3DataReceivedSLOT(double time, const CMPUData&);
    void sensor4DataReceivedSLOT(double time, const CMPUData&);
    void sensor5DataReceivedSLOT(double time, const CMPUData&);
    void sensor6DataReceivedSLOT(double time, const CMPUData&);

    void startButtonClickedSLOT();
    void numberOfValuesChangedSLOT(int newValue);
public:
    CSensorCalibration();
private:
    void createPlots();
    void createControls();
private:
    int mNumberOfValues;
    int mReceivedValues;


    QPushButton* mStartButtonPtr;

    QHBoxLayout* mValuesLayoutPtr;
    QLabel*      mValuesLabelPtr;
    QSpinBox*    mValuesSpinBoxPtr;

    QHBoxLayout* mPhiLayoutPtr;
    QLabel*      mPhiLabelPtr;
    QSpinBox*    mPhiSpinBoxPtr;

    QHBoxLayout* mDegLayoutPtr;
    QLabel*      mDegLabelPtr;
    QSpinBox*    mDegSpinBoxPtr;

    CPlot*  mSensor1PlotPtr;
    CPlot*  mSensor2PlotPtr;
    CPlot*  mSensor3PlotPtr;
    CPlot*  mSensor4PlotPtr;
    CPlot*  mSensor5PlotPtr;
    CPlot*  mSensor6PlotPtr;

};

#endif // CSENSORCALIBRATION_H
