#ifndef CRXTASK_H
#define CRXTASK_H
#include "IRunnable.h"
#include "CClient.h"
#include <QThread>

class CRxTask : public QThread
{
    Q_OBJECT
public:
    void run() override;
signals:
    void sensorDataReceived(CSensorData);
public:
    CRxTask();
    CRxTask(const CRxTask&) = delete;
    CRxTask& operator=(const CRxTask&) = delete;
    ~CRxTask() = default;
private:
    CClient mClient;
};

#endif // CRXTASK_H
