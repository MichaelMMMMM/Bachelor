/**
 * @file	CCommAction.cpp
 * @author  Michael Meindl
 * @date	6.10.2016
 */
#include "CCommAction.h"
#include <iostream>
using namespace std;

CCommAction::CCommAction() : mServer(),
						     mReceiveTask(mServer),
							 mReceiveThread(&mReceiveTask, CThread::PRIORITY_NORM)
{
	mReceiveThread.start();
}
void CCommAction::entryStandby()
{
	cout << "[*] Comm-FSM: Entering Standby" << endl;
}
void CCommAction::exitStandby()
{
	cout << "[*] Comm-FSM: Exiting Standby" << endl;
}
void CCommAction::entryRunning()
{
	cout << "[*] Comm-FSM: Entering Running" << endl;
}
void CCommAction::exitRunning()
{
	cout << "[*] Comm-FSM: Exiting Running" << endl;
}
void CCommAction::transmitMessage(CMessage& msg)
{
	if(mServer.transmitMessage(msg) == false)
	{
		cout << "[*] Comm-FSM: Failed to transmit TCP/IP-Message" << endl;
	}
}
