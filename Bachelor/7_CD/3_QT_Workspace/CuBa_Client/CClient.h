#ifndef CCLIENT_H
#define CCLIENT_H
#include "CMessage.h"

class CClient
{
public:
    bool connectToServer();
    void disconnect();
    bool writeMessage(CMessage& msg);
    bool readMessage(CMessage& msg);
public:
    CClient();
    CClient(const CClient&) = delete;
    CClient& operator=(const CClient&) = delete;
    ~CClient();
private:
    int mSockFD;

};


#endif // CCLIENT_H
