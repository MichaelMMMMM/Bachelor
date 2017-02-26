#include "CControlWidget.h"
#include <iostream>
#include <ostream>
#include <fstream>
using namespace std;

CControlWidget::CControlWidget(QWidget *parent) :
    QWidget(parent), mDrawCounter(0), mRunningFlag(false), mGDisplayFlag(false)
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

    mStartButtonPtr = new QPushButton("Start Control-Test");
    mRightLayoutPtr->addWidget(mStartButtonPtr);
    QObject::connect(mStartButtonPtr, SIGNAL(clicked()),
                     this, SLOT(startButtonClicked()));

    mGDisplayCheckBoxPtr = new QCheckBox("Display g-Derivation");
    QObject::connect(mGDisplayCheckBoxPtr, SIGNAL(clicked(bool)),
                     this, SLOT(gDisplayClicked(bool)));
    mRightLayoutPtr->addWidget(mGDisplayCheckBoxPtr);

    mSaveButtonPtr = new QPushButton("Save Data");
    QObject::connect(mSaveButtonPtr, SIGNAL(clicked()),
                     this, SLOT(saveData()));
    mRightLayoutPtr->addWidget(mSaveButtonPtr);

    mCompFilterBoxPtr = new QCheckBox("Enable Comp-Filter");
    QObject::connect(mCompFilterBoxPtr, SIGNAL(clicked()),
                     this, SLOT(onCompFilterBoxClicked()));
    mRightLayoutPtr->addWidget(mCompFilterBoxPtr);

    mOffsetBoxPtr = new QCheckBox("Enable Offset-Correction");
    QObject::connect(mOffsetBoxPtr, SIGNAL(clicked()),
                     this, SLOT(onOffsetBoxClicked()));
    mRightLayoutPtr->addWidget(mOffsetBoxPtr);

    mRightLayoutPtr->addStretch();

    mGPlotPtr = new QCustomPlot;
    mGPlotPtr->addGraph();
    mGPlotPtr->addGraph();
    mGPlotPtr->addGraph();
    mGPlotPtr->graph(0)->setPen(QPen(Qt::blue));
    mGPlotPtr->graph(1)->setPen(QPen(Qt::red));
    mGPlotPtr->graph(2)->setPen(QPen(Qt::green));
    mGPlotPtr->xAxis->setLabel("Time [s]");
    mGPlotPtr->yAxis->setLabel("G [m/s^2]");
    mGPlotPtr->xAxis->setRange(0.0, 20.0);
    mGPlotPtr->yAxis->setRange(-10.5, 10.5);
    mGPlotPtr->graph(0)->setName("g_k1");
    mGPlotPtr->graph(1)->setName("g_k2");
    mGPlotPtr->graph(2)->setName("g_k3");
    mGPlotPtr->graph(0)->addToLegend();
    mGPlotPtr->graph(1)->addToLegend();
    mGPlotPtr->graph(2)->addToLegend();
    mGPlotPtr->legend->setVisible(true);
    mGPlotPtr->replot();

    mUKPlotPtr = new QCustomPlot;
    mUKPlotPtr->addGraph();
    mUKPlotPtr->addGraph();
    mUKPlotPtr->addGraph();
    mUKPlotPtr->graph(0)->setPen(QPen(Qt::blue));
    mUKPlotPtr->graph(1)->setPen(QPen(Qt::red));
    mUKPlotPtr->graph(2)->setPen(QPen(Qt::green));
    mUKPlotPtr->xAxis->setLabel("Time [s]");
    mUKPlotPtr->yAxis->setLabel("U_K [rad/s]");
    mUKPlotPtr->xAxis->setRange(0.0, 20.0);
    mUKPlotPtr->yAxis->setRange(-1.5, 1.5);
    mUKPlotPtr->graph(0)->setName("uK_k1");
    mUKPlotPtr->graph(1)->setName("uK_k2");
    mUKPlotPtr->graph(2)->setName("uK_k3");
    mUKPlotPtr->graph(0)->addToLegend();
    mUKPlotPtr->graph(1)->addToLegend();
    mUKPlotPtr->graph(2)->addToLegend();
    mUKPlotPtr->legend->setVisible(true);
    mUKPlotPtr->replot();

    mURPlotPtr = new QCustomPlot;
    mURPlotPtr->addGraph();
    mURPlotPtr->addGraph();
    mURPlotPtr->addGraph();
    mURPlotPtr->graph(0)->setPen(QPen(Qt::blue));
    mURPlotPtr->graph(1)->setPen(QPen(Qt::red));
    mURPlotPtr->graph(2)->setPen(QPen(Qt::green));
    mURPlotPtr->xAxis->setLabel("Time [s]");
    mURPlotPtr->yAxis->setLabel("U_R [rad/s]");
    mURPlotPtr->xAxis->setRange(0.0, 20.0);
    mURPlotPtr->yAxis->setRange(-150, 150);
    mURPlotPtr->graph(0)->setName("uR_k1");
    mURPlotPtr->graph(1)->setName("uR_k2");
    mURPlotPtr->graph(2)->setName("uR_k3");
    mURPlotPtr->graph(0)->addToLegend();
    mURPlotPtr->graph(1)->addToLegend();
    mURPlotPtr->graph(2)->addToLegend();
    mURPlotPtr->legend->setVisible(true);
    mURPlotPtr->replot();

    mTorquePlotPtr = new QCustomPlot;
    mTorquePlotPtr->addGraph();
    mTorquePlotPtr->addGraph();
    mTorquePlotPtr->addGraph();
    mTorquePlotPtr->graph(0)->setPen(QPen(Qt::blue));
    mTorquePlotPtr->graph(1)->setPen(QPen(Qt::red));
    mTorquePlotPtr->graph(2)->setPen(QPen(Qt::green));
    mTorquePlotPtr->xAxis->setLabel("Time [s]");
    mTorquePlotPtr->yAxis->setLabel("Torque [Nm]");
    mTorquePlotPtr->xAxis->setRange(0.0, 9.0);
    mTorquePlotPtr->yAxis->setRange(-0.130, 0.130);
    mTorquePlotPtr->graph(0)->setName("TM1");
    mTorquePlotPtr->graph(1)->setName("TM2");
    mTorquePlotPtr->graph(2)->setName("TM3");
    mTorquePlotPtr->graph(0)->addToLegend();
    mTorquePlotPtr->graph(1)->addToLegend();
    mTorquePlotPtr->graph(2)->addToLegend();
    mTorquePlotPtr->legend->setVisible(true);
    mTorquePlotPtr->replot(),

    mLeftLayoutPtr->addWidget(mGPlotPtr, 0, 0);
    mLeftLayoutPtr->addWidget(mTorquePlotPtr, 0, 1);
    mLeftLayoutPtr->addWidget(mUKPlotPtr, 1, 0);
    mLeftLayoutPtr->addWidget(mURPlotPtr, 1, 1);
}
void CControlWidget::gDataReceived(const CGData &data)
{
    mGData.append(data);
    mGTime.append(static_cast<double>(data.mTime));
    if(mGDisplayFlag == true)
    {
        mG_k1.append(static_cast<double>(data.mG_k1));
        mG_k2.append(static_cast<double>(data.mG_k2));
        mG_k3.append(static_cast<double>(data.mG_k3));
    }
    else
    {
        mG_k1.append(static_cast<double>(data.mG_k1) - 5.6638);
        mG_k2.append(static_cast<double>(data.mG_k2) - 5.6638);
        mG_k3.append(static_cast<double>(data.mG_k3) - 5.6638);
    }


    if(mGTime.length() > 450)
    {
        mGTime.erase(mGTime.begin());
        mG_k1.erase(mG_k1.begin());
        mG_k2.erase(mG_k2.begin());
        mG_k3.erase(mG_k3.begin());
        mGPlotPtr->xAxis->setRangeLower(*(mGTime.begin()));
        mGPlotPtr->xAxis->setRangeUpper(*(mGTime.end()));
    }
    this->drawPlots();
}
void CControlWidget::ukDataReceived(const CUKData &data)
{
    mUKData.append(data);
    mUKTime.append(static_cast<double>(data.mTime));
    mUK_k1.append(static_cast<double>(data.mUK_k1));
    mUK_k2.append(static_cast<double>(data.mUK_k2));
    mUK_k3.append(static_cast<double>(data.mUK_k3));
    if(mUKTime.length() > 450)
    {
        mUKTime.erase(mUKTime.begin());
        mUK_k1.erase(mUK_k1.begin());
        mUK_k2.erase(mUK_k2.begin());
        mUK_k3.erase(mUK_k3.begin());
        mUKPlotPtr->xAxis->setRangeLower(*(mUKTime.begin()));
        mUKPlotPtr->xAxis->setRangeUpper(*(mUKTime.end()));
    }
    this->drawPlots();
}
void CControlWidget::urDataReceived(const CURData &data)
{
    mURData.append(data);
    mURTime.append(static_cast<double>(data.mTime));
    mUR_k1.append(static_cast<double>(data.mUR_k1));
    mUR_k2.append(static_cast<double>(data.mUR_k2));
    mUR_k3.append(static_cast<double>(data.mUR_k3));
    if(mURTime.length() > 450)
    {
        mURTime.erase(mURTime.begin());
        mUR_k1.erase(mUR_k1.begin());
        mUR_k2.erase(mUR_k2.begin());
        mUR_k3.erase(mUR_k3.begin());
        mURPlotPtr->xAxis->setRangeLower(*(mURTime.begin()));
        mURPlotPtr->xAxis->setRangeUpper(*(mURTime.end()));
    }
    this->drawPlots();
}
void CControlWidget::torqueDataReceived(const CTorqueData &data)
{
    mTorqueData.append(data);
    mTorqueTime.append(static_cast<double>(data.mTime));
    mTM1.append(static_cast<double>(data.mTorque1));
    mTM2.append(static_cast<double>(data.mTorque2));
    mTM3.append(static_cast<double>(data.mTorque3));
    if(mTorqueTime.length() > 450)
    {
        mTorqueTime.erase(mTorqueTime.begin());
        mTM1.erase(mTM1.begin());
        mTM2.erase(mTM2.begin());
        mTM3.erase(mTM3.begin());
        mTorquePlotPtr->xAxis->setRangeLower(*(mTorqueTime.begin()));
        mTorquePlotPtr->xAxis->setRangeUpper(*(mTorqueTime.end()));
    }
}
void CControlWidget::drawPlots()
{
    mDrawCounter++;
    if(mDrawCounter > 20)
    {
        mDrawCounter = 0;
        this->drawGData();
        this->drawUKData();
        this->drawURData();
        this->drawTorqueData();
    }
}
void CControlWidget::drawGData()
{
    mGPlotPtr->graph(0)->setData(mGTime, mG_k1);
    mGPlotPtr->graph(1)->setData(mGTime, mG_k2);
    mGPlotPtr->graph(2)->setData(mGTime, mG_k3);

    double g1_min = *std::min_element(mG_k1.begin(), mG_k1.end());
    double g2_min = *std::min_element(mG_k2.begin(), mG_k2.end());
    double g3_min = *std::min_element(mG_k3.begin(), mG_k3.end());

    g1_min = g1_min < g2_min ? g1_min : g2_min;
    g1_min = g1_min < g3_min ? g1_min : g3_min;

    double g1_max = *std::max_element(mG_k1.begin(), mG_k1.end());
    double g2_max = *std::max_element(mG_k2.begin(), mG_k2.end());
    double g3_max = *std::max_element(mG_k3.begin(), mG_k3.end());

    g1_max = g1_max > g2_max ? g1_max : g2_max;
    g1_max = g1_max > g3_max ? g1_max : g3_max;

    mGPlotPtr->yAxis->setRange(g1_min - 0.5, g1_max + 0.5);

    mGPlotPtr->replot();
}
void CControlWidget::drawUKData()
{
    mUKPlotPtr->graph(0)->setData(mUKTime, mUK_k1);
    mUKPlotPtr->graph(1)->setData(mUKTime, mUK_k2);
    mUKPlotPtr->graph(2)->setData(mUKTime, mUK_k3);

    double uk1_min = *std::min_element(mUK_k1.begin(), mUK_k1.end());
    double uk2_min = *std::min_element(mUK_k2.begin(), mUK_k2.end());
    double uk3_min = *std::min_element(mUK_k3.begin(), mUK_k3.end());

    uk1_min = uk1_min < uk2_min ? uk1_min : uk2_min;
    uk1_min = uk1_min < uk3_min ? uk1_min : uk3_min;

    double uk1_max = *std::max_element(mUK_k1.begin(), mUK_k1.end());
    double uk2_max = *std::max_element(mUK_k2.begin(), mUK_k2.end());
    double uk3_max = *std::max_element(mUK_k3.begin(), mUK_k3.end());

    uk1_max = uk1_max > uk2_max ? uk1_max : uk2_max;
    uk1_max = uk1_max > uk3_max ? uk1_max : uk3_max;

    mUKPlotPtr->yAxis->setRange(uk1_min - 0.02, uk2_max + 0.02);

    mUKPlotPtr->replot();
}
void CControlWidget::drawURData()
{
    mURPlotPtr->graph(0)->setData(mURTime, mUR_k1);
    mURPlotPtr->graph(1)->setData(mURTime, mUR_k2);
    mURPlotPtr->graph(2)->setData(mURTime, mUR_k3);

    double ur1_min = *std::min_element(mUR_k1.begin(), mUR_k1.end());
    double ur2_min = *std::min_element(mUR_k2.begin(), mUR_k2.end());
    double ur3_min = *std::min_element(mUR_k3.begin(), mUR_k3.end());

    ur1_min = ur1_min < ur2_min ? ur1_min : ur2_min;
    ur1_min = ur1_min < ur3_min ? ur1_min : ur3_min;

    double ur1_max = *std::max_element(mUR_k1.begin(), mUR_k1.end());
    double ur2_max = *std::max_element(mUR_k2.begin(), mUR_k2.end());
    double ur3_max = *std::max_element(mUR_k3.begin(), mUR_k3.end());

    ur1_max = ur1_max > ur2_max ? ur1_max : ur2_max;
    ur1_max = ur1_max > ur3_max ? ur1_max : ur3_max;

    mURPlotPtr->yAxis->setRange(ur1_min - 1.0, ur1_max + 1.0);
    mURPlotPtr->replot();
}
void CControlWidget::drawTorqueData()
{
    mTorquePlotPtr->graph(0)->setData(mTorqueTime, mTM1);
    mTorquePlotPtr->graph(1)->setData(mTorqueTime, mTM2);
    mTorquePlotPtr->graph(2)->setData(mTorqueTime, mTM3);

    double tm1_min = *std::min_element(mTM1.begin(), mTM1.end());
    double tm2_min = *std::min_element(mTM2.begin(), mTM2.end());
    double tm3_min = *std::min_element(mTM3.begin(), mTM3.end());

    tm1_min = tm1_min < tm2_min ? tm1_min : tm2_min;
    tm1_min = tm1_min < tm3_min ? tm1_min : tm3_min;

    double tm1_max = *std::max_element(mTM1.begin(), mTM1.end());
    double tm2_max = *std::max_element(mTM2.begin(), mTM2.end());
    double tm3_max = *std::max_element(mTM3.begin(), mTM3.end());
    tm1_max = tm1_max > tm2_max ? tm1_max : tm2_max;
    tm1_max = tm1_max > tm3_max ? tm1_max : tm3_max;
    mTorquePlotPtr->yAxis->setRangeLower(0.15);
    mTorquePlotPtr->yAxis->setRangeUpper(-0.15);

    mTorquePlotPtr->replot();
}
void CControlWidget::startButtonClicked()
{
    if(mRunningFlag == true)
    {
        mRunningFlag = false;
        mStartButtonPtr->setText("Start Control-Test");

        emit stopControlTest();
    }
    else
    {
        mRunningFlag = true;
        mStartButtonPtr->setText("Stop Control-Test");

        mGData.clear();
        mUKData.clear();
        mURData.clear();
        mTorqueData.clear();
        mGTime.clear();
        mG_k1.clear();
        mG_k2.clear();
        mG_k3.clear();
        mUKTime.clear();
        mUK_k1.clear();
        mUK_k2.clear();
        mUK_k3.clear();
        mURTime.clear();
        mUR_k1.clear();
        mUR_k2.clear();
        mUR_k3.clear();
        mTorqueTime.clear();
        mTM1.clear();
        mTM2.clear();
        mTM3.clear();

        mGPlotPtr->graph(0)->clearData();
        mGPlotPtr->graph(1)->clearData();
        mGPlotPtr->graph(2)->clearData();
        mGPlotPtr->replot();

        mUKPlotPtr->graph(0)->clearData();
        mUKPlotPtr->graph(1)->clearData();
        mUKPlotPtr->graph(2)->clearData();
        mUKPlotPtr->replot();

        mURPlotPtr->graph(0)->clearData();
        mURPlotPtr->graph(1)->clearData();
        mURPlotPtr->graph(2)->clearData();
        mURPlotPtr->replot();

        mTorquePlotPtr->graph(0)->clearData();
        mTorquePlotPtr->graph(1)->clearData();
        mTorquePlotPtr->graph(2)->clearData();
        mTorquePlotPtr->replot();

        emit runControlTest();
    }
}
void CControlWidget::gDisplayClicked(bool state)
{
    mGDisplayFlag = state;
}
void CControlWidget::onCompFilterBoxClicked()
{
    bool flag = mCompFilterBoxPtr->isChecked();
    emit setCompFilterFlag(flag);
}
void CControlWidget::onOffsetBoxClicked()
{
    bool flag = mOffsetBoxPtr->isChecked();
    emit setOffsetFilterFlag(flag);
}

