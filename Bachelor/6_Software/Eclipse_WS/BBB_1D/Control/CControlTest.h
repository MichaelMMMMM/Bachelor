/**
 * @file	CControlTest.h
 * @author	Michael Meindl
 * @date	8.1.2017
 * @brief	State-Class for the control test.
 */
#ifndef CCONTROLTEST_H
#define CCONTROLTEST_H
#include "AState.h"
#include "CControlTestAction.h"

class CControlTest : public AState
{
private:
	using StatePtr = bool(CControlTest::*)(CMessage&);
public:
	bool dispatch(CMessage& msg) override;
	bool tryEntry(CMessage& msg, AState*& statePtr) override;
	void onEntry() override;
	void onExit() override;
	bool onIdle(CMessage& msg);
	bool onBalance(CMessage& msg);
public:
	CControlTest();
	CControlTest(const CControlTest&) = delete;
	CControlTest& operator=(const CControlTest&) = delete;
	~CControlTest() = default;
private:
	static constexpr StatePtr sIdle 	= static_cast<StatePtr>(&CControlTest::onIdle);
	static constexpr StatePtr sBalance 	= static_cast<StatePtr>(&CControlTest::onBalance);
	CControlTestAction mAction;
	StatePtr mState;
};

#endif
