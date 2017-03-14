#ifndef TFSM_H
#define TFSM_H
#include "TLinHierarchy.h"
#include "AState.h"
#include "CControlAction.h"

template<class StateList>
class TFSM : public AState
{
public:
	bool dispatch(CMessage& msg) override;
	bool tryEntry(CMessage& msg, AState*& statePtr) override;
	void onEntry() override;
	void onExit() override;
	bool onStandby(CMessage& msg);
public:
	TFSM();
	TFSM(const TFSM&) = delete;
	TFSM& operator=(const TFSM&) = delete;
	~TFSM() = default;
private:
	AState* mStatePtr;
	StateList mStateList;
	CControlAction mAction;
};

template<class StateList>
TFSM<StateList>::TFSM() : mStatePtr(nullptr)
{

}
template<class StateList>
bool TFSM<StateList>::onStandby(CMessage& msg)
{
	bool consumed = this->tryEntry(msg, mStatePtr);

	if(consumed == true)
	{
		mAction.exitStandby();
		mStatePtr->onEntry();
	}
	else
	{
		//Unhandled event
	}
	return consumed;
}
template<class StateList>
bool TFSM<StateList>::dispatch(CMessage& msg)
{
	bool consumed = false;
	if(mStatePtr == nullptr)
	{
		consumed = this->onStandby(msg);
	}
	else
	{
		consumed = mStatePtr->dispatch(msg);
	}

	if(consumed == false)
	{
		EEvent event = msg.getEvent();
		if(EEvent::CLIENT_DISCONNECT == event)
		{
			mStatePtr->onExit();
			mStatePtr = nullptr;
			mAction.entryStandby();
		}
	}

	//RTC
	while(sQueueSize > 0U)
	{
		CMessage internalMessage(sInternalQueue);
		sQueueSize = 0U;
		consumed = mStatePtr->dispatch(internalMessage);
	}

	return consumed;
}
template<class StateList>
bool TFSM<StateList>::tryEntry(CMessage& msg, AState*& statePtr)
{
	return mStateList.tryEntry(msg, statePtr);
}
template<class StateList>
void TFSM<StateList>::onEntry()
{

}
template<class StateList>
void TFSM<StateList>::onExit()
{

}
#endif
