#include "CSensorCalibWidget.h"
#include <iostream>
#include <ostream>
#include <fstream>
using namespace std;

CSensorCalibWidget::CSensorCalibWidget() : mSavedFlag(false),
                                           mDrawCounter(0)
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
    mStartButtonPtr = new QPushButton("Start Measurement");
    mRightLayoutPtr->addWidget(mStartButtonPtr);
    QObject::connect(mStartButtonPtr, SIGNAL(clicked()),
                     this, SLOT(startClicked()));

    mCentralLayoutPtr->addWidget(mLeftWidgetPtr);
    mCentralLayoutPtr->addWidget(mRightWidgetPtr);

    //Create the Plots
    mXAccelPlotPtr = new QCustomPlot;
    mXAccelPlotPtr->xAxis->setLabel("Time [s]");
    mXAccelPlotPtr->yAxis->setLabel("X-Acceleration []");
    mXAccelPlotPtr->xAxis->setRange(0.0, 40.0);
    mXAccelPlotPtr->yAxis->setRange(-33000.0, 33000);
    mYAccelPlotPtr = new QCustomPlot;
    mYAccelPlotPtr->xAxis->setLabel("Time [s]");
    mYAccelPlotPtr->yAxis->setLabel("Y-Acceleration []");
    mYAccelPlotPtr->xAxis->setRange(0.0, 40.0);
    mYAccelPlotPtr->yAxis->setRange(-33000.0, 33000);
    mZAccelPlotPtr = new QCustomPlot;
    mZAccelPlotPtr->xAxis->setLabel("Time [s]");
    mZAccelPlotPtr->yAxis->setLabel("Z-Acceleration []");
    mZAccelPlotPtr->xAxis->setRange(0.0, 40.0);
    mZAccelPlotPtr->yAxis->setRange(-33000.0, 33000);
    mXAnglVelPlotPtr = new QCustomPlot;
    mXAnglVelPlotPtr->xAxis->setLabel("Time [s]");
    mXAnglVelPlotPtr->yAxis->setLabel("X-Angular-Velocity []");
    mXAnglVelPlotPtr->xAxis->setRange(0.0, 140.0);
    mXAnglVelPlotPtr->yAxis->setRange(-33000.0, 33000);
    mYAnglVelPlotPtr = new QCustomPlot;
    mYAnglVelPlotPtr->xAxis->setLabel("Time [s]");
    mYAnglVelPlotPtr->xAxis->setLabel("Y-Angulvar-Velocity []");
    mYAnglVelPlotPtr->xAxis->setRange(0.0, 140.0);
    mYAnglVelPlotPtr->yAxis->setRange(-33000.0, 33000);
    mZAnglVelPlotPtr = new QCustomPlot;
    mZAnglVelPlotPtr->xAxis->setLabel("Time [s]");
    mZAnglVelPlotPtr->yAxis->setLabel("Z-Angulvar-Velocity []");
    mZAnglVelPlotPtr->xAxis->setRange(0.0, 140.0);
    mZAnglVelPlotPtr->yAxis->setRange(-33000.0, 33000);

    for(int i = 0; i < 6; i++)
    {
        mXAccelPlotPtr->addGraph();
        mYAccelPlotPtr->addGraph();
        mZAccelPlotPtr->addGraph();
        mXAnglVelPlotPtr->addGraph();
        mYAnglVelPlotPtr->addGraph();
        mZAnglVelPlotPtr->addGraph();
    }

    mLeftLayoutPtr->addWidget(mXAccelPlotPtr, 0, 0);
    mLeftLayoutPtr->addWidget(mYAccelPlotPtr, 0, 1);
    mLeftLayoutPtr->addWidget(mZAccelPlotPtr, 0, 2);
    mLeftLayoutPtr->addWidget(mXAnglVelPlotPtr, 1, 0);
    mLeftLayoutPtr->addWidget(mYAnglVelPlotPtr, 1, 1);
    mLeftLayoutPtr->addWidget(mZAnglVelPlotPtr, 1, 2);

}
void CSensorCalibWidget::startClicked()
{
    mSavedFlag = false;
    mDrawCounter = 0;

    mTime1.clear();
    mTime2.clear();
    mTime3.clear();
    mTime4.clear();
    mTime5.clear();
    mTime6.clear();

    mA_X1.clear();
    mA_X2.clear();
    mA_X3.clear();
    mA_X4.clear();
    mA_X5.clear();
    mA_X6.clear();

    mA_Y1.clear();
    mA_Y2.clear();
    mA_Y3.clear();
    mA_Y4.clear();
    mA_Y5.clear();
    mA_Y6.clear();

    mA_Z1.clear();
    mA_Z2.clear();
    mA_Z3.clear();
    mA_Z4.clear();
    mA_Z5.clear();
    mA_Z6.clear();

    mW_X1.clear();
    mW_X2.clear();
    mW_X3.clear();
    mW_X4.clear();
    mW_X5.clear();
    mW_X6.clear();

    mW_Y1.clear();
    mW_Y2.clear();
    mW_Y3.clear();
    mW_Y4.clear();
    mW_Y5.clear();
    mW_Y6.clear();

    mW_Z1.clear();
    mW_Z2.clear();
    mW_Z3.clear();
    mW_Z4.clear();
    mW_Z5.clear();
    mW_Z6.clear();

    emit runSensorMeasurement();
}
void CSensorCalibWidget::sensor1DataReceived(const CMPUData& data)
{
    mTime1.append(static_cast<double>(data.mTime));
    mA_X1.append(static_cast<double>(data.mA_x));
    mA_Y1.append(static_cast<double>(data.mA_y));
    mA_Z1.append(static_cast<double>(data.mA_z));
    mW_X1.append(static_cast<double>(data.mW_x));
    mW_Y1.append(static_cast<double>(data.mW_y));
    mW_Z1.append(static_cast<double>(data.mW_z));
}
void CSensorCalibWidget::sensor2DataReceived(const CMPUData& data)
{
    mTime2.append(static_cast<double>(data.mTime));
    mA_X2.append(static_cast<double>(data.mA_x));
    mA_Y2.append(static_cast<double>(data.mA_y));
    mA_Z2.append(static_cast<double>(data.mA_z));
    mW_X2.append(static_cast<double>(data.mW_x));
    mW_Y2.append(static_cast<double>(data.mW_y));
    mW_Z2.append(static_cast<double>(data.mW_z));
}
void CSensorCalibWidget::sensor3DataReceived(const CMPUData &data)
{
    mTime3.append(static_cast<double>(data.mTime));
    mA_X3.append(static_cast<double>(data.mA_x));
    mA_Y3.append(static_cast<double>(data.mA_y));
    mA_Z3.append(static_cast<double>(data.mA_z));
    mW_X3.append(static_cast<double>(data.mW_x));
    mW_Y3.append(static_cast<double>(data.mW_y));
    mW_Z3.append(static_cast<double>(data.mW_z));
}
void CSensorCalibWidget::sensor4DataReceived(const CMPUData& data)
{
    mTime4.append(static_cast<double>(data.mTime));
    mA_X4.append(static_cast<double>(data.mA_x));
    mA_Y4.append(static_cast<double>(data.mA_y));
    mA_Z4.append(static_cast<double>(data.mA_z));
    mW_X4.append(static_cast<double>(data.mW_x));
    mW_Y4.append(static_cast<double>(data.mW_y));
    mW_Z4.append(static_cast<double>(data.mW_z));
}
void CSensorCalibWidget::sensor5DataReceived(const CMPUData& data)
{
    mTime5.append(static_cast<double>(data.mTime));
    mA_X5.append(static_cast<double>(data.mA_x));
    mA_Y5.append(static_cast<double>(data.mA_y));
    mA_Z5.append(static_cast<double>(data.mA_z));
    mW_X5.append(static_cast<double>(data.mW_x));
    mW_Y5.append(static_cast<double>(data.mW_y));
    mW_Z5.append(static_cast<double>(data.mW_z));
}
void CSensorCalibWidget::sensor6DataReceived(const CMPUData& data)
{
    mTime6.append(static_cast<double>(data.mTime));
    mA_X6.append(static_cast<double>(data.mA_x));
    mA_Y6.append(static_cast<double>(data.mA_y));
    mA_Z6.append(static_cast<double>(data.mA_z));
    mW_X6.append(static_cast<double>(data.mW_x));
    mW_Y6.append(static_cast<double>(data.mW_y));
    mW_Z6.append(static_cast<double>(data.mW_z));

    this->drawPlots();
}
void CSensorCalibWidget::drawPlots()
{
    mDrawCounter++;
    if(mDrawCounter >= 30)
    {
        mDrawCounter = 0;
        mXAccelPlotPtr->graph(0)->setData(mTime1, mA_X1);
        mXAccelPlotPtr->graph(1)->setData(mTime2, mA_X2);
        mXAccelPlotPtr->graph(2)->setData(mTime3, mA_X3);
        mXAccelPlotPtr->graph(3)->setData(mTime4, mA_X4);
        mXAccelPlotPtr->graph(4)->setData(mTime5, mA_X5);
        mXAccelPlotPtr->graph(5)->setData(mTime6, mA_X6);
        mXAccelPlotPtr->replot();

        mYAccelPlotPtr->graph(0)->setData(mTime1, mA_Y1);
        mYAccelPlotPtr->graph(1)->setData(mTime2, mA_Y2);
        mYAccelPlotPtr->graph(2)->setData(mTime3, mA_Y3);
        mYAccelPlotPtr->graph(3)->setData(mTime4, mA_Y4);
        mYAccelPlotPtr->graph(4)->setData(mTime5, mA_Y5);
        mYAccelPlotPtr->graph(5)->setData(mTime6, mA_Y6);
        mYAccelPlotPtr->replot();

        mZAccelPlotPtr->graph(0)->setData(mTime1, mA_Z1);
        mZAccelPlotPtr->graph(1)->setData(mTime2, mA_Z2);
        mZAccelPlotPtr->graph(2)->setData(mTime3, mA_Z3);
        mZAccelPlotPtr->graph(3)->setData(mTime4, mA_Z4);
        mZAccelPlotPtr->graph(4)->setData(mTime5, mA_Z5);
        mZAccelPlotPtr->graph(5)->setData(mTime6, mA_Z6);
        mZAccelPlotPtr->replot();

        mXAnglVelPlotPtr->graph(0)->setData(mTime1, mW_X1);
        mXAnglVelPlotPtr->graph(1)->setData(mTime2, mW_X2);
        mXAnglVelPlotPtr->graph(2)->setData(mTime3, mW_X3);
        mXAnglVelPlotPtr->graph(3)->setData(mTime4, mW_X4);
        mXAnglVelPlotPtr->graph(4)->setData(mTime5, mW_X5);
        mXAnglVelPlotPtr->graph(5)->setData(mTime6, mW_X6);
        mXAnglVelPlotPtr->replot();

        mYAnglVelPlotPtr->graph(0)->setData(mTime1, mW_Y1);
        mYAnglVelPlotPtr->graph(1)->setData(mTime2, mW_Y2);
        mYAnglVelPlotPtr->graph(2)->setData(mTime3, mW_Y3);
        mYAnglVelPlotPtr->graph(3)->setData(mTime4, mW_Y4);
        mYAnglVelPlotPtr->graph(4)->setData(mTime5, mW_Y5);
        mYAnglVelPlotPtr->graph(5)->setData(mTime6, mW_Y6);
        mYAnglVelPlotPtr->replot();

        mZAnglVelPlotPtr->graph(0)->setData(mTime1, mW_Z1);
        mZAnglVelPlotPtr->graph(1)->setData(mTime2, mW_Z2);
        mZAnglVelPlotPtr->graph(2)->setData(mTime3, mW_Z3);
        mZAnglVelPlotPtr->graph(3)->setData(mTime4, mW_Z4);
        mZAnglVelPlotPtr->graph(4)->setData(mTime5, mW_Z5);
        mZAnglVelPlotPtr->graph(5)->setData(mTime6, mW_Z6);
        mZAnglVelPlotPtr->replot();
    }
    if(mTime1.length() > 500)
    {
        this->saveCSV();
        emit endMeasurement();
    }
}
void CSensorCalibWidget::saveCSV()
{
    if(mSavedFlag == false)
    {
        mSavedFlag = true;
        string fileName = "sensor_calib_data.csv";
        ofstream fileStream;
        fileStream.open(fileName);
        fileStream << "t1, a_x1, a_y1, a_z1, w_x1, w_y1, w_z1, "
                   << "t2, a_x2, a_y2, a_z2, w_x2, w_y2, w_z2, "
                   << "t3, a_x3, a_y3, a_z3, w_x3, w_y3, w_z3, "
                   << "t4, a_x4, a_y4, a_z4, w_x4, w_y4, w_z4, "
                   << "t5, a_x5, a_y5, a_z5, w_x5, w_y5, w_z5, "
                   << "t6, a_x6, a_y6, a_z6, w_x6, w_y6, w_z6\n ";

        QVectorIterator<double> time_it[]   = { mTime1, mTime2, mTime3,
                                                mTime4, mTime5, mTime6 };
        QVectorIterator<double> ax_it[]     = { mA_X1, mA_X2, mA_X3,
                                                mA_X4, mA_X5, mA_X6 };
        QVectorIterator<double> ay_it[]     = { mA_Y1, mA_Y2, mA_Y3,
                                                mA_Y4, mA_Y5, mA_Y6 };
        QVectorIterator<double> az_it[]     = { mA_Z1, mA_Z2, mA_Z3,
                                                mA_Z4, mA_Z5, mA_Z6 };
        QVectorIterator<double> wx_it[]     = { mW_X1, mW_X2, mW_X3,
                                                mW_X4, mW_X5, mW_X6 };
        QVectorIterator<double> wy_it[]     = { mW_Y1, mW_Y2, mW_Y3,
                                                mW_Y4, mW_Y5, mW_Y6 };
        QVectorIterator<double> wz_it[]     = { mW_Z1, mW_Z2, mW_Z3,
                                                mW_Z4, mW_Z5, mW_Z6 };

        for(int n = 0; n < mTime1.length(); n++)
        {
            for(int i = 0; i < 6; i++)
            {
                if(time_it[i].hasNext())
                {
                    string tmp = to_string(time_it[i].next());
                    tmp.replace(tmp.find(",", 0), 1, ".");
                    fileStream << tmp << ", ";

                    tmp = to_string(ax_it[i].next());
                    tmp.replace(tmp.find(",", 0), 1, ".");
                    fileStream << tmp << ", ";

                    tmp = to_string(ay_it[i].next());
                    tmp.replace(tmp.find(",", 0), 1, ".");
                    fileStream << tmp << ", ";

                    tmp = to_string(az_it[i].next());
                    tmp.replace(tmp.find(",", 0), 1, ".");
                    fileStream << tmp << ", ";

                    tmp = to_string(wx_it[i].next());
                    tmp.replace(tmp.find(",", 0), 1, ".");
                    fileStream << tmp << ", ";

                    tmp = to_string(wy_it[i].next());
                    tmp.replace(tmp.find(",", 0), 1, ".");
                    fileStream << tmp << ", ";

                    tmp = to_string(wz_it[i].next());
                    tmp.replace(tmp.find(",", 0), 1, ".");
                    fileStream << tmp;

                    if(i == 5)
                    {
                        fileStream << "\n";
                    }
                    else
                    {
                        fileStream << ", ";
                    }
                }
            }
        }

    }
}
