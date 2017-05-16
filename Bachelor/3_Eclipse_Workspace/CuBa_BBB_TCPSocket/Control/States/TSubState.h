/**
 * @file	TSubState.h
 * @author	Michael Meindl
 * @date	5.4.2017
 * @brief	Template class for simple sub states.
 */
#ifndef TSUBSTATE_H
#define	TSUBSTATE_H
#include "AState.h"
#include "EEvent.h"

template<const EEvent entry, class Action>
class TSubState : public AState
{
public:
	bool tryEntry(CMessage& msg, AState*& statePtr) override;
	bool dispatch(CMessage& msg) override;
	void onEntry() override;
	void onExit() override;
public:
	TSubState() = default;
	TSubState(const TSubState&) = default;
	TSubState& operator=(const TSubState&) = default;
	~TSubState() = default;
private:
	Action mAction;
};

template<const EEvent entry, class Action>
bool TSubState<entry, Action>::tryEntry(CMessage& msg, AState*& statePtr)
{
	EEvent event = msg.getEvent();
	if(event == entry)
	{
		statePtr = this;
		return true;
	}
	return false;
}

#endif
