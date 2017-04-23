#ifndef CRXTHREAD_H
#define CRXTHREAD_H
#include "CClient.h"
#include "CMPUData.h"
#include "CADCData.h"
#include "E1DControlSystem.h"
#include <QThread>

class CRxThread : public QThread
{
    Q_OBJECT
public:
    explicit CRxThread(QObject *parent = 0);
    void run() override;
signals:
    void sensor1DataReceived(double time, const CMPUData& data);
    void sensor2DataReceived(double time, const CMPUData& data);
    void sensor3DataReceived(double time, const CMPUData& data);
    void sensor4DataReceived(double time, const CMPUData& data);
    void sensor5DataReceived(double time, const CMPUData& data);
    void sensor6DataReceived(double time, const CMPUData& data);

    void adcDataReceivedSIG(double time, const CADCData& data);

    void CompLQR1DDataReceivedSIG(double time, QVector<double> data);
    void PhiObsLQR1DDataReceiveSIG(double time, QVector<double> data);
    void OffsetObsLQR1DDataReceivedSIG(double time, QVector<double> data);

    void CompLQR3DPhiReceivedSIG(double time, QVector<double> phi);
    void CompLQR3DUKReceivedSIG(double time, QVector<double> uk);
    void CompLQR3DURReceivedSIG(double time, QVector<double> ur);
    void CompLQR3DTMReceivedSIG(double time, QVector<double> tm);
public slots:
    void endMeasurement();
    void runSensorCalibration();
    void runADCCalibrationSLOT();
    void runEdgeBalanceSLOT();
    void runCornerBalanceSLOT();

    void setPhiOffsetSLOT(double);
    void setUKOffsetSLOT(double);
    void setUROffsetSLOT(double);
    void selectControlSystemSLOT(E1DControlSystem);
    void reloadConfigSLOT();
private:
    CClient mClient;
    bool mConnectedFlag;
};

#endif // CRXTHREAD_H
