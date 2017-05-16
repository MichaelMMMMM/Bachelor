/**
 * @file	CEdgeBalance.h
 * @author	Michael Meindl
 * @date	18.04.2017
 * @brief	State to handle the edge balancing.
 */
#ifndef CEDGEBALANCE_H
#define CEDGEBALANCE_H
#include "AState.h"
#include "CEdgeBalanceAction.h"

class CEdgeBalance : public AState
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
	CEdgeBalance();
	CEdgeBalance(const CEdgeBalance&) = delete;
	CEdgeBalance& operator=(const CEdgeBalance&) = delete;
	~CEdgeBalance() = default;
private:
	using StatePtr = bool(CEdgeBalance::*)(CMessage&);
private:
	static constexpr StatePtr sInitial = static_cast<StatePtr>(&CEdgeBalance::onInitial);
	static constexpr StatePtr sIdle    = static_cast<StatePtr>(&CEdgeBalance::onIdle);
	static constexpr StatePtr sBalance = static_cast<StatePtr>(&CEdgeBalance::onBalance);

	StatePtr 		   mState;
	CEdgeBalanceAction mAction;
};

#endif
