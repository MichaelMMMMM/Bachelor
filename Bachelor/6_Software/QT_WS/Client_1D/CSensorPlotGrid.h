#ifndef CSENSORPLOTGRID_H
#define CSENSORPLOTGRID_H
#include <QWidget>
#include "CSensorData.h"
#include "qcustomplot.h"

class CSensorPlotGrid : public QGridLayout
{
    Q_OBJECT
public:
    void addSensorData(const CSensorData& data);
private slots:
    void onSensorDataReceived(CSensorData);
public:
    CSensorPlotGrid(QWidget* parent = nullptr);
    CSensorPlotGrid(const CSensorPlotGrid&) = delete;
    CSensorPlotGrid& operator=(const CSensorPlotGrid&) = delete;
    ~CSensorPlotGrid() = default;
private:
    QCustomPlot* mX1Plot;
    QCustomPlot* mX2Plot;
    QCustomPlot* mY1Plot;
    QCustomPlot* mY2Plot;
    QCustomPlot* mPhi1Plot;
    QCustomPlot* mPhi2Plot;

    QVector<double> mTime;
    QVector<double> mX1__dd;
    QVector<double> mX2__dd;
    QVector<double> mY1__dd;
    QVector<double> mY2__dd;
    QVector<double> mPhi1__d;
    QVector<double> mPhi2__d;
};

#endif // CSENSORPLOTGRID_H
