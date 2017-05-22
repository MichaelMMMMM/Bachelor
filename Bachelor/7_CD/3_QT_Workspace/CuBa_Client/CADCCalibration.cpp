#include "CADCCalibration.h"

CADCCalibration::CADCCalibration() : mNumberOfValues(500),
                                     mReceivedValues(0)
{
    this->createControls();
    this->createPlots();
}
void CADCCalibration::createControls()
{
    mStartButtonPtr     = new QPushButton("Start Measurement");
    QObject::connect(mStartButtonPtr, SIGNAL(clicked()),
                     this, SLOT(startButtonClickedLSLOT()));
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
void CADCCalibration::startButtonClickedLSLOT()
{
    emit startADCCalibrationSIG();
    mADC1PlotPtr->reset();
    mADC2PlotPtr->reset();
    mADC3PlotPtr->reset();
    mReceivedValues = 0;
}
void CADCCalibration::adcDataReceivedSLOT(double time, const CADCData& data)
{
    QVector<double> data1; data1.append(static_cast<double>(data.mADC1Value));
    QVector<double> data2; data2.append(static_cast<double>(data.mADC2Value));
    QVector<double> data3; data3.append(static_cast<double>(data.mADC3Value));

    mADC1PlotPtr->addData(time, data1);
    mADC2PlotPtr->addData(time, data2);
    mADC3PlotPtr->addData(time, data3);

    mReceivedValues++;
    if(mReceivedValues >= mNumberOfValues)
    {
        emit endMeasurementSIG();
        QVector<std::string> varNames;
        varNames.append("adc");
        mADC1PlotPtr->saveCSV("ADCCalibration/adc1data.csv", varNames);
        mADC2PlotPtr->saveCSV("ADCCalibration/adc2data.csv", varNames);
        mADC3PlotPtr->saveCSV("ADCCalibration/adc3data.csv", varNames);
    }
}
