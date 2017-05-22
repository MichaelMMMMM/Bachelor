#ifndef CEXPERIMENTWIDGET_H
#define CEXPERIMENTWIDGET_H
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>

class CExperimentWidget : public QWidget
{
    Q_OBJECT
public:

public:

public:
    explicit CExperimentWidget(QWidget* parent = 0);
    CExperimentWidget(const CExperimentWidget&) = delete;
    CExperimentWidget& operator=(const CExperimentWidget&) = delete;
    ~CExperimentWidget() = default;
protected:
    QGridLayout*    mPlotLayoutPtr;
    QVBoxLayout*    mControlLayoutPtr;
private:
    QHBoxLayout*    mCentralLayoutPtr;
    QWidget*        mPlotWidgetPtr;
    QWidget*        mControlWidgetPtr;
};


#endif // CEXPERIMENTWIDGET_H

