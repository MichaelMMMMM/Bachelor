#include "CWebSocket.h"
#include <iostream>
#include <cmath>
#include "CThread.h"
#include "CServerTask.h"

int main()
{
	CServerTask mTask;
	CThread mServerThread(&mTask, CThread::PRIORITY_NORM);
	mServerThread.start();

	double i = 0.0;
	constexpr double ta = 0.02;
	while(true)
	{
		i += ta;
		double ax = sin(i);
		double ay = cos(i);
		double az = 2*sin(i);
		double wx = 2*cos(i);
		double wy = 3*sin(i);
		double wz = 3*cos(i);

		string msg = "{\"mEvent\": \"Sensor1Data\", \"mTime\":" + Util::toString(i) +
				     ", \"mData\": { \"mA_x\":" + Util::toString(ax) +
					 ", \"mA_y\":" + Util::toString(ay) +
					 ", \"mA_z\":" + Util::toString(az) +
					 ", \"mW_x\":" + Util::toString(wx) +
					 ", \"mW_y\":" + Util::toString(wy) +
					 ", \"mW_z\":" + Util::toString(wz) + "} }";
		mTask.send(msg);
		msg = "{\"mEvent\": \"Sensor2Data\", \"mTime\":" + Util::toString(i) +
				     ", \"mData\": { \"mA_x\":" + Util::toString(ax) +
					 ", \"mA_y\":" + Util::toString(ay) +
					 ", \"mA_z\":" + Util::toString(az) +
					 ", \"mW_x\":" + Util::toString(wx) +
					 ", \"mW_y\":" + Util::toString(wy) +
					 ", \"mW_z\":" + Util::toString(wz) + "} }";
		mTask.send(msg);
		msg = "{\"mEvent\": \"Sensor3Data\", \"mTime\":" + Util::toString(i) +
				     ", \"mData\": { \"mA_x\":" + Util::toString(ax) +
					 ", \"mA_y\":" + Util::toString(ay) +
					 ", \"mA_z\":" + Util::toString(az) +
					 ", \"mW_x\":" + Util::toString(wx) +
					 ", \"mW_y\":" + Util::toString(wy) +
					 ", \"mW_z\":" + Util::toString(wz) + "} }";
		mTask.send(msg);
		msg = "{\"mEvent\": \"Sensor4Data\", \"mTime\":" + Util::toString(i) +
				     ", \"mData\": { \"mA_x\":" + Util::toString(ax) +
					 ", \"mA_y\":" + Util::toString(ay) +
					 ", \"mA_z\":" + Util::toString(az) +
					 ", \"mW_x\":" + Util::toString(wx) +
					 ", \"mW_y\":" + Util::toString(wy) +
					 ", \"mW_z\":" + Util::toString(wz) + "} }";
		mTask.send(msg);
		msg = "{\"mEvent\": \"Sensor5Data\", \"mTime\":" + Util::toString(i) +
				     ", \"mData\": { \"mA_x\":" + Util::toString(ax) +
					 ", \"mA_y\":" + Util::toString(ay) +
					 ", \"mA_z\":" + Util::toString(az) +
					 ", \"mW_x\":" + Util::toString(wx) +
					 ", \"mW_y\":" + Util::toString(wy) +
					 ", \"mW_z\":" + Util::toString(wz) + "} }";
		mTask.send(msg);
		msg = "{\"mEvent\": \"Sensor6Data\", \"mTime\":" + Util::toString(i) +
				     ", \"mData\": { \"mA_x\":" + Util::toString(ax) +
					 ", \"mA_y\":" + Util::toString(ay) +
					 ", \"mA_z\":" + Util::toString(az) +
					 ", \"mW_x\":" + Util::toString(wx) +
					 ", \"mW_y\":" + Util::toString(wy) +
					 ", \"mW_z\":" + Util::toString(wz) + "} }";
		mTask.send(msg);
		usleep(static_cast<int>(ta*1000000.0));
	}

	mServerThread.join();

	CWebSocket socket(18000);
	std::cout << "Socket is up and running" << std::endl;

	while(true)
	{
		i += 0.02;

		double mySin = sin(i);
		double myCos = cos(i);


		string msg = "{\"time\":" + Util::toString(i) + ",\"phi1\":" + Util::toString(mySin) + ",\"phi2\":" + Util::toString(myCos) + "}";


		if(socket.getNumberOfConnections() > 0)
		{
			std::cout << msg << std::endl;
			socket.broadcast(msg);
		}

		socket.TriggerAllProtocolsCallback();
		socket.wait(500);
		usleep(20000);
	}
}
