/**
 * @file	TFSMBase.h
 * @author	Michael Meindl
 * @date	5.10.2016
 */
#ifndef TFSMBASE_H
#define TFSMBASE_H
#include "Global.h"
#include "CMessage.h"

template<typename Action>
class TFSMBase
{
public:
	bool dispatch(CMessage& msg);
	void entry();
	void exit();
protected:
	using StatePtr = bool (TFSMBase::*)(CMessage&);
	virtual bool onInitial(CMessage& msg) = 0;
public:
	TFSMBase();
	TFSMBase(const TFSMBase&) = delete;
	TFSMBase& operator=(const TFSMBase&) = delete;
	virtual ~TFSMBase() = default;
protected:
	static constexpr StatePtr sInitial = static_cast<StatePtr>(&TFSMBase<Action>::onInitial);
	static Action sAction;
	static CMessage sInternalQueue;
	static Int32 sQueueSize;
	StatePtr mState;
};

template<typename Action>
Action TFSMBase<Action>::sAction{};

template<typename Action>
CMessage TFSMBase<Action>::sInternalQueue{};

template<typename Action>
Int32 TFSMBase<Action>::sQueueSize = 0;

template<typename Action>
void TFSMBase<Action>::entry()
{
	CMessage msg(EEvent::INIT);
	this->dispatch(msg);
}
template<typename Action>
void TFSMBase<Action>::exit()
{
	CMessage msg(EEvent::EXIT);
	this->dispatch(msg);
}
template<typename Action>
bool TFSMBase<Action>::dispatch(CMessage& msg)
{
	return (this->*mState)(msg);
}
template<typename Action>
TFSMBase<Action>::TFSMBase() : mState(sInitial)
{

}
#endif
