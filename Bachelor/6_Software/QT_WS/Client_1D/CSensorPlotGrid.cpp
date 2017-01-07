#include "CSensorPlotGrid.h"

CSensorPlotGrid::CSensorPlotGrid(QWidget *parent) : QGridLayout(parent)
{
    mX1Plot         = new QCustomPlot();
    mX2Plot         = new QCustomPlot();
    mY1Plot         = new QCustomPlot();
    mY2Plot         = new QCustomPlot();
    mPhi1Plot       = new QCustomPlot();
    mPhi2Plot       = new QCustomPlot();

    mX1Plot->addGraph();
    mX1Plot->graph(0)->setData(mTime, mX1__dd);
    mX1Plot->xAxis->setLabel("Time [s]");
    mX1Plot->yAxis->setLabel("X1_dd []");
    mX1Plot->replot();

    mX2Plot->addGraph();
    mX2Plot->graph(0)->setData(mTime, mX2__dd);
    mX2Plot->xAxis->setLabel("Time [s]");
    mX2Plot->yAxis->setLabel("X2__dd []");
    mX2Plot->replot();

    mY1Plot->addGraph();
    mY1Plot->graph(0)->setData(mTime, mY1__dd);
    mY1Plot->xAxis->setLabel("Time [s]");
    mY1Plot->yAxis->setLabel("Y1__dd []");
    mY1Plot->replot();

    mY2Plot->addGraph();
    mY2Plot->graph(0)->setData(mTime, mY2__dd);
    mY2Plot->xAxis->setLabel("Time [s]");
    mY2Plot->yAxis->setLabel("Y2__dd []");
    mY2Plot->replot();

    mPhi1Plot->addGraph();
    mPhi1Plot->graph(0)->setData(mTime, mPhi1__d);
    mPhi1Plot->xAxis->setLabel("Time [s]");
    mPhi1Plot->yAxis->setLabel("Phi1__d []");
    mPhi1Plot->replot();

    mPhi2Plot->addGraph();
    mPhi2Plot->graph(0)->setData(mTime, mPhi2__d);
    mPhi2Plot->xAxis->setLabel("Time [s]");
    mPhi2Plot->yAxis->setLabel("Phi2__d []");
    mPhi2Plot->replot();

    this->addWidget(mX1Plot, 0, 0);
    this->addWidget(mX2Plot, 1, 0);
    this->addWidget(mY1Plot, 0, 1);
    this->addWidget(mY2Plot, 1, 1);
    this->addWidget(mPhi1Plot, 0, 2);
    this->addWidget(mPhi2Plot, 1, 2);
}
void CSensorPlotGrid::onSensorDataReceived(CSensorData data)
{
    this->addSensorData(data);
}

void CSensorPlotGrid::addSensorData(const CSensorData &data)
{
    mTime.append(static_cast<double>(data.mTime));
    mX1__dd.append(static_cast<double>(data.mX1__dd));
    mX2__dd.append(static_cast<double>(data.mX2__dd));
    mY1__dd.append(static_cast<double>(data.mY1__dd));
    mY2__dd.append(static_cast<double>(data.mY2__dd));
    mPhi1__d.append(static_cast<double>(data.mPhi1__d));
    mPhi2__d.append(static_cast<double>(data.mPhi2__d));

    mX1Plot->graph(0)->setData(mTime, mX1__dd);
    mX1Plot->xAxis->setRange(0.0,
                             *std::max_element(mTime.begin(), mTime.end()));
    mX1Plot->yAxis->setRange(*std::min_element(mX1__dd.begin(), mX1__dd.end()),
                             *std::max_element(mX1__dd.begin(), mX1__dd.end()));
    mX1Plot->replot();

    mX2Plot->graph(0)->setData(mTime, mX2__dd);
    mX2Plot->xAxis->setRange(0.0,
                             *std::max_element(mTime.begin(), mTime.end()));
    mX2Plot->yAxis->setRange(*std::min_element(mX2__dd.begin(), mX2__dd.end()),
                             *std::max_element(mX2__dd.begin(), mX2__dd.end()));
    mX2Plot->replot();

    mY1Plot->graph(0)->setData(mTime, mY1__dd);
    mY1Plot->xAxis->setRange(0.0,
                             *std::max_element(mTime.begin(), mTime.end()));
    mY1Plot->yAxis->setRange(*std::min_element(mY1__dd.begin(), mY1__dd.end()),
                             *std::max_element(mY1__dd.begin(), mY1__dd.end()));
    mY1Plot->replot();

    mY2Plot->graph(0)->setData(mTime, mY2__dd);
    mY2Plot->xAxis->setRange(0.0,
                             *std::max_element(mTime.begin(), mTime.end()));
    mY2Plot->yAxis->setRange(*std::min_element(mY2__dd.begin(), mY2__dd.end()),
                             *std::max_element(mY2__dd.begin(), mY2__dd.end()));
    mY2Plot->replot();

    mPhi1Plot->graph(0)->setData(mTime, mPhi1__d);
    mPhi1Plot->xAxis->setRange(0.0,
                               *std::max_element(mTime.begin(), mTime.end()));
    mPhi1Plot->yAxis->setRange(*std::min_element(mPhi1__d.begin(), mPhi1__d.end()),
                               *std::max_element(mPhi1__d.begin(), mPhi1__d.end()));
    mPhi1Plot->replot();

    mPhi2Plot->graph(0)->setData(mTime, mPhi2__d);
    mPhi2Plot->xAxis->setRange(0.0,
                               *std::max_element(mTime.begin(), mTime.end()));
    mPhi2Plot->yAxis->setRange(*std::min_element(mPhi2__d.begin(), mPhi2__d.end()),
                               *std::max_element(mPhi2__d.begin(), mPhi2__d.end()));
    mPhi2Plot->replot();
}
