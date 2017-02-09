#ifndef CSENSORCALIBWIDGET_H
#define CSENSORCALIBWIDGET_H
#include "Global.h"
#include "CMPUData.h"
#include "qcustomplot.h"
#include <QWidget>

class CSensorCalibWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CSensorCalibWidget();
    void drawPlots();
    void saveCSV();
signals:
    void runSensorMeasurement();
    void endMeasurement();
public slots:
    void startClicked();
    void sensor1DataReceived(const CMPUData& data);
    void sensor2DataReceived(const CMPUData& data);
    void sensor3DataReceived(const CMPUData& data);
    void sensor4DataReceived(const CMPUData& data);
    void sensor5DataReceived(const CMPUData& data);
    void sensor6DataReceived(const CMPUData& data);
private:
    bool         mSavedFlag;
    int          mDrawCounter;
    QHBoxLayout* mCentralLayoutPtr;
    QWidget*     mLeftWidgetPtr;
    QGridLayout* mLeftLayoutPtr;
    QWidget*     mRightWidgetPtr;
    QVBoxLayout* mRightLayoutPtr;
    QPushButton* mStartButtonPtr;

    //Plots for the Sensor-Values
    QCustomPlot* mXAccelPlotPtr;
    QCustomPlot* mYAccelPlotPtr;
    QCustomPlot* mZAccelPlotPtr;
    QCustomPlot* mXAnglVelPlotPtr;
    QCustomPlot* mYAnglVelPlotPtr;
    QCustomPlot* mZAnglVelPlotPtr;
    //Time Vectors
    QVector<double> mTime1;
    QVector<double> mTime2;
    QVector<double> mTime3;
    QVector<double> mTime4;
    QVector<double> mTime5;
    QVector<double> mTime6;
    //Acceleration in X-Direction(k1)
    QVector<double> mA_X1;
    QVector<double> mA_X2;
    QVector<double> mA_X3;
    QVector<double> mA_X4;
    QVector<double> mA_X5;
    QVector<double> mA_X6;
    //Acceleration in Y-Direction(k2)
    QVector<double> mA_Y1;
    QVector<double> mA_Y2;
    QVector<double> mA_Y3;
    QVector<double> mA_Y4;
    QVector<double> mA_Y5;
    QVector<double> mA_Y6;
    //Acceleration in Z-Direction(k3)
    QVector<double> mA_Z1;
    QVector<double> mA_Z2;
    QVector<double> mA_Z3;
    QVector<double> mA_Z4;
    QVector<double> mA_Z5;
    QVector<double> mA_Z6;
    //Angular-Velocity in X-Direction(k1)
    QVector<double> mW_X1;
    QVector<double> mW_X2;
    QVector<double> mW_X3;
    QVector<double> mW_X4;
    QVector<double> mW_X5;
    QVector<double> mW_X6;
    //Angular-Velocity in Y-Direction(k2)
    QVector<double> mW_Y1;
    QVector<double> mW_Y2;
    QVector<double> mW_Y3;
    QVector<double> mW_Y4;
    QVector<double> mW_Y5;
    QVector<double> mW_Y6;
    //Angular-Velocity in Z-Direction(k3)
    QVector<double> mW_Z1;
    QVector<double> mW_Z2;
    QVector<double> mW_Z3;
    QVector<double> mW_Z4;
    QVector<double> mW_Z5;
    QVector<double> mW_Z6;
};

#endif // CSENSORCALIBWIDGET_H
