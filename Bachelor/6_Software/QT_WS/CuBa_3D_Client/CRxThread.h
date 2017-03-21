#ifndef CRXTHREAD_H
#define CRXTHREAD_H
#include "CClient.h"
#include "CMPUData.h"
#include "CTorqueData.h"
#include "CADCData.h"
#include "CStateData.h"
#include <QThread>

class CRxThread : public QThread
{
    Q_OBJECT
public:
    explicit CRxThread(QObject *parent = 0);
    void run() override;
signals:
    void sensor1DataReceived(const CMPUData& data);
    void sensor2DataReceived(const CMPUData& data);
    void sensor3DataReceived(const CMPUData& data);
    void sensor4DataReceived(const CMPUData& data);
    void sensor5DataReceived(const CMPUData& data);
    void sensor6DataReceived(const CMPUData& data);
    void adcDataReceived(const CADCData& data);
    void gDataReceived(const CGData& data);
    void ukDataReceived(const CUKData& data);
    void urDataReceived(const CURData& data);
    void torqueDataReceived(const CTorqueData& data);
    void lqr1DDataReceivedSIG(const Data1D& data);
    void lqg1DDataReceivedSIG(const Data1D& data);
public slots:
    void endMeasurement();
    void runSensorCalibration();
    void runADCCalibration();
    void runControlTest();
    void runEdgeBalanceSLOT();
    void setTorque(const CTorqueData& data);
    void setCompFilterFlag(bool flag);
    void setOffsetCorrectionFlag(bool flag);
    void setLQRFlag(bool flag);
private:
    CClient mClient;
    bool mConnectedFlag;
};

#endif // CRXTHREAD_H
