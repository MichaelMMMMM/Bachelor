/**
 * @file	CServerTask.h
 * @author	Michael Meindl
 * @date	4.4.2017
 * @brief	Runnable object to execute the Server-Task.
 */
#ifndef CSERVERTASK_H
#define CSERVERTASK_H
#include "IRunnable.h"
#include "CWebSocket.h"
#include <string>

class CServerTask : public IRunnable
{
public:
	void init() override;
	void run() override;
	void send(const std::string& msg);
public:
	explicit CServerTask();
	CServerTask(const CServerTask&) = delete;
	CServerTask& operator=(const CServerTask&) = delete;
	~CServerTask() = default;
private:
	CWebSocket mSocket;
};

#endif
