#ifndef CCONTROLWIDGET_H
#define CCONTROLWIDGET_H
#include "qcustomplot.h"
#include "CPhi.h"
#include "CPhi__d.h"
#include "EFilter.h"
#include "CPsi__d.h"
#include <QWidget>

class CControlWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CControlWidget();

signals:
    void phiOffsetChanged(float offset);
    void phi__dOffsetChanged(float offset);
    void psi__dOffsetChanged(float offset);
    void filterChanged(EFilter filter);
    void highpassFlagChanged(bool flag);
    void lqrFlagChanged(bool flag);
public slots:
    void phiDataReceived(const CPhi& data);
    void phi__dDataReceived(const CPhi__d& data);
    void psi__dDataReceived(const CPsi__d& data);
    void phiOffsetButtonClicked();
    void phi__dOffsetButtonClicked();
    void psi__dOffsetButtonClicked();
    void phiFilterSelected(bool toggled);
    void phi__dFilterSelected(bool toggled);
    void psi__dFilterSelected(bool toggled);
    void highpassCheckboxToggled(bool flag);
    void controllerGroupClicked();
private:
    void drawPlots();
private:
    QHBoxLayout* mCentralLayoutPtr;
    QWidget*     mLeftWidgetPtr;
    QWidget*     mRightWidgetPtr;
    QGridLayout* mLeftLayoutPtr;
    QVBoxLayout* mRightLayoutPtr;

    QCustomPlot* mPhiPlotPtr;
    QCustomPlot* mPhi__dPlotPtr;
    QCustomPlot* mPsi__dPlotPtr;

    QHBoxLayout*    mPhiOffsetLayoutPtr;
    QDoubleSpinBox* mPhiOffsetInputPtr;
    QLabel*         mPhiOffsetLabelPtr;
    QPushButton*    mPhiOffsetButtonPtr;

    QHBoxLayout*    mPhi__dOffsetLayoutPtr;
    QDoubleSpinBox* mPhi__dOffsetInputPtr;
    QLabel*         mPhi__dOffsetLabelPtr;
    QPushButton*    mPhi__dOffsetButtonPtr;

    QHBoxLayout*    mPsi__dOffsetLayoutPtr;
    QDoubleSpinBox* mPsi__dOffsetInputPtr;
    QLabel*         mPsi__dOffsetLabelPtr;
    QPushButton*    mPsi__dOffsetButtonPtr;

    QGroupBox*      mPhiFilterGroupPtr;
    QVBoxLayout*    mPhiFilterLayoutPtr;
    QRadioButton*   mPhiFilterNoneButtonPtr;
    QRadioButton*   mPhiFilterCompButtonPtr;

    QGroupBox*      mPhi__dFilterGroupPtr;
    QVBoxLayout*    mPhi__dFilterLayoutPtr;
    QRadioButton*   mPhi__dFilterNoneButtonPtr;
    QRadioButton*   mPhi__dFilterPT1_5HzButtonPtr;
    QRadioButton*   mPhi__dFilterPT1_10HzButtonPtr;

    QGroupBox*      mPsi__dFilterGroupPtr;
    QVBoxLayout*    mPsi__dFilterLayoutPtr;
    QRadioButton*   mPsi__dFilterNoneButtonPtr;
    QRadioButton*   mPsi__dFilterPT1_5HzButtonPtr;
    QRadioButton*   mPsi__dFilterPT1_10HzButtonPtr;

    QCheckBox*      mHighpassCheckBoxPtr;

    QGroupBox*      mControlGroupPtr;
    QVBoxLayout*    mControlLayoutPtr;
    QRadioButton*   mLQRButtonPtr;
    QRadioButton*   mCascButtonPtr;

    QVector<double> mPhiTime;
    QVector<double> mPhi_Acc;
    QVector<double> mPhiXVector;
    QVector<double> mPhiYVector;
    QVector<double> mPhi_Comp;
    QVector<double> mPhi__dTime;
    QVector<double> mPhi__dXVector;
    QVector<double> mPhi__dYVector;
    QVector<double> mPhi__d;
    QVector<double> mPsi__dTime;
    QVector<double> mPsi__d;
    QVector<double> mPsi__dXVector;
    QVector<double> mPsi__dYVector;

    int mDrawCounter;
};

#endif // CCONTROLWIDGET_H
