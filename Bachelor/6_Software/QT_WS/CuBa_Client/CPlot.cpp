#include "CPlot.h"

CPlot::CPlot(int nbrOfLines,
             const QString& yLabel,
             const QString& plotTitle,
             QVector<QString>& legend,
             QVector<QPen>& lineColors) : mNumberOfLines(nbrOfLines),
                                          mDrawCounter(0)
{
    mPlotPtr = new QCustomPlot;
    mPlotPtr->xAxis->setLabel("Time  in seconds");
    mPlotPtr->yAxis->setLabel(yLabel);

    QCPPlotTitle* title = new QCPPlotTitle(mPlotPtr);
    title->setText(plotTitle);
    title->setFont(QFont("sans", 12, QFont::Bold));
    mPlotPtr->plotLayout()->insertRow(0);
    mPlotPtr->plotLayout()->addElement(0,0, title);

    for(int i = 0; i < mNumberOfLines; i++)
    {
        mPlotPtr->addGraph();
        mPlotPtr->graph(i)->setName(legend.at(i));
        mPlotPtr->graph(i)->addToLegend();
        mPlotPtr->graph(i)->setPen(lineColors.at(i));
        mData.append(QVector<double>());
        mDisplayData.append(QVector<double>());
    }
    mPlotPtr->legend->setVisible(true);
}
void CPlot::addData(double time, QVector<double> &data)
{
    mTime.append(time);
    mDisplayTime.append(time);
    for(int i = 0; i < mNumberOfLines; i++)
    {
        QVector<double>& dataVec = mData[i];
        dataVec.append(data.at(i));
        mDisplayData[i].append(data.at(i));
    }

    if(mTime.length() >= 500)
    {
        mDisplayTime.erase(mDisplayTime.begin());
        for(int i = 0; i < mNumberOfLines; i++)
        {
            mDisplayData[i].erase(mDisplayData[i].begin());
        }
    }

    mDrawCounter++;
    if(mDrawCounter >= 0)
    {
        mDrawCounter = 0;

        for(int i = 0; i < mNumberOfLines; i++)
        {
            mPlotPtr->graph(i)->setData(mDisplayTime, mDisplayData.at(i));
        }
        mPlotPtr->replot();
    }
}

QCustomPlot* CPlot::getPlotPtr()
{
    return mPlotPtr;
}
