#include "CEdgeBalanceWidget.h"

CEdgeBalanceWidget::CEdgeBalanceWidget(QWidget *parent) :
    QWidget(parent), mDrawCounter(0), mRunningFlag(false)
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

    //Setup the control widgets
    mStartButtonPtr = new QPushButton("Start Control");
    QObject::connect(mStartButtonPtr, SIGNAL(clicked()),
                     this, SLOT(startButtonClickedSLOT()));
    mRightLayoutPtr->addWidget(mStartButtonPtr);

    mOffsetBoxPtr   = new QCheckBox("Enable Offset-Correction");
    mOffsetBoxPtr->setChecked(true);
    QObject::connect(mOffsetBoxPtr, SIGNAL(clicked(bool)),
                     this, SLOT(offsetCheckboxClicked(bool)));
    mRightLayoutPtr->addWidget(mOffsetBoxPtr);

    mLQRBoxPtr      = new QCheckBox("Enable LQR");
    mLQRBoxPtr->setChecked(true);
    QObject::connect(mLQRBoxPtr, SIGNAL(clicked(bool)),
                     this, SLOT(lqrCheckboxClickedSLOT(bool)));
    mRightLayoutPtr->addWidget(mLQRBoxPtr);

    mRightLayoutPtr->addStretch();

    //Setup the plots
    mGPlotPtr = new QCustomPlot;
    mGPlotPtr->addGraph();
    mGPlotPtr->addGraph();
    mGPlotPtr->graph(0)->setPen(QPen(Qt::blue));
    mGPlotPtr->graph(1)->setPen(QPen(Qt::red));
    mGPlotPtr->xAxis->setLabel("Time [s]");
    mGPlotPtr->yAxis->setLabel("g_div [m/s^2]");
    mGPlotPtr->xAxis->setRange(0.0, 10.0);
    mGPlotPtr->yAxis->setRange(-10.5, 10.5);
    mGPlotPtr->graph(0)->setName("LQR");
    mGPlotPtr->graph(1)->setName("LQG");
    mGPlotPtr->graph(0)->addToLegend();
    mGPlotPtr->graph(1)->addToLegend();
    mGPlotPtr->legend->setVisible(true);
    mGPlotPtr->replot();

    mUKPlotPtr = new QCustomPlot;
    mUKPlotPtr->addGraph();
    mUKPlotPtr->addGraph();
    mUKPlotPtr->graph(0)->setPen(QPen(Qt::blue));
    mUKPlotPtr->graph(1)->setPen(QPen(Qt::red));
    mUKPlotPtr->xAxis->setLabel("Time [s]");
    mUKPlotPtr->yAxis->setLabel("u_K [rad/sec]");
    mUKPlotPtr->xAxis->setRange(0.0, 10.0);
    mUKPlotPtr->yAxis->setRange(-1.0, 1.0);
    mUKPlotPtr->graph(0)->setName("LQR");
    mUKPlotPtr->graph(1)->setName("LQG");
    mUKPlotPtr->graph(0)->addToLegend();
    mUKPlotPtr->graph(1)->addToLegend();
    mUKPlotPtr->legend->setVisible(true);
    mUKPlotPtr->replot();

    mURPlotPtr = new QCustomPlot;
    mURPlotPtr->addGraph();
    mURPlotPtr->addGraph();
    mURPlotPtr->graph(0)->setPen(QPen(Qt::blue));
    mURPlotPtr->graph(1)->setPen(QPen(Qt::red));
    mURPlotPtr->xAxis->setLabel("Time [s]");
    mURPlotPtr->yAxis->setLabel("u_R [rad/sec]");
    mURPlotPtr->xAxis->setRange(0.0, 10.0);
    mURPlotPtr->yAxis->setRange(-30.0, 30.0);
    mURPlotPtr->graph(0)->setName("LQR");
    mURPlotPtr->graph(1)->setName("LQG");
    mURPlotPtr->graph(0)->addToLegend();
    mURPlotPtr->graph(1)->addToLegend();
    mURPlotPtr->legend->setVisible(true);
    mURPlotPtr->replot();

    mTMPlotPtr = new QCustomPlot;
    mTMPlotPtr->addGraph();
    mTMPlotPtr->addGraph();
    mTMPlotPtr->graph(0)->setPen(QPen(Qt::blue));
    mTMPlotPtr->graph(1)->setPen(QPen(Qt::red));
    mTMPlotPtr->xAxis->setLabel("Time [s]");
    mTMPlotPtr->yAxis->setLabel("TM [Nm]");
    mTMPlotPtr->xAxis->setRange(0.0, 10.0);
    mTMPlotPtr->yAxis->setRange(-0.11, 0.11);
    mTMPlotPtr->graph(0)->setName("LQR");
    mTMPlotPtr->graph(1)->setName("LQG");
    mTMPlotPtr->graph(0)->addToLegend();
    mTMPlotPtr->graph(1)->addToLegend();
    mTMPlotPtr->legend->setVisible(true);
    mTMPlotPtr->replot();

    mLeftLayoutPtr->addWidget(mGPlotPtr, 0, 0);
    mLeftLayoutPtr->addWidget(mUKPlotPtr, 0, 1);
    mLeftLayoutPtr->addWidget(mURPlotPtr, 0, 2);
    mLeftLayoutPtr->addWidget(mTMPlotPtr, 1, 0);
}
void CEdgeBalanceWidget::startButtonClickedSLOT()
{
    if(mRunningFlag == false)
    {
        mRunningFlag = true;
        mLQRData.clear();
        mLQGData.clear();
        mLQRTime.clear();
        mLQGTime.clear();
        mGLQR.clear();
        mGLQG.clear();
        mUKLQG.clear();
        mUKLQR.clear();
        mURLQR.clear();
        mURLQG.clear();
        mTMLQR.clear();
        mTMLQG.clear();

        mGPlotPtr->xAxis->setRange(0.0, 10.0);
        mGPlotPtr->yAxis->setRange(-10.5, 10.5);
        mGPlotPtr->replot();
        mUKPlotPtr->xAxis->setRange(0.0, 10.0);
        mUKPlotPtr->yAxis->setRange(-1.0, 1.0);
        mUKPlotPtr->replot();
        mURPlotPtr->xAxis->setRange(0.0, 10.0);
        mURPlotPtr->yAxis->setRange(-30.0, 30.0);
        mURPlotPtr->replot();
        mTMPlotPtr->xAxis->setRange(0.0, 10.0);
        mTMPlotPtr->yAxis->setRange(-0.11, 0.11);
        mTMPlotPtr->replot();

        mStartButtonPtr->setText("Stop Control");
        emit runEdgeBalanceSIG();
    }
    else
    {
        mRunningFlag = false;
        mStartButtonPtr->setText("Start Control");
        emit stopEdgeBalanceSIG();
    }
}
void CEdgeBalanceWidget::lqgDataReceivedSLOT(const Data1D& data)
{
    mLQGData.append(data);
    double x1 = static_cast<double>(data.scalarAt(1,1));
    double x2 = static_cast<double>(data.scalarAt(2,1));
    double x3 = static_cast<double>(data.scalarAt(3,1));
    double u  = static_cast<double>(data.scalarAt(4,1));
    mGLQG.append(x1);
    mUKLQG.append(x2);
    mURLQG.append(x3);
    mTMLQG.append(u);
    mLQGTime.append(mLQRTime.last());
    if(mGLQG.length() > 500)
    {
        mLQGTime.erase(mLQGTime.begin());
        mGLQG.erase(mGLQG.begin());
        mUKLQG.erase(mUKLQG.begin());
        mURLQG.erase(mURLQG.begin());
        mTMLQG.erase(mTMLQG.begin());
    }
    this->redrawPlots();
}
void CEdgeBalanceWidget::lqrDataReceivedSLOT(const Data1D& data)
{
    mLQRData.append(data);
    double x1 = static_cast<double>(data.scalarAt(1,1));
    double x2 = static_cast<double>(data.scalarAt(2,1));
    double x3 = static_cast<double>(data.scalarAt(3,1));
    double u  = static_cast<double>(data.scalarAt(4,1));
    mGLQR.append(x1);
    mUKLQR.append(x2);
    mURLQR.append(x3);
    mTMLQR.append(u);
    if(mLQRTime.length() == 0)
    {
        mLQRTime.append(0.0);
    }
    else
    {
        double time_end = mLQRTime.last();
        mLQRTime.append(time_end + 0.02);
    }
    if(mGLQR.length() > 500)
    {
        mLQRTime.erase(mLQRTime.begin());
        mGLQR.erase(mGLQR.begin());
        mUKLQR.erase(mUKLQR.begin());
        mURLQR.erase(mURLQR.begin());
        mTMLQR.erase(mTMLQR.begin());
    }
    this->redrawPlots();
}
void CEdgeBalanceWidget::redrawPlots()
{
    mDrawCounter++;
    if(mDrawCounter > 4)
    {
        mDrawCounter = 0;
        mGPlotPtr->graph(0)->setData(mLQRTime, mGLQR);
        mGPlotPtr->graph(1)->setData(mLQGTime, mGLQG);

        double min1 = *std::min_element(mGLQR.begin(), mGLQR.end());
        double min2 = *std::min_element(mGLQG.begin(), mGLQG.end());
        min1 = min1 < min2 ? min1 : min2;

        double max1 = *std::max_element(mGLQR.begin(), mGLQR.end());
        double max2 = *std::max_element(mGLQG.begin(), mGLQG.end());
        //max1 = max1 > max2 ? max1 : max2;


        mGPlotPtr->yAxis->setRange(min1 - 0.01, max1 + 0.01);
        mGPlotPtr->xAxis->setRange(mLQRTime.first(), mLQRTime.last());

        mUKPlotPtr->graph(0)->setData(mLQRTime, mUKLQR);
        mUKPlotPtr->graph(1)->setData(mLQGTime, mUKLQG);

        min1 = *std::min_element(mUKLQR.begin(), mUKLQR.end());
        min2 = *std::min_element(mUKLQG.begin(), mUKLQG.end());
        min1 = min1 < min2 ? min1 : min2;

        max1 = *std::max_element(mUKLQR.begin(), mUKLQR.end());
        max2 = *std::max_element(mUKLQG.begin(), mUKLQG.end());
        max1 = max1 > max2 ? max1 : max2;

        mUKPlotPtr->yAxis->setRange(min1 - 0.002, max1 + 0.002);
        mUKPlotPtr->xAxis->setRange(mLQRTime.first(), mLQRTime.last());

        mURPlotPtr->graph(0)->setData(mLQRTime, mURLQR);
        mURPlotPtr->graph(1)->setData(mLQGTime, mURLQG);

        min1 = *std::min_element(mURLQR.begin(), mURLQR.end());
        min2 = *std::min_element(mURLQG.begin(), mURLQG.end());
        min1 = min1 < min2 ? min1 : min2;

        max1 = *std::max_element(mURLQR.begin(), mURLQR.end());
        max2 = *std::max_element(mURLQG.begin(), mURLQG.end());
        max1 = max1 > max2 ? max1 : max2;

        mURPlotPtr->yAxis->setRange(min1 - 1.0, max1 + 1.0);
        mURPlotPtr->xAxis->setRange(mLQRTime.first(), mLQRTime.last());

        mTMPlotPtr->graph(0)->setData(mLQRTime, mTMLQR);
        mTMPlotPtr->graph(1)->setData(mLQGTime, mTMLQG);

        min1 = *std::min_element(mTMLQR.begin(), mTMLQR.end());
        min2 = *std::min_element(mTMLQG.begin(), mTMLQG.end());
        min1 = min1 < min2 ? min1 : min2;

        max1 = *std::max_element(mTMLQR.begin(), mTMLQR.end());
        max2 = *std::max_element(mTMLQG.begin(), mTMLQG.end());
        max1 = max1 > max2 ? max1 : max2;

        mTMPlotPtr->yAxis->setRange(min1 - 0.01, max1 + 0.01);
        mTMPlotPtr->xAxis->setRange(mLQRTime.first(), mLQRTime.last());

        mGPlotPtr->replot();
        mUKPlotPtr->replot();
        mURPlotPtr->replot();
        mTMPlotPtr->replot();

    }
}
void CEdgeBalanceWidget::offsetCheckboxClicked(bool flag)
{
    emit setOffsetCorrectionFlagSIG(flag);
}
void CEdgeBalanceWidget::lqrCheckboxClickedSLOT(bool flag)
{
    emit setLQRFlagSIG(flag);
}
