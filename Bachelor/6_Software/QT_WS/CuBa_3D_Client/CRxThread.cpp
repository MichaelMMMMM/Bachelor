#include "CRxThread.h"
#include <unistd.h>

CRxThread::CRxThread(QObject *parent) :
    QThread(parent),
    mConnectedFlag(false)
{
}
void CRxThread::run()
{
    CMessage msg;
    while(true)
    {
        if(mConnectedFlag)
        {
            if(mClient.readMessage(msg))
            {
                EEvent event = msg.getEvent();
                switch(event)
                {
                case EEvent::SENSOR_1_DATA:
                {
                    CMPUData data = *reinterpret_cast<CMPUData*>(msg.getDataPtr());
                    emit sensor1DataReceived(data);
                    break;
                }
                case EEvent::SENSOR_2_DATA:
                {
                    CMPUData data = *reinterpret_cast<CMPUData*>(msg.getDataPtr());
                    emit sensor2DataReceived(data);
                    break;
                }
                case EEvent::SENSOR_3_DATA:
                {
                    CMPUData data = *reinterpret_cast<CMPUData*>(msg.getDataPtr());
                    emit sensor3DataReceived(data);
                    break;
                }
                case EEvent::SENSOR_4_DATA:
                {
                    CMPUData data = *reinterpret_cast<CMPUData*>(msg.getDataPtr());
                    emit sensor4DataReceived(data);
                    break;
                }
                case EEvent::SENSOR_5_DATA:
                {
                    CMPUData data = *reinterpret_cast<CMPUData*>(msg.getDataPtr());
                    emit sensor5DataReceived(data);
                    break;
                }
                case EEvent::SENSOR_6_DATA:
                {
                    CMPUData data = *reinterpret_cast<CMPUData*>(msg.getDataPtr());
                    emit sensor6DataReceived(data);
                    break;
                }
                case EEvent::ADC_DATA:
                {
                    CADCData data = *reinterpret_cast<CADCData*>(msg.getDataPtr());
                    emit adcDataReceived(data);
                    break;
                }
                default:
                    break;
                }
            }
        }
        else
        {
            sleep(1);
        }
    }
}
void CRxThread::endMeasurement()
{
    mClient.disconnect();
    mConnectedFlag = false;
}
void CRxThread::runSensorCalibration()
{
    mConnectedFlag = mClient.connectToServer();
    CMessage msg(EEvent::RUN_SENSOR_CALIBRATION);
    mClient.writeMessage(msg);
}
void CRxThread::runADCCalibration()
{
    mConnectedFlag = mClient.connectToServer();
    CMessage msg(EEvent::RUN_ADC_CALIBRATION);
    mClient.writeMessage(msg);
}
void CRxThread::setTorque(const CTorqueData &data)
{
    CMessage msg(EEvent::TORQUE_DATA);
    *reinterpret_cast<CTorqueData*>(msg.getDataPtr()) = data;
    mClient.writeMessage(msg);
}
