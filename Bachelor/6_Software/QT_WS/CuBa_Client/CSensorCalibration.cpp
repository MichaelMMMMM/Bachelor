#include "CSensorCalibration.h"

CSensorCalibration::CSensorCalibration() : mNumberOfValues(500)
{
    this->createPlots();
    this->createControls();
}
void CSensorCalibration::createPlots()
{
    QVector<QString> legend;
    legend.append("A_x"); legend.append("A_y"); legend.append("A_z");
    legend.append("W_x"); legend.append("W_y"); legend.append("W_z");
    QVector<QPen> lineColors;
    lineColors.append(QPen(Qt::blue)); lineColors.append(QPen(Qt::red)); lineColors.append(QPen(Qt::green));
    lineColors.append(QPen(Qt::blue)); lineColors.append(QPen(Qt::red)); lineColors.append(QPen(Qt::green));
    mSensor1PlotPtr = new CPlot(6, "Measurements in 2K", "Sensor 1", legend, lineColors);
    mSensor2PlotPtr = new CPlot(6, "Measurements in 2K", "Sensor 2", legend, lineColors);
    mSensor3PlotPtr = new CPlot(6, "Measurements in 2K", "Sensor 3", legend, lineColors);
    mSensor4PlotPtr = new CPlot(6, "Measurements in 2K", "Sensor 4", legend, lineColors);
    mSensor5PlotPtr = new CPlot(6, "Measurements in 2K", "Sensor 5", legend, lineColors);
    mSensor6PlotPtr = new CPlot(6, "Measurements in 2K", "Sensor 6", legend, lineColors);

    mPlotLayoutPtr->addWidget(mSensor1PlotPtr->getPlotPtr(), 0, 0);
    mPlotLayoutPtr->addWidget(mSensor2PlotPtr->getPlotPtr(), 0, 1);
    mPlotLayoutPtr->addWidget(mSensor3PlotPtr->getPlotPtr(), 0, 2);
    mPlotLayoutPtr->addWidget(mSensor4PlotPtr->getPlotPtr(), 1, 0);
    mPlotLayoutPtr->addWidget(mSensor5PlotPtr->getPlotPtr(), 1, 1);
    mPlotLayoutPtr->addWidget(mSensor6PlotPtr->getPlotPtr(), 1, 2);
}
void CSensorCalibration::createControls()
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
void CSensorCalibration::sensor1DataReceivedSLOT()
{

}
void CSensorCalibration::sensor2DataReceivedSLOT()
{

}
void CSensorCalibration::sensor3DataReceivedSLOT()
{

}
void CSensorCalibration::sensor4DataReceivedSLOT()
{

}
void CSensorCalibration::sensor5DataReceivedSLOT()
{

}
void CSensorCalibration::sensor6DataReceivedSLOT()
{

}
void CSensorCalibration::startButtonClickedSLOT()
{

}
void CSensorCalibration::numberOfValuesChangedSLOT(int newValue)
{
    mNumberOfValues = newValue;
}
