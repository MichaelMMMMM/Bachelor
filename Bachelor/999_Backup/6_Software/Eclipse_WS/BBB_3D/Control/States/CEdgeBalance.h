/**
 * @file	CEdgeBalance.h
 * @author	Michael Meindl
 * @date	14.03.2017
 * @brief	State to handle balancing on an edge.
 */
#ifndef CEDGEBALANCE_H
#define CEDGEBALANCE_H
#include "CEdgeBalanceAction.h"
#include "AState.h"

class CEdgeBalance : public AState
{
public:
	bool dispatch(CMessage& msg) override;
	bool tryEntry(CMessage& msg, AState*& statePtr) override;
	void onEntry() override;
	void onExit() override;

	bool onDefault(CMessage& msg);
	bool onIdle(CMessage& msg);
	bool onControl(CMessage& msg);

	using State = bool (CEdgeBalance::*)(CMessage&);
public:
	CEdgeBalance();
	CEdgeBalance(const CEdgeBalance&) = delete;
	CEdgeBalance& operator=(const CEdgeBalance&) = delete;
	~CEdgeBalance() = default;
private:
	CEdgeBalanceAction mAction;
	State 			   mState;

	static constexpr State sDefault = static_cast<State>(&CEdgeBalance::onDefault);
	static constexpr State sIdle	= static_cast<State>(&CEdgeBalance::onIdle);
	static constexpr State sControl = static_cast<State>(&CEdgeBalance::onControl);
};

#endif
