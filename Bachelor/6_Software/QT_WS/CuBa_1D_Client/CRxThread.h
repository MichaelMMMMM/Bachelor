#ifndef CRXTHREAD_H
#define CRXTHREAD_H
#include "CSensorData.h"
#include "CPhi.h"
#include "CPhi__d.h"
#include "CPsi__d.h"
#include "CClient.h"
#include <QThread>

class CRxThread : public QThread
{
    Q_OBJECT
public:
    explicit CRxThread(QObject *parent = 0);
    void run() override;

signals:
    void sensorDataReceived(const CSensorData& data);
    void adcDataReceived(const CSensorData& data);
    void phiDataReceived(const CPhi& data);
    void phi__dDataReceived(const CPhi__d& data);
    void psi__dDataReceived(const CPsi__d& data);
public slots:
    void endMeasurement();
    void runSensorMeasurement();
    void runADCMeasurement();
    void setRPM(float rpm);
    void runControlTest();
    void phiOffsetChanged(float offset);
    void phi__dOffsetChanged(float offset);
    void psi__dOffsetChanged(float offset);
    void filterChanged(EFilter filter);
    void highpassFlagChanged(bool flag);
    void lqrFlagChanged(bool flag);
private:
    CClient mClient;
    bool mConnectedFlag;
};

#endif // CRXTHREAD_H
