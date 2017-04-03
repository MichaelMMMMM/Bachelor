#include "CWebSocket.h"

CWebSocket::CWebSocket(int port) : WebSocketServer(port)
{
	Util::log("WebSocketServer is listening on Port: " + Util::toString(port) );
}
CWebSocket::~CWebSocket()
{
	Util::log("CWebSocket Destructor");
}
void CWebSocket::onConnect(int socketID)
{
	Util::log("New connect on SocketID: " + Util::toString(socketID) );
}
void CWebSocket::onMessage(int socketID, const std::string& data)
{
	Util::log("Message received on SocketID: " + Util::toString(socketID) + " -> " + data);
}
void CWebSocket::onDisconnect(int socketID)
{
	Util::log("Disconnect on SocketID: " + Util::toString(socketID) );
}
void CWebSocket::onError(int socketID, const std::string& msg)
{
	Util::log("Error on SocketID: " + Util::toString(socketID)  + " -> " + msg);
}
