#ifndef CEDGEBALANCE_H
#define CEDGEBALANCE_H
#include <QDoubleSpinBox>
#include <QFrame>
#include <QPalette>
#include "CExperimentWidget.h"
#include "CPlot.h"
#include "E1DControlSystem.h"

class CEdgeBalance : public CExperimentWidget
{
    Q_OBJECT
signals:
    void runEdgeBalanceSIG();
    void stopEdgeBalanceSIG();
    void setPhiOffsetSIG(double);
    void setUKOffsetSIG(double);
    void setUROffsetSIG(double);
    void selectControlSystemSIG(E1DControlSystem);
    void updateConfigSIG();
public slots:
    void compLQR1DDataReceivedSLOT(double time, QVector<double> data);
    void phiObsLQR1DDataReceivedSLOT(double time, QVector<double> data);
    void fullObsLQR1DDataReceivedSLOT(double time, QVector<double> data);
    void startButtonSLOT();
    void saveButtonSLOT();
    void offsetButtonSLOT();
    void controlRadioButtonSLOT();
    void updateConfigButtonSLOT();
    void displayButtonSLOT();
public:
    CEdgeBalance();
private:
    void createControls();
    void createPlots();
    void createOffsetControls();
private:
    bool    mStartedFlag;

    CPlot*  mPhiPlotPtr;
    CPlot*  mUKPlotPtr;
    CPlot*  mURPlotPtr;
    CPlot*  mUPlotPtr;

    QPushButton* mStartButtonPtr;
    QPushButton* mSaveButtonPtr;
    QPushButton* mUpdateConfigButtonPtr;

    QFrame*         mOffsetWidgetPtr;
    QVBoxLayout*    mOffsetLayoutPtr;

    QHBoxLayout*    mPhiOffsetLayoutPtr;
    QLabel*         mPhiOffsetLabelPtr;
    QDoubleSpinBox* mPhiOffsetInputPtr;

    QHBoxLayout*    mUKOffsetLayoutPtr;
    QLabel*         mUKOffsetLabelPtr;
    QDoubleSpinBox* mUKOffsetInputPtr;

    QHBoxLayout*    mUROffsetLayoutPtr;
    QLabel*         mUROffsetLabelPtr;
    QDoubleSpinBox* mUROffsetInputPtr;

    QPushButton*    mOffsetButtonPtr;

    QRadioButton*   mCompLQRButtonPtr;
    QRadioButton*   mPhiObsLQRButtonPtr;
    QRadioButton*   mFullObsLQRButtonPtr;

    QVBoxLayout*    mDisplayLayoutPtr;
    QCheckBox*      mCompDisplayPtr;
    QCheckBox*      mPhiObsDisplayPtr;
    QCheckBox*      mFullObsDisplayPtr;
};

#endif // CEDGEBALANCE_H
