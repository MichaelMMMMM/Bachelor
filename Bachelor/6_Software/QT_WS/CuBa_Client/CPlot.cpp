#include "CPlot.h"
#include <iostream>
#include <ostream>
#include <fstream>
using namespace std;

CPlot::CPlot(int nbrOfLines,
             const QString& yLabel,
             const QString& plotTitle,
             QVector<QString>& legend,
             QVector<QPen>& lineColors) : mNumberOfLines(nbrOfLines),
                                          mDrawCounter(0),
                                          mSavedFlag(false)
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
        double min =  1000000;
        double max = -1000000;
        for(int i = 0; i < mNumberOfLines; i++)
        {
            double max_i = *std::max_element(mDisplayData.at(i).begin(),
                                             mDisplayData.at(i).end());
            max = max > max_i ? max : max_i;
            double min_i = *std::min_element(mDisplayData.at(i).begin(),
                                             mDisplayData.at(i).end());
            min = min < min_i ? min : min_i;
            mPlotPtr->graph(i)->setData(mDisplayTime, mDisplayData.at(i));
        }
        mPlotPtr->xAxis->setRange(mDisplayTime.first(), mDisplayTime.last());
        mPlotPtr->yAxis->setRange(min*1.1, max*1.1);
        mPlotPtr->replot();
    }
}
void CPlot::reset()
{
    mSavedFlag = false;
    mDisplayTime.clear();
    mTime.clear();
    for(int i = 0; i < mNumberOfLines; i++)
    {
        mDisplayData[i].clear();
        mData[i].clear();
        mPlotPtr->graph(i)->setData(mDisplayTime, mDisplayData.at(i));
    }
    mPlotPtr->xAxis->setRange(0.0, 5.0);
    mPlotPtr->yAxis->setRange(0.0, 5.0);
    mPlotPtr->replot();
}
QCustomPlot* CPlot::getPlotPtr()
{
    return mPlotPtr;
}
void CPlot::saveCSV(const std::string& filename,
                    const QVector<std::string>& varNames)
{
    if(mSavedFlag == false)
    {
        mSavedFlag = true;
        ofstream stream;
        stream.open(filename);
        stream << "t";
        for(int i = 0; i < mNumberOfLines; i++)
        {
            stream << ", " << varNames[i];
        }
        stream << "\n";

        for(int k = 0; k < mTime.length(); k++)
        {
            string tmp = to_string(mTime[k]);
            tmp.replace(tmp.find(",", 0), 1, ".");
            stream << tmp;
            for(int i = 0; i < mNumberOfLines; i++)
            {
                tmp = to_string(mData[i].at(k));
                tmp.replace(tmp.find(",", 0), 1, ".");
                stream << ", " << tmp;
            }
            stream << "\n";
        }
        stream.close();
    }
}
