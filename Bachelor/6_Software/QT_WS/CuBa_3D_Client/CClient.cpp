#include "CClient.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstdlib>
#include <strings.h>

using namespace std;

CClient::CClient() : mSockFD(-1)
{

}
CClient::~CClient()
{
    if(mSockFD >= 0)
    {
        close(mSockFD);
    }
}

bool CClient::connectToServer()
{
    mSockFD = socket(AF_INET, SOCK_STREAM, 0);
    if(mSockFD < 0)
    {
        cerr << "(CClient::CClient) Failed to create socket!" << endl;
    }

    struct sockaddr_in serv_addr;
    bzero((char*) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family        = AF_INET;
    serv_addr.sin_addr.s_addr   = inet_addr("192.168.9.1");
    serv_addr.sin_port          = htons(40000);

    if(connect(mSockFD, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
    {
        cerr << "(CClient::CClient) Failed to connect to server!" << endl;
        return false;
    }
    return true;
}
void CClient::disconnect()
{
    shutdown(mSockFD, SHUT_RDWR);
    close(mSockFD);
}

bool CClient::writeMessage(CMessage& msg)
{
    char* bytePtr = reinterpret_cast<char*>(&msg);

    unsigned int bytesWritten = 0;
    int ret = -1;
    while(bytesWritten < sizeof(msg))
    {
        ret = write(mSockFD, &(bytePtr[bytesWritten]), sizeof(msg)-bytesWritten);
        if(ret < 0)
        {
            cerr << "(CClient::writeFloat) Failed to write bytes" << endl;
            return false;
        }
        bytesWritten += ret;
    }
    return true;
}
bool CClient::readMessage(CMessage& msg)
{
    char rxData[sizeof(msg)] = {0};

    unsigned int bytesReceived = 0;
    int ret = -1;
    while(bytesReceived < sizeof(msg))
    {
        ret = read(mSockFD, &(rxData[bytesReceived]), sizeof(msg)-bytesReceived);
        if(ret < 0)
        {
            cerr << "(CClient::readFloat) Failed to read bytes" << endl;
            return false;
        }
        bytesReceived += ret;
    }
    msg = *reinterpret_cast<CMessage*>(rxData);
    return true;
}