void CControlWidget::saveData()
{
    string g_file     = "control_g_data.csv";
    ofstream g_stream;
    g_stream.open(g_file);
    g_stream << "t_g, g1, g2, g3\n";
    QVectorIterator<CGData> g_it(mGData);

    while(g_it.hasNext())
    {
        const CGData& g = g_it.next();
        string tmp = to_string(g.mTime);
        tmp.replace(tmp.find(",", 0), 1, ".");
        g_stream << tmp << ", ";

        tmp = to_string(g.mG_k1);
        tmp.replace(tmp.find(",", 0), 1, ".");
        g_stream << tmp << ", ";

        tmp = to_string(g.mG_k2);
        tmp.replace(tmp.find(",", 0), 1, ".");
        g_stream << tmp << ", ";

        tmp = to_string(g.mG_k3);
        tmp.replace(tmp.find(",", 0), 1, ".");
        g_stream << tmp << "\n";
    }
    g_stream.close();

    string uk_file = "control_uk_data.csv";
    ofstream uk_stream;
    uk_stream.open(uk_file);
    uk_stream << "t_uk, uk1, uk2, uk3\n";

    QVectorIterator<CUKData> uk_it(mUKData);

    while(uk_it.hasNext())
    {
        const CUKData& uk = uk_it.next();
        string tmp = to_string(uk.mTime);
        tmp.replace(tmp.find(",", 0), 1, ".");
        uk_stream << tmp << ", ";

        tmp = to_string(uk.mUK_k1);
        tmp.replace(tmp.find(",", 0), 1, ".");
        uk_stream << tmp << ", ";

        tmp = to_string(uk.mUK_k2);
        tmp.replace(tmp.find(",", 0), 1, ".");
        uk_stream << tmp << ", ";

        tmp = to_string(uk.mUK_k3);
        tmp.replace(tmp.find(",", 0), 1, ".");
        uk_stream << tmp << "\n";
    }
    uk_stream.close();

    string ur_file = "control_ur_data.csv";
    ofstream ur_stream;
    ur_stream.open(ur_file);
    ur_stream << "t_ur, ur1, ur2, ur3\n";

    QVectorIterator<CURData> ur_it(mURData);
    while(ur_it.hasNext())
    {
        const CURData& ur = ur_it.next();
        string tmp = to_string(ur.mTime);
        tmp.replace(tmp.find(",", 0), 1, ".");
        ur_stream << tmp << ", ";

        tmp = to_string(ur.mUR_k1);
        tmp.replace(tmp.find(",", 0), 1, ".");
        ur_stream << tmp << ", ";

        tmp = to_string(ur.mUR_k2);
        tmp.replace(tmp.find(",", 0), 1, ".");
        ur_stream << tmp << ", ";

        tmp = to_string(ur.mUR_k3);
        tmp.replace(tmp.find(",", 0), 1, ".");
        ur_stream << tmp << "\n";
    }
    ur_stream.close();

    string tm_file = "control_tm_data.csv";
    ofstream tm_stream;
    tm_stream.open(tm_file);
    tm_stream << "t_tm, tm1, tm2, tm3\n";

    QVectorIterator<CTorqueData> tm_it(mTorqueData);
    while(tm_it.hasNext())
    {
        const CTorqueData& tm = tm_it.next();
        string tmp = to_string(tm.mTime);
        tmp.replace(tmp.find(",", 0), 1, ".");
        tm_stream << tmp << ", ";

        tmp = to_string(tm.mTorque1);
        tmp.replace(tmp.find(",", 0), 1, ".");
        tm_stream << tmp << ", ";

        tmp = to_string(tm.mTorque2);
        tmp.replace(tmp.find(",", 0), 1, ".");
        tm_stream << tmp << ", ";

        tmp = to_string(tm.mTorque3);
        tmp.replace(tmp.find(",", 0), 1, ".");
        tm_stream << tmp << "\n";
    }
    tm_stream.close();


}
