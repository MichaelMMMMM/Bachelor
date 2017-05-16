#include "CExperimentWidget.h"

CExperimentWidget::CExperimentWidget(QWidget* parent) : QWidget(parent)
{
    mCentralLayoutPtr = new QHBoxLayout;
    this->setLayout(mCentralLayoutPtr);

    mPlotWidgetPtr = new QWidget;
    QSizePolicy plotSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    plotSizePolicy.setHorizontalStretch(4);
    mPlotWidgetPtr->setSizePolicy(plotSizePolicy);
    mPlotLayoutPtr = new QGridLayout;
    mPlotWidgetPtr->setLayout(mPlotLayoutPtr);

    mControlWidgetPtr = new QWidget;
    QSizePolicy controlSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    controlSizePolicy.setHorizontalStretch(1);
    mControlWidgetPtr->setSizePolicy(controlSizePolicy);
    mControlLayoutPtr = new QVBoxLayout;
    mControlWidgetPtr->setLayout(mControlLayoutPtr);

    mCentralLayoutPtr->addWidget(mPlotWidgetPtr);
    mCentralLayoutPtr->addWidget(mControlWidgetPtr);
}
