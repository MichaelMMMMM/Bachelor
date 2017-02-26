#include "CSensorPlotGrid.h"
#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

CSensorPlotGrid::CSensorPlotGrid() : mNumberOfDatapoints(4096),
                                     mPhi(0),
                                     mPlotCounter(0),
                                     mSaveFlag(false)
{
    mX1PlotPtr      = new QCustomPlot();
    mX2PlotPtr      = new QCustomPlot();
    mY1PlotPtr      = new QCustomPlot();
    mY2PlotPtr      = new QCustomPlot();
    mPhi1PlotPtr    = new QCustomPlot();
    mPhi2PlotPtr    = new QCustomPlot();

    this->addWidget(mX1PlotPtr, 0, 0);
    this->addWidget(mX2PlotPtr, 1, 0);
    this->addWidget(mY1PlotPtr, 0, 1);
    this->addWidget(mY2PlotPtr, 1, 1);
    this->addWidget(mPhi1PlotPtr, 0, 2);
    this->addWidget(mPhi2PlotPtr, 1, 2);

    mX1PlotPtr->addGraph();
    mX2PlotPtr->addGraph();
    mY1PlotPtr->addGraph();
    mY2PlotPtr->addGraph();
    mPhi1PlotPtr->addGraph();
    mPhi2PlotPtr->addGraph();

    mX1PlotPtr->xAxis->setLabel("Time [s]");
    mX1PlotPtr->yAxis->setLabel("X1-Acceleration []");
    mX2PlotPtr->xAxis->setLabel("Time [s]");
    mX2PlotPtr->yAxis->setLabel("X2-Acceleration []");
    mY1PlotPtr->xAxis->setLabel("Time [s]");
    mY1PlotPtr->yAxis->setLabel("Y1-Acceleration []");
    mY2PlotPtr->xAxis->setLabel("Time  [s]");
    mY2PlotPtr->yAxis->setLabel("Y2-Acceleration []");
    mPhi1PlotPtr->xAxis->setLabel("Time [s]");
    mPhi1PlotPtr->yAxis->setLabel("Z1-Angular-Velocity []");
    mPhi2PlotPtr->xAxis->setLabel("Time [s]");
    mPhi2PlotPtr->yAxis->setLabel("Z2-Angular-Velocity []");

    mX1PlotPtr->graph(0)->setData(mTime, mX1__dd);
    mX2PlotPtr->graph(0)->setData(mTime, mX2__dd);
    mY1PlotPtr->graph(0)->setData(mTime, mY1__dd);
    mY2PlotPtr->graph(0)->setData(mTime, mY2__dd);
    mPhi1PlotPtr->graph(0)->setData(mTime, mPhi1__d);
    mPhi2PlotPtr->graph(0)->setData(mTime, mPhi2__d);

    mX1PlotPtr->replot();
    mX2PlotPtr->replot();
    mY1PlotPtr->replot();
    mY2PlotPtr->replot();
    mPhi1PlotPtr->replot();
    mPhi2PlotPtr->replot();
}
void CSensorPlotGrid::setNumberOfDatapoints(int newValue)
{
    mNumberOfDatapoints = newValue;
}
void CSensorPlotGrid::setPhiValue(int newValue)
{
    mPhi = newValue;
}
void CSensorPlotGrid::sensorDataReceived(const CSensorData &data)
{
    if(mTime.length() >= mNumberOfDatapoints)
    {
        if(mSaveFlag == false)
        {
            mSaveFlag = true;
            this->saveCSV();
        }
        emit measurementFinished();
    }
    else
    {
        mTime.append(static_cast<double>(data.mTime));
        mX1__dd.append(static_cast<double>(data.mX1__dd));
        mX2__dd.append(static_cast<double>(data.mX2__dd));
        mY1__dd.append(static_cast<double>(data.mY1__dd));
        mY2__dd.append(static_cast<double>(data.mY2__dd));
        mPhi1__d.append(static_cast<double>(data.mPhi1__d));
        mPhi2__d.append(static_cast<double>(data.mPhi2__d));

        mX1PlotPtr->graph(0)->setData(mTime, mX1__dd);
        mX2PlotPtr->graph(0)->setData(mTime, mX2__dd);
        mY1PlotPtr->graph(0)->setData(mTime, mY1__dd);
        mY2PlotPtr->graph(0)->setData(mTime, mY2__dd);
        mPhi1PlotPtr->graph(0)->setData(mTime, mPhi1__d);
        mPhi2PlotPtr->graph(0)->setData(mTime, mPhi2__d);

        double time_max = *std::max_element(mTime.begin(), mTime.end());

        mX1PlotPtr->xAxis->setRange(0.0, time_max);
        mX1PlotPtr->yAxis->setRange(*std::min_element(mX1__dd.begin(), mX1__dd.end()) - 5.0,
                                    *std::max_element(mX1__dd.begin(), mX1__dd.end()) + 5.0);
        mX2PlotPtr->xAxis->setRange(0.0, time_max);
        mX2PlotPtr->yAxis->setRange(*std::min_element(mX2__dd.begin(), mX2__dd.end()) - 5.0,
                                    *std::max_element(mX2__dd.begin(), mX2__dd.end()) + 5.0);
        mY1PlotPtr->xAxis->setRange(0.0, time_max);
        mY1PlotPtr->yAxis->setRange(*std::min_element(mY1__dd.begin(), mY1__dd.end()) - 5.0,
                                    *std::max_element(mY1__dd.begin(), mY1__dd.end()) + 5.0);
        mY2PlotPtr->xAxis->setRange(0.0, time_max);
        mY2PlotPtr->yAxis->setRange(*std::min_element(mY2__dd.begin(), mY2__dd.end()) - 5.0,
                                    *std::max_element(mY2__dd.begin(), mY2__dd.end()) + 5.0);
        mPhi1PlotPtr->xAxis->setRange(0.0, time_max);
        mPhi1PlotPtr->yAxis->setRange(*std::min_element(mPhi1__d.begin(), mPhi1__d.end()) - 5.0,
                                      *std::max_element(mPhi1__d.begin(), mPhi1__d.end()) + 5.0);
        mPhi2PlotPtr->xAxis->setRange(0.0, time_max);
        mPhi2PlotPtr->yAxis->setRange(*std::min_element(mPhi2__d.begin(), mPhi2__d.end()) - 5.0,
                                      *std::max_element(mPhi2__d.begin(), mPhi2__d.end()) + 5.0);

        mPlotCounter++;
        if(mPlotCounter >= 5)
        {
            mPlotCounter = 0;
            mX1PlotPtr->replot();
            mX2PlotPtr->replot();
            mY1PlotPtr->replot();
            mY2PlotPtr->replot();
            mPhi1PlotPtr->replot();
            mPhi2PlotPtr->replot();
        }
    }
}
void CSensorPlotGrid::resetData()
{
    mTime.clear();
    mX1__dd.clear();
    mX2__dd.clear();
    mY1__dd.clear();
    mY2__dd.clear();
    mPhi1__d.clear();
    mPhi2__d.clear();
    mSaveFlag = false;
}
void CSensorPlotGrid::saveCSV()
{
    string fileName = "sensordata_" + std::to_string(mPhi) + ".csv";
    ofstream fileStream;
    fileStream.open(fileName);
    fileStream << "time, x1__dd, x2__dd, y1__dd, y2__dd, phi1__d, phi2__d\n";

    auto timeIt = mTime.begin();
    auto x1It   = mX1__dd.begin();
    auto x2It   = mX2__dd.begin();
    auto y1It   = mY1__dd.begin();
    auto y2It   = mY2__dd.begin();
    auto phi1It = mPhi1__d.begin();
    auto phi2It = mPhi2__d.begin();

    string tmp;
    for(int n = 0; n < mTime.length(); n++)
    {
        tmp = to_string(*timeIt);
        tmp.replace(tmp.find(",", 0), 1,  ".");
        fileStream << tmp << ", ";

        tmp = to_string(*x1It);
        tmp.replace(tmp.find(",", 0), 1, ".");
        fileStream << tmp << ", ";

        tmp = to_string(*x2It);
        tmp.replace(tmp.find(",", 0), 1, ".");
        fileStream << tmp << ", ";

        tmp = to_string(*y1It);
        tmp.replace(tmp.find(",", 0), 1, ".");
        fileStream << tmp << ", ";

        tmp = to_string(*y2It);
        tmp.replace(tmp.find(",", 0), 1, ".");
        fileStream << tmp << ", ";

        tmp = to_string(*phi1It);
        tmp.replace(tmp.find(",", 0), 1, ".");
        fileStream << tmp << ", ";

        tmp = to_string(*phi2It);
        tmp.replace(tmp.find(",", 0), 1, ".");
        fileStream << tmp << "\n";

        timeIt++;
        x1It++;
        x2It++;
        y1It++;
        y2It++;
        phi1It++;
        phi2It++;
    }

    fileStream.close();
}
