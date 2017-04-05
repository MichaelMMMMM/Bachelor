#ifndef CWEBSOCKET_H
#define CWEBSOCKET_H
#include <string>
#include "Util.h"
#include "WebSocketServer.h"

class CWebSocket : public WebSocketServer
{
public:
	void onConnect(int socketID) override;
	void onMessage(int socketID, const std::string& data) override;
	void onDisconnect(int socketID) override;
	void onError(int socketID, const std::string& message) override;
public:
	CWebSocket(int port);
	CWebSocket(const CWebSocket&) = delete;
	CWebSocket& operator=(const CWebSocket&) = delete;
	virtual ~CWebSocket();

};

#endif
