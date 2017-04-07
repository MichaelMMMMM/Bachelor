#ifndef CADCCALIBRATION_H
#define CADCCALIBRATION_H
#include "CExperimentWidget.h"
#include "CPlot.h"
#include "CADCData.h"

class CADCCalibration : public CExperimentWidget
{
    Q_OBJECT
signals:
    void startADCCalibrationSIG();
    void endMeasurementSIG();
public slots:
    void numberOfValuesChangedSLOT(int newValue);
    void startButtonClickedLSLOT();
    void adcDataReceivedSLOT(double time, const CADCData&);
public:
    CADCCalibration();
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

    CPlot* mADC1PlotPtr;
    CPlot* mADC2PlotPtr;
    CPlot* mADC3PlotPtr;
};

#endif // CADCCALIBRATION_H
