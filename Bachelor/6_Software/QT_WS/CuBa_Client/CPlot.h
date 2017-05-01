#ifndef CPLOT_H
#define CPLOT_H
#include <QWidget>
#include "QCustomPlot.h"
#include <QString>

class CPlot
{
public:
    void saveCSV(const std::string& filename,
                 const QVector<std::string>& varNames,
                 bool force = false);
    void addData(double time, QVector<double>& data);
    void addData(double time, double data, int graphIndex);
    void reset();
    void setDisplayFlag(bool flag, int index);
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
    bool mSavedFlag;
    QVector<double>     mTime;
    QVector<double>     mDisplayTime;
    QVector<QVector<double> >     mData;
    QVector<QVector<double> >     mDisplayData;

    QCustomPlot* mPlotPtr;
    bool*        mDisplayFlagsPtr;
};

#endif // CPLOT_H
