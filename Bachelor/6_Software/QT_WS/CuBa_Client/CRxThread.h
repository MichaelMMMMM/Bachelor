#ifndef CRXTHREAD_H
#define CRXTHREAD_H
#include "CClient.h"
#include "CMPUData.h"
#include "CADCData.h"
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
public slots:
    void endMeasurement();
    void runSensorCalibration();
    void runADCCalibrationSLOT();
private:
    CClient mClient;
    bool mConnectedFlag;
};

#endif // CRXTHREAD_H
