#include "CADCCalibration.h"

CADCCalibration::CADCCalibration() : mNumberOfValues(500)
{
    this->createControls();
    this->createPlots();
}
void CADCCalibration::createControls()
{
    mStartButtonPtr     = new QPushButton("Start Measurement");
    mControlLayoutPtr->addWidget(mStartButtonPtr);

    mValuesLayoutPtr    = new QHBoxLayout;
    mValuesLabelPtr     = new QLabel("Number of Values");
    mValuesSpinBoxPtr   = new QSpinBox;
    mValuesSpinBoxPtr->setMaximum(10000);
    mValuesSpinBoxPtr->setMinimum(100);
    mValuesSpinBoxPtr->setValue(500);
    mValuesLayoutPtr->addWidget(mValuesLabelPtr);
    mValuesLayoutPtr->addWidget(mValuesSpinBoxPtr);
    mControlLayoutPtr->addLayout(mValuesLayoutPtr);

    mControlLayoutPtr->addStretch();

    QObject::connect(mValuesSpinBoxPtr, SIGNAL(valueChanged(int)),
                     this, SLOT(numberOfValuesChangedSLOT(int)));
}
void CADCCalibration::createPlots()
{
    QVector<QString> legend;
    legend.append("ADC-Value");
    QVector<QPen> lineColors;
    lineColors.append(QPen(Qt::blue));
    mADC1PlotPtr = new CPlot(1, "Unsigned Values", "ADC 1", legend, lineColors);
    mADC2PlotPtr = new CPlot(1, "Unsigned Values", "ADC 2", legend, lineColors);
    mADC3PlotPtr = new CPlot(1, "Unsigned Values", "ADC 3", legend, lineColors);

    mPlotLayoutPtr->addWidget(mADC1PlotPtr->getPlotPtr(), 0, 0);
    mPlotLayoutPtr->addWidget(mADC2PlotPtr->getPlotPtr(), 1, 0);
    mPlotLayoutPtr->addWidget(mADC3PlotPtr->getPlotPtr(), 2, 0);
}
void CADCCalibration::numberOfValuesChangedSLOT(int newValue)
{
    mNumberOfValues = newValue;
}
