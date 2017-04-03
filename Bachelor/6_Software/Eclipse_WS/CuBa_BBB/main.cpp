#include "CWebSocket.h"
#include <iostream>
#include <cmath>

int main()
{
	CWebSocket socket(18000);
	std::cout << "Socket is up and running" << std::endl;

	double i = 0.0;
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
		usleep(1000000);
	}
}
