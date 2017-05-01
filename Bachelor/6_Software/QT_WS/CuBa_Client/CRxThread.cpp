#include "CRxThread.h"
#include <unistd.h>
#include <iostream>
#include <QVector>

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
                case EEvent::COMPLQR_1D_DATA:
                {
                    QVector<double> data;
                    Float32* ptr = reinterpret_cast<Float32*>(msg.getDataPtr());
                    data.append(static_cast<double>(ptr[0]));
                    data.append(static_cast<double>(ptr[1]));
                    data.append(static_cast<double>(ptr[2]));
                    data.append(static_cast<double>(ptr[3]));
                    emit CompLQR1DDataReceivedSIG(time, data);
                    break;
                }
                case EEvent::PHIOBSLQR_1D_DATA:
                {
                    QVector<double> data;
                    Float32* ptr = reinterpret_cast<Float32*>(msg.getDataPtr());
                    data.append(static_cast<double>(ptr[0]));
                    data.append(static_cast<double>(ptr[1]));
                    data.append(static_cast<double>(ptr[2]));
                    data.append(static_cast<double>(ptr[3]));
                    emit PhiObsLQR1DDataReceiveSIG(time, data);
                    break;
                }
                case EEvent::FULLOBSLQR_1D_DATA:
                {
                    QVector<double> data;
                    Float32* ptr = reinterpret_cast<Float32*>(msg.getDataPtr());
                    data.append(static_cast<double>(ptr[0]));
                    data.append(static_cast<double>(ptr[1]));
                    data.append(static_cast<double>(ptr[2]));
                    data.append(static_cast<double>(ptr[3]));
                    emit FullObsLQR1DDataReceivedSIG(time, data);
                    break;
                }
                case EEvent::COMPLQR_3D_PHI:
                {
                    QVector<double> data;
                    Float32* ptr = reinterpret_cast<Float32*>(msg.getDataPtr());
                    data.append(static_cast<double>(ptr[0]));
                    data.append(static_cast<double>(ptr[1]));
                    emit CompLQR3DPhiReceivedSIG(time, data);
                    break;
                }
                case EEvent::COMPLQR_3D_UK:
                {
                    QVector<double> data;
                    Float32* ptr = reinterpret_cast<Float32*>(msg.getDataPtr());
                    data.append(static_cast<double>(ptr[0]));
                    data.append(static_cast<double>(ptr[1]));
                    data.append(static_cast<double>(ptr[2]));
                    emit CompLQR3DUKReceivedSIG(time, data);
                    break;
                }
                case EEvent::COMPLQR_3D_UR:
                {
                    QVector<double> data;
                    Float32* ptr = reinterpret_cast<Float32*>(msg.getDataPtr());
                    data.append(static_cast<double>(ptr[0]));
                    data.append(static_cast<double>(ptr[1]));
                    data.append(static_cast<double>(ptr[2]));
                    emit CompLQR3DURReceivedSIG(time, data);
                    break;
                }
                case EEvent::COMPLQR_3D_TM:
                {
                    QVector<double> data;
                    Float32* ptr = reinterpret_cast<Float32*>(msg.getDataPtr());
                    data.append(static_cast<double>(ptr[0]));
                    data.append(static_cast<double>(ptr[1]));
                    data.append(static_cast<double>(ptr[2]));
                    emit CompLQR3DTMReceivedSIG(time, data);
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
void CRxThread::runEdgeBalanceSLOT()
{
    mConnectedFlag = mClient.connectToServer();
    CMessage msg(EEvent::RUN_EDGE_BALANCE);
    mClient.writeMessage(msg);
}
void CRxThread::setPhiOffsetSLOT(double offset)
{
    CMessage msg(EEvent::PHI_OFFSET);
    *reinterpret_cast<Float32*>(msg.getDataPtr()) = static_cast<Float32>(offset);
    mClient.writeMessage(msg);
}
void CRxThread::setUKOffsetSLOT(double offset)
{
    CMessage msg(EEvent::UK_OFFSET);
    *reinterpret_cast<Float32*>(msg.getDataPtr()) = static_cast<Float32>(offset);
    mClient.writeMessage(msg);
}
void CRxThread::setUROffsetSLOT(double offset)
{
    CMessage msg(EEvent::UR_OFFSET);
    *reinterpret_cast<Float32*>(msg.getDataPtr()) = static_cast<Float32>(offset);
    mClient.writeMessage(msg);
}
void CRxThread::selectControlSystemSLOT(E1DControlSystem sys)
{
    CMessage msg(EEvent::SELECT_1D_CONTROL);
    *reinterpret_cast<E1DControlSystem*>(msg.getDataPtr()) = sys;
    mClient.writeMessage(msg);
}
void CRxThread::runCornerBalanceSLOT()
{
    mConnectedFlag = mClient.connectToServer();
    CMessage msg(EEvent::RUN_CORNER_BALANCE);
    mClient.writeMessage(msg);
}
void CRxThread::reloadConfigSLOT()
{
    CMessage msg(EEvent::RELOAD_CONFIG);
    mClient.writeMessage(msg);
}
