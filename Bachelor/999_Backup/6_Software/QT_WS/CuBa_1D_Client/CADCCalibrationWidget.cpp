#include "CADCCalibrationWidget.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

CADCCalibrationWidget::CADCCalibrationWidget() : mNbrOfDatapoints(4096),
                                                 mRPM(0),
                                                 mSaveFlag(false)
{
    mCentralLayoutPtr = new QHBoxLayout;
    this->setLayout(mCentralLayoutPtr);

    mLeftWidgetPtr = new QWidget;
    QSizePolicy leftSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    leftSizePolicy.setHorizontalStretch(4);
    mLeftWidgetPtr->setSizePolicy(leftSizePolicy);

    mLeftLayoutPtr = new QGridLayout;
    mLeftWidgetPtr->setLayout(mLeftLayoutPtr);
    mADCPlotPtr    = new QCustomPlot;
    mADCPlotPtr->addGraph();
    mADCPlotPtr->xAxis->setLabel("Time [s]");
    mADCPlotPtr->yAxis->setLabel("ADC-Value []");
    mADCPlotPtr->graph(0)->setData(mTime, mADCValue);

    mCentralLayoutPtr->addWidget(mLeftWidgetPtr);
    mLeftLayoutPtr->addWidget(mADCPlotPtr, 0, 0);

    mRightWidgetPtr = new QWidget;
    QSizePolicy rightSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    rightSizePolicy.setHorizontalStretch(1);
    mRightWidgetPtr->setSizePolicy(rightSizePolicy);

    mRightLayoutPtr = new QVBoxLayout;
    mRightWidgetPtr->setLayout(mRightLayoutPtr);

    mDatapointsLayoutPtr = new QHBoxLayout;
    mDatapointsLabelPtr  = new QLabel("Number of Datapoints:");
    mDatapointsInputPtr  = new QSpinBox;
    mDatapointsInputPtr->setMinimum(5);
    mDatapointsInputPtr->setMaximum(100000);
    mDatapointsInputPtr->setSingleStep(1);
    mDatapointsInputPtr->setValue(4096);
    mDatapointsLayoutPtr->addWidget(mDatapointsLabelPtr);
    mDatapointsLayoutPtr->addWidget(mDatapointsInputPtr);
    mRightLayoutPtr->addLayout(mDatapointsLayoutPtr);

    mRPMInputLayoutPtr = new QHBoxLayout;
    mRPMLabelPtr       = new QLabel("RPM:");
    mRPMInputPtr       = new QSpinBox;
    mRPMInputPtr->setMinimum(-10000);
    mRPMInputPtr->setMaximum(10000);
    mRPMInputPtr->setValue(0);
    mRPMInputPtr->setSingleStep(1);
    mRPMInputLayoutPtr->addWidget(mRPMLabelPtr);
    mRPMInputLayoutPtr->addWidget(mRPMInputPtr);
    mRightLayoutPtr->addLayout(mRPMInputLayoutPtr);

    mStartButtonPtr = new QPushButton("Start Measurement");
    mRightLayoutPtr->addWidget(mStartButtonPtr);
    mRightLayoutPtr->addStretch();

    mCentralLayoutPtr->addWidget(mRightWidgetPtr);

    QObject::connect(mStartButtonPtr, SIGNAL(clicked()),
                     this, SLOT(startClicked()));
    QObject::connect(mDatapointsInputPtr, SIGNAL(valueChanged(int)),
                     this, SLOT(setDatapoints(int)));
    QObject::connect(mRPMInputPtr, SIGNAL(valueChanged(int)),
                     this, SLOT(setRPM(int)));
}
void CADCCalibrationWidget::adcDataReceived(const CSensorData &data)
{
    if(mTime.length() >= mNbrOfDatapoints)
    {
        mStartButtonPtr->setEnabled(true);
        mDatapointsInputPtr->setEnabled(true);
        mRPMInputPtr->setEnabled(true);
        if(mSaveFlag == false)
        {
            mSaveFlag = true;
            this->saveCSV();
        }
        emit endMeasurement();
    }
    else
    {
        mTime.append(static_cast<double>(data.mTime));
        mADCValue.append(static_cast<double>(data.mPsi__d));

        mADCPlotPtr->graph(0)->setData(mTime, mADCValue);
        mADCPlotPtr->xAxis->setRange(0.0, *std::max_element(mTime.begin(), mTime.end()));
        mADCPlotPtr->yAxis->setRange(*std::min_element(mADCValue.begin(), mADCValue.end()) - 5.0,
                                     *std::max_element(mADCValue.begin(), mADCValue.end()) + 5.0);
        mADCPlotPtr->replot();

    }
}
void CADCCalibrationWidget::setDatapoints(int newValue)
{
    mNbrOfDatapoints = newValue;
}
void CADCCalibrationWidget::setRPM(int newValue)
{
    mRPM = newValue;
}
void CADCCalibrationWidget::startClicked()
{
    mTime.clear();
    mADCValue.clear();
    mSaveFlag = false;

    mStartButtonPtr->setEnabled(false);
    mDatapointsInputPtr->setEnabled(false);
    mRPMInputPtr->setEnabled(false);
    emit runADCMeasurement();
    emit setRPM(static_cast<float>(mRPM)/140000.0F);
}
void CADCCalibrationWidget::saveCSV()
{
    string fileName = "adcdata_" + to_string(mRPM) + ".csv";
    ofstream fileStream;
    fileStream.open(fileName);
    fileStream << "time, adcValue\n";

    auto timeIt = mTime.begin();
    auto adcIt  = mADCValue.begin();

    for(int n = 0; n < mTime.length(); n++)
    {
        string tmp = to_string(*timeIt);
        tmp.replace(tmp.find(",", 0), 1, ".");
        fileStream << tmp << ", ";

        tmp = to_string(*adcIt);
        tmp.replace(tmp.find(",", 0), 1, ".");
        fileStream << tmp << "\n";

        timeIt++;
        adcIt++;
    }

    fileStream.close();
}
