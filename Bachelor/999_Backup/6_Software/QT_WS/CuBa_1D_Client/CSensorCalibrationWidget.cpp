#include "CSensorCalibrationWidget.h"

CSensorCalibrationWidget::CSensorCalibrationWidget()
{
    mLayoutPtr      = new QHBoxLayout(this);
    mRightWidgetPtr = new QWidget(this);
    mLeftWidgetPtr  = new QWidget(this);

    QSizePolicy leftSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    leftSizePolicy.setHorizontalStretch(4);
    mLeftWidgetPtr->setSizePolicy(leftSizePolicy);

    QSizePolicy rightSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    rightSizePolicy.setHorizontalStretch(1);
    mRightWidgetPtr->setSizePolicy(rightSizePolicy);

    mLayoutPtr->addWidget(mLeftWidgetPtr);
    mLayoutPtr->addWidget(mRightWidgetPtr);

    mSensorPlotGridPtr = new CSensorPlotGrid();
    mLeftWidgetPtr->setLayout(mSensorPlotGridPtr);

    mRightLayoutPtr = new QVBoxLayout();
    mRightWidgetPtr->setLayout(mRightLayoutPtr);

    mDatapointsInputLayoutPtr   = new QHBoxLayout;
    mDatapointsLabelPtr         = new QLabel("Number of Datapoints:");
    mDatapointsInputPtr         = new QSpinBox();
    mDatapointsInputPtr->setMinimum(5);
    mDatapointsInputPtr->setMaximum(100000);
    mDatapointsInputPtr->setSingleStep(1);
    mDatapointsInputPtr->setValue(4096);
    mDatapointsInputLayoutPtr->addWidget(mDatapointsLabelPtr);
    mDatapointsInputLayoutPtr->addWidget(mDatapointsInputPtr);
    mRightLayoutPtr->addLayout(mDatapointsInputLayoutPtr);

    mPhiInputLayoutPtr      = new QHBoxLayout;
    mPhiLabelPtr            = new QLabel("Phi [deg]:");
    mPhiInputPtr            = new QSpinBox();
    mPhiInputPtr->setMinimum(-45);
    mPhiInputPtr->setMaximum(45);
    mPhiInputPtr->setSingleStep(1);
    mPhiInputPtr->setValue(0);
    mPhiInputLayoutPtr->addWidget(mPhiLabelPtr);
    mPhiInputLayoutPtr->addWidget(mPhiInputPtr);
    mRightLayoutPtr->addLayout(mPhiInputLayoutPtr);

    mStartButtonPtr = new QPushButton("Start Measurement");
    mRightLayoutPtr->addWidget(mStartButtonPtr);
    mRightLayoutPtr->addStretch();

    QObject::connect(mDatapointsInputPtr, SIGNAL(valueChanged(int)),
                     mSensorPlotGridPtr, SLOT(setNumberOfDatapoints(int)));
    QObject::connect(mPhiInputPtr, SIGNAL(valueChanged(int)),
                     mSensorPlotGridPtr, SLOT(setPhiValue(int)));
    QObject::connect(mStartButtonPtr, SIGNAL(clicked()),
                     this, SLOT(startMeasurementClicked()));
    QObject::connect(mSensorPlotGridPtr, SIGNAL(measurementFinished()),
                     this, SLOT(measurementFinished()));
}
void CSensorCalibrationWidget::measurementFinished()
{
    emit endMeasurement();
    mStartButtonPtr->setEnabled(true);
    mPhiInputPtr->setEnabled(true);
    mDatapointsInputPtr->setEnabled(true);
}
void CSensorCalibrationWidget::startMeasurementClicked()
{
    mSensorPlotGridPtr->resetData();
    emit startMeasurement();
    mStartButtonPtr->setEnabled(false);
    mPhiInputPtr->setEnabled(false);
    mDatapointsInputPtr->setEnabled(false);
}
void CSensorCalibrationWidget::sensorDataReceived(const CSensorData &data)
{
    mSensorPlotGridPtr->sensorDataReceived(data);
}
