/**
 * @file	CLQRTest.h
 * @author	Michael Meindl
 * @date	16.02.2017
 * @brief	State to handle the Controller.
 */
#ifndef CLQRTEST_H
#define CLQRTEST_H
#include "AState.h"
#include "CLQRTestAction.h"

class CLQRTest : public AState
{
public:
	bool dispatch(CMessage& msg) override;
	bool tryEntry(CMessage& msg, AState*& statePtr) override;
	void onEntry() override;
	void onExit() override;
public:
	CLQRTest() = default;
	CLQRTest(const CLQRTest&) = delete;
	CLQRTest& operator=(const CLQRTest&) = delete;
	~CLQRTest() = default;
private:
	CLQRTestAction mAction;
};

#endif
