/**
 * @file	CCornerBalance.h
 * @author	Michael Meindl
 * @date	20.04.2017
 * @brief	State to handle Corner-Balancing.
 */
#ifndef CCORNERBALANCE_H
#define CCORNERBALANCE_H
#include "AState.h"
#include "CCornerBalanceAction.h"

class CCornerBalance : public AState
{
public:
	bool dispatch(CMessage& msg) override;
	bool tryEntry(CMessage& msg, AState*& statePtr) override;
	void onEntry() override;
	void onExit() override;
	bool onInitial(CMessage& msg);
	bool onIdle(CMessage& msg);
	bool onBalance(CMessage& msg);
public:
	CCornerBalance();
	CCornerBalance(const CCornerBalance&) = delete;
	CCornerBalance& operator=(const CCornerBalance&) = delete;
	~CCornerBalance() = default;
private:
	using StatePtr = bool(CCornerBalance::*)(CMessage&);
private:
	CCornerBalanceAction mAction;
	StatePtr			 mState;

	static constexpr StatePtr sInitial = static_cast<StatePtr>(&CCornerBalance::onInitial);
	static constexpr StatePtr sIdle	   = static_cast<StatePtr>(&CCornerBalance::onIdle);
	static constexpr StatePtr sBalance = static_cast<StatePtr>(&CCornerBalance::onBalance);
};

#endif
