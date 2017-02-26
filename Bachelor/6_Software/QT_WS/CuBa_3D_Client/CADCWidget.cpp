#include "CADCWidget.h"
#include <iostream>
#include <ostream>
#include <fstream>
using namespace std;

CADCCalibWidget::CADCCalibWidget() :
     mDrawCounter(0), mSavedFlag(false)
{
    //Setup of the central layouts
    mCentralLayoutPtr = new QHBoxLayout;
    this->setLayout(mCentralLayoutPtr);
    //Setup the left Widget and Layout
    mLeftWidgetPtr = new QWidget;
    QSizePolicy leftSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    leftSizePolicy.setHorizontalStretch(4);
    mLeftWidgetPtr->setSizePolicy(leftSizePolicy);
    mLeftLayoutPtr = new QGridLayout;
    mLeftWidgetPtr->setLayout(mLeftLayoutPtr);
    //Setup the right Widget and Layout
    mRightWidgetPtr = new QWidget;
    QSizePolicy rightSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    rightSizePolicy.setHorizontalStretch(1);
    mRightWidgetPtr->setSizePolicy(rightSizePolicy);
    mRightLayoutPtr = new QVBoxLayout;
    mRightWidgetPtr->setLayout(mRightLayoutPtr);

    mCentralLayoutPtr->addWidget(mLeftWidgetPtr);
    mCentralLayoutPtr->addWidget(mRightWidgetPtr);

    //Create the controls
    mTorqueInputLayoutPtr = new QHBoxLayout;
    mTorqueInputLabelPtr  = new QLabel("Torque");
    mTorqueInputPtr       = new QDoubleSpinBox;
    mTorqueInputPtr->setMinimum(-0.130);
    mTorqueInputPtr->setMaximum(0.130);
    mTorqueInputPtr->setSingleStep(0.001);
    mTorqueInputPtr->setValue(0.0);
    mTorqueInputLayoutPtr->addWidget(mTorqueInputLabelPtr);
    mTorqueInputLayoutPtr->addWidget(mTorqueInputPtr);
    mRightLayoutPtr->addLayout(mTorqueInputLayoutPtr);

    mStartButtonPtr = new QPushButton("Start Measurement");
    QObject::connect(mStartButtonPtr, SIGNAL(clicked()),
                     this, SLOT(startClicked()));
    mRightLayoutPtr->addWidget(mStartButtonPtr);
    mRightLayoutPtr->addStretch();

    //Create the plots
    mADC1PlotPtr = new QCustomPlot;
    mADC1PlotPtr->addGraph();
    mADC1PlotPtr->xAxis->setLabel("Time [s]");
    mADC1PlotPtr->yAxis->setLabel("ADC1-Value []");
    mADC1PlotPtr->xAxis->setRange(0.0, 40.0);
    mADC1PlotPtr->yAxis->setRange(-10.0, 4200.0);
    mADC2PlotPtr = new QCustomPlot;
    mADC2PlotPtr->addGraph();
    mADC2PlotPtr->xAxis->setLabel("Time [s]");
    mADC2PlotPtr->yAxis->setLabel("ADC2-Value []");
    mADC2PlotPtr->xAxis->setRange(0.0, 40.0);
    mADC2PlotPtr->yAxis->setRange(-10.0, 4200.0);
    mADC3PlotPtr = new QCustomPlot;
    mADC3PlotPtr->addGraph();
    mADC3PlotPtr->xAxis->setLabel("Time [s]");
    mADC3PlotPtr->yAxis->setLabel("ADC3-Value []");
    mADC3PlotPtr->xAxis->setRange(0.0, 40.0);
    mADC3PlotPtr->yAxis->setRange(-10.0, 4200.0);

    mLeftLayoutPtr->addWidget(mADC1PlotPtr, 0, 0);
    mLeftLayoutPtr->addWidget(mADC2PlotPtr, 0, 1);
    mLeftLayoutPtr->addWidget(mADC3PlotPtr, 1, 0);
}
void CADCCalibWidget::startClicked()
{
    mDrawCounter = 0;
    mSavedFlag   = false;
    mADC1Value.clear();
    mADC2Value.clear();
    mADC3Value.clear();
    mTime.clear();

    static CTorqueData torque;
    torque.mTorque1 = static_cast<Float32>(mTorqueInputPtr->value());
    torque.mTorque2 = torque.mTorque1;
    torque.mTorque3 = torque.mTorque1;

    emit startADCCalib();
    emit setTorque(torque);
}
void CADCCalibWidget::onADCDataReceived(const CADCData& data)
{
    mTime.append(static_cast<double>(data.mTime));
    mADC1Value.append(static_cast<double>(data.mADC1Value));
    mADC2Value.append(static_cast<double>(data.mADC2Value));
    mADC3Value.append(static_cast<double>(data.mADC3Value));

    mDrawCounter++;
    if(mDrawCounter > 10)
    {
        mDrawCounter = 0;
        mADC1PlotPtr->graph(0)->setData(mTime, mADC1Value);
        mADC2PlotPtr->graph(0)->setData(mTime, mADC2Value);
        mADC3PlotPtr->graph(0)->setData(mTime, mADC3Value);

        mADC1PlotPtr->replot();
        mADC2PlotPtr->replot();
        mADC3PlotPtr->replot();
    }

    if(mTime.length() > 1500)
    {
        this->saveCSV();
        emit endADCCalib();
    }
}
void CADCCalibWidget::saveCSV()
{
    if(mSavedFlag == false)
    {
        mSavedFlag = true;

        string fileName = "adcdata.csv";
        ofstream fileStream;
        fileStream.open(fileName);
        fileStream << "t, adc1, adc2, adc3\n";

        auto time_it = mTime.begin();
        auto adc1_it = mADC1Value.begin();
        auto adc2_it = mADC2Value.begin();
        auto adc3_it = mADC3Value.begin();

        for(int n = 0; n < mTime.length(); n++)
        {
            string tmp = to_string(*time_it);
            tmp.replace(tmp.find(",", 0), 1, ".");
            fileStream << tmp << ", ";

            tmp = to_string(*adc1_it);
            tmp.replace(tmp.find(",", 0), 1, ".");
            fileStream << tmp << ", ";

            tmp = to_string(*adc2_it);
            tmp.replace(tmp.find(",", 0), 1, ".");
            fileStream << tmp << ", ";

            tmp = to_string(*adc3_it);
            tmp.replace(tmp.find(",", 0), 1, ".");
            fileStream << tmp << "\n";

            time_it++;
            adc1_it++;
            adc2_it++;
            adc3_it++;
        }
    }
}
