#include "CSensorCalibration.h"
#include <cstdlib>
#include <string>

CSensorCalibration::CSensorCalibration() : mNumberOfValues(500), mReceivedValues(0)
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
    QObject::connect(mStartButtonPtr, SIGNAL(clicked()),
                     this, SLOT(startButtonClickedSLOT()));
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

    mPhiLayoutPtr       = new QHBoxLayout;
    mPhiLabelPtr        = new QLabel("Phi-Index");
    mPhiSpinBoxPtr      = new QSpinBox;
    mPhiSpinBoxPtr->setMaximum(3);
    mPhiSpinBoxPtr->setMinimum(1);
    mPhiSpinBoxPtr->setValue(1);
    mPhiLayoutPtr->addWidget(mPhiLabelPtr);
    mPhiLayoutPtr->addWidget(mPhiSpinBoxPtr);
    mControlLayoutPtr->addLayout(mPhiLayoutPtr);

    mDegLayoutPtr       = new QHBoxLayout;
    mDegLabelPtr        = new QLabel("Angle");
    mDegSpinBoxPtr      = new QSpinBox;
    mDegSpinBoxPtr->setMaximum(90);
    mDegSpinBoxPtr->setMinimum(-90);
    mDegSpinBoxPtr->setValue(0);
    mDegSpinBoxPtr->setSingleStep(15);
    mDegLayoutPtr->addWidget(mDegLabelPtr);
    mDegLayoutPtr->addWidget(mDegSpinBoxPtr);
    mControlLayoutPtr->addLayout(mDegLayoutPtr);

    mControlLayoutPtr->addStretch();

    QObject::connect(mValuesSpinBoxPtr, SIGNAL(valueChanged(int)),
                     this, SLOT(numberOfValuesChangedSLOT(int)));
}
void CSensorCalibration::sensor1DataReceivedSLOT(double time, const CMPUData& data)
{
    QVector<double> dataVector;
    dataVector.append(static_cast<double>(data.mA_x));
    dataVector.append(static_cast<double>(data.mA_y));
    dataVector.append(static_cast<double>(data.mA_z));
    dataVector.append(static_cast<double>(data.mW_x));
    dataVector.append(static_cast<double>(data.mW_y));
    dataVector.append(static_cast<double>(data.mW_z));
    mSensor1PlotPtr->addData(time, dataVector);

    mReceivedValues++;
    if(mReceivedValues >= mNumberOfValues)
    {
        emit endMeasurementSIG();
        QVector<std::string> varNames;
        varNames.append("a_x"); varNames.append("a_y"); varNames.append("a_z");
        varNames.append("w_x"); varNames.append("w_y"); varNames.append("w_z");
        std::string appendix = "_phi" + std::to_string(mPhiSpinBoxPtr->value()) + "_" + std::to_string(mDegSpinBoxPtr->value()) + ".csv";
        //QString appendix = "_phi" + QString(std::to_string(mPhiSpinBoxPtr->value())) + "_" + QString(std::to_string(mDegSpinBoxPtr->value())) + ".csv";
        mSensor1PlotPtr->saveCSV( "SensorCalibration/s1" + appendix, varNames);
        mSensor2PlotPtr->saveCSV( "SensorCalibration/s2" + appendix, varNames);
        mSensor3PlotPtr->saveCSV( "SensorCalibration/s3" + appendix, varNames);
        mSensor4PlotPtr->saveCSV( "SensorCalibration/s4" + appendix, varNames);
        mSensor5PlotPtr->saveCSV( "SensorCalibration/s5" + appendix, varNames);
        mSensor6PlotPtr->saveCSV( "SensorCalibration/s6" + appendix, varNames);
    }
}
void CSensorCalibration::sensor2DataReceivedSLOT(double time, const CMPUData& data)
{
    QVector<double> dataVector;
    dataVector.append(static_cast<double>(data.mA_x));
    dataVector.append(static_cast<double>(data.mA_y));
    dataVector.append(static_cast<double>(data.mA_z));
    dataVector.append(static_cast<double>(data.mW_x));
    dataVector.append(static_cast<double>(data.mW_y));
    dataVector.append(static_cast<double>(data.mW_z));
    mSensor2PlotPtr->addData(time, dataVector);
}
void CSensorCalibration::sensor3DataReceivedSLOT(double time, const CMPUData& data)
{
    QVector<double> dataVector;
    dataVector.append(static_cast<double>(data.mA_x));
    dataVector.append(static_cast<double>(data.mA_y));
    dataVector.append(static_cast<double>(data.mA_z));
    dataVector.append(static_cast<double>(data.mW_x));
    dataVector.append(static_cast<double>(data.mW_y));
    dataVector.append(static_cast<double>(data.mW_z));
    mSensor3PlotPtr->addData(time, dataVector);
}
void CSensorCalibration::sensor4DataReceivedSLOT(double time, const CMPUData& data)
{
    QVector<double> dataVector;
    dataVector.append(static_cast<double>(data.mA_x));
    dataVector.append(static_cast<double>(data.mA_y));
    dataVector.append(static_cast<double>(data.mA_z));
    dataVector.append(static_cast<double>(data.mW_x));
    dataVector.append(static_cast<double>(data.mW_y));
    dataVector.append(static_cast<double>(data.mW_z));
    mSensor4PlotPtr->addData(time, dataVector);
}
void CSensorCalibration::sensor5DataReceivedSLOT(double time, const CMPUData& data)
{
    QVector<double> dataVector;
    dataVector.append(static_cast<double>(data.mA_x));
    dataVector.append(static_cast<double>(data.mA_y));
    dataVector.append(static_cast<double>(data.mA_z));
    dataVector.append(static_cast<double>(data.mW_x));
    dataVector.append(static_cast<double>(data.mW_y));
    dataVector.append(static_cast<double>(data.mW_z));
    mSensor5PlotPtr->addData(time, dataVector);
}
void CSensorCalibration::sensor6DataReceivedSLOT(double time, const CMPUData& data)
{
    QVector<double> dataVector;
    dataVector.append(static_cast<double>(data.mA_x));
    dataVector.append(static_cast<double>(data.mA_y));
    dataVector.append(static_cast<double>(data.mA_z));
    dataVector.append(static_cast<double>(data.mW_x));
    dataVector.append(static_cast<double>(data.mW_y));
    dataVector.append(static_cast<double>(data.mW_z));
    mSensor6PlotPtr->addData(time, dataVector);
}
void CSensorCalibration::startButtonClickedSLOT()
{
    mReceivedValues = 0;
    mSensor1PlotPtr->reset();
    mSensor2PlotPtr->reset();
    mSensor3PlotPtr->reset();
    mSensor4PlotPtr->reset();
    mSensor5PlotPtr->reset();
    mSensor6PlotPtr->reset();
    emit startSensorCalibrationSIG();
}
void CSensorCalibration::numberOfValuesChangedSLOT(int newValue)
{
    mNumberOfValues = newValue;
}
