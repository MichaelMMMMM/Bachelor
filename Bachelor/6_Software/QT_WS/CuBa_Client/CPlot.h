#ifndef CPLOT_H
#define CPLOT_H
#include <QWidget>
#include "QCustomPlot.h"
#include <QString>

class CPlot
{
public:
    void addData(double time, QVector<double>& data);
    QCustomPlot* getPlotPtr();
public:
    CPlot(int nbrOfLines,
          const QString& yLabel,
          const QString& title,
          QVector<QString>& legend,
          QVector<QPen>& lineColors);
private:
    int mNumberOfLines;
    int mDrawCounter;
    QVector<double>     mTime;
    QVector<double>     mDisplayTime;
    QVector<QVector<double> >     mData;
    QVector<QVector<double> >     mDisplayData;

    QCustomPlot* mPlotPtr;
};

#endif // CPLOT_H
