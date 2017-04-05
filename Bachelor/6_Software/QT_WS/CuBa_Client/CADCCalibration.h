#ifndef CADCCALIBRATION_H
#define CADCCALIBRATION_H
#include "CExperimentWidget.h"
#include "CPlot.h"

class CADCCalibration : public CExperimentWidget
{
    Q_OBJECT
public slots:
    void numberOfValuesChangedSLOT(int newValue);
public:
    CADCCalibration();
private:
    void createPlots();
    void createControls();
private:
    int mNumberOfValues;

    QPushButton* mStartButtonPtr;

    QHBoxLayout* mValuesLayoutPtr;
    QLabel*      mValuesLabelPtr;
    QSpinBox*    mValuesSpinBoxPtr;

    CPlot* mADC1PlotPtr;
    CPlot* mADC2PlotPtr;
    CPlot* mADC3PlotPtr;
};

#endif // CADCCALIBRATION_H
