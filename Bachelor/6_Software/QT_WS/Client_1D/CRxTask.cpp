#include "CRxTask.h"

CRxTask::CRxTask()
{

}
void CRxTask::run()
{
    mClient.connectToServer();
    CMessage msg(EEvent::RUN_SENSOR_MEASUREMENT);
    mClient.writeMessage(msg);

    while(true)
    {
        if(mClient.readMessage(msg))
        {
            EEvent event = msg.getEvent();
            if(EEvent::TX_SENSOR_DATA == event)
            {
                CSensorData sensorData = *reinterpret_cast<CSensorData*>(msg.getDataPtr());
                emit sensorDataReceived(sensorData);
            }
        }
    }
}
