#include "CRxThread.h"
#include <unistd.h>
#include <iostream>

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
                double time  = static_cast<double>(msg.getTime());
                switch(event)
                {
                case EEvent::SENSOR1DATA:
                {
                    CMPUData data = *reinterpret_cast<CMPUData*>(msg.getDataPtr());
                    emit sensor1DataReceived(time, data);
                    break;
                }
                case EEvent::SENSOR2DATA:
                {
                    CMPUData data = *reinterpret_cast<CMPUData*>(msg.getDataPtr());
                    emit sensor2DataReceived(time, data);
                    break;
                }
                case EEvent::SENSOR3DATA:
                {
                    CMPUData data = *reinterpret_cast<CMPUData*>(msg.getDataPtr());
                    emit sensor3DataReceived(time, data);
                    break;
                }
                case EEvent::SENSOR4DATA:
                {
                    CMPUData data = *reinterpret_cast<CMPUData*>(msg.getDataPtr());
                    emit sensor4DataReceived(time, data);
                    break;
                }
                case EEvent::SENSOR5DATA:
                {
                    CMPUData data = *reinterpret_cast<CMPUData*>(msg.getDataPtr());
                    emit sensor5DataReceived(time, data);
                    break;
                }
                case EEvent::SENSOR6DATA:
                {
                    CMPUData data = *reinterpret_cast<CMPUData*>(msg.getDataPtr());
                    emit sensor6DataReceived(time, data);
                    break;
                }
                case EEvent::ADCDATA:
                {
                    CADCData data = *reinterpret_cast<CADCData*>(msg.getDataPtr());
                    emit adcDataReceivedSIG(time, data);
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
void CRxThread::runADCCalibrationSLOT()
{
    mConnectedFlag = mClient.connectToServer();
    CMessage msg(EEvent::RUN_ADC_CALIBRATION);
    mClient.writeMessage(msg);
}
