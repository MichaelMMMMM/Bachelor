#ifndef CSENSORPLOTGRID_H
#define CSENSORPLOTGRID_H
#include "qcustomplot.h"
#include <QGridLayout>
#include "Global.h"
#include "CSensorData.h"

class CSensorPlotGrid : public QGridLayout
{
    Q_OBJECT
public:
    explicit CSensorPlotGrid();
    void sensorDataReceived(const CSensorData& data);
    void resetData();
    void saveCSV();
signals:
    void measurementFinished();
public slots:
    void setNumberOfDatapoints(int newValue);
    void setPhiValue(int newValue);
private:
    QCustomPlot* mX1PlotPtr;
    QCustomPlot* mX2PlotPtr;
    QCustomPlot* mY1PlotPtr;
    QCustomPlot* mY2PlotPtr;
    QCustomPlot* mPhi1PlotPtr;
    QCustomPlot* mPhi2PlotPtr;

    QVector<double> mTime;
    QVector<double> mX1__dd;
    QVector<double> mX2__dd;
    QVector<double> mY1__dd;
    QVector<double> mY2__dd;
    QVector<double> mPhi1__d;
    QVector<double> mPhi2__d;

    Int32 mNumberOfDatapoints;
    Int32 mPhi;
    Int32 mPlotCounter;
    bool mSaveFlag;
};

#endif // CSENSORPLOTGRID_H
