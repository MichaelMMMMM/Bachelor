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
                if(EEvent::TX_SENSOR_DATA == event)
                {
                    CSensorData data = *reinterpret_cast<CSensorData*>(msg.getDataPtr());
                    emit sensorDataReceived(data);
                    emit adcDataReceived(data);
                }
                else if(EEvent::TX_PHI_DATA == event)
                {
                    CPhi data = *reinterpret_cast<CPhi*>(msg.getDataPtr());
                    emit phiDataReceived(data);
                }
                else if(EEvent::TX_PHI__D_DATA == event)
                {
                    CPhi__d data = *reinterpret_cast<CPhi__d*>(msg.getDataPtr());
                    emit phi__dDataReceived(data);
                }
                else if(EEvent::TX_PSI__D_DATA == event)
                {
                    CPsi__d data = *reinterpret_cast<CPsi__d*>(msg.getDataPtr());
                    emit psi__dDataReceived(data);
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
}
void CRxThread::runSensorMeasurement()
{
    mConnectedFlag = mClient.connectToServer();
    CMessage msg(EEvent::RUN_SENSOR_MEASUREMENT);
    mClient.writeMessage(msg);
}
void CRxThread::runADCMeasurement()
{
    mConnectedFlag = mClient.connectToServer();
    CMessage msg(EEvent::RUN_ADC_MEASUREMENT);
    mClient.writeMessage(msg);
}
void CRxThread::setRPM(float rpm)
{
    CMessage msg(EEvent::SET_TORQUE);
    *reinterpret_cast<float*>(msg.getDataPtr()) = rpm;
    mClient.writeMessage(msg);
}
void CRxThread::runControlTest()
{
    mConnectedFlag = mClient.connectToServer();
    CMessage msg(EEvent::RUN_CONTROL_TEST);
    mClient.writeMessage(msg);
}
void CRxThread::phiOffsetChanged(float offset)
{
    CMessage msg(EEvent::SET_PHI_OFFSET);
    *reinterpret_cast<float*>(msg.getDataPtr()) = offset;
    mClient.writeMessage(msg);
}
void CRxThread::phi__dOffsetChanged(float offset)
{
    CMessage msg(EEvent::SET_PHI__D_OFFSET);
    *reinterpret_cast<float*>(msg.getDataPtr()) = offset;
    mClient.writeMessage(msg);
}
void CRxThread::psi__dOffsetChanged(float offset)
{
    CMessage msg(EEvent::SET_PSI__D_OFFSET);
    *reinterpret_cast<float*>(msg.getDataPtr()) = offset;
    mClient.writeMessage(msg);
}
void CRxThread::filterChanged(EFilter filter)
{
    CMessage msg(EEvent::SET_FILTER);
   *reinterpret_cast<EFilter*>(msg.getDataPtr()) = filter;
    mClient.writeMessage(msg);
}
void CRxThread::highpassFlagChanged(bool flag)
{
    CMessage msg(EEvent::SET_HIGHPASS_FLAG);
    *reinterpret_cast<bool*>(msg.getDataPtr()) = flag;
    mClient.writeMessage(msg);
}
void CRxThread::lqrFlagChanged(bool flag)
{
    CMessage msg(EEvent::SET_LQR_FLAG);
    *reinterpret_cast<bool*>(msg.getDataPtr()) = flag;
    mClient.writeMessage(msg);
}
void CRxThread::obsFlagChanged(bool flag)
{
    CMessage msg(EEvent::SET_OBS_FLAG);
    *reinterpret_cast<bool*>(msg.getDataPtr()) = flag;
    mClient.writeMessage(msg);
}
