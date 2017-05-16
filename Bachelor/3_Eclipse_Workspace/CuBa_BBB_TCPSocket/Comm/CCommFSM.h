/**
 * @file	CCommFSM.h
 * @author	Michael Meindl
 * @date	6.10.2016
 */
#ifndef CCOMMFSM_H
#define CCOMMFSM_H
#include "TFSMBase.h"
#include "CCommAction.h"

using CCommFSMBase = TFSMBase<CCommAction>;

class CCommFSM : public CCommFSMBase
{
public:
	bool dispatch(CMessage& msg);
	bool onInitial(CMessage& msg) override;
	bool onStandby(CMessage& msg);
	bool onRunning(CMessage& msg);
public:
	CCommFSM();
	CCommFSM(const CCommFSM&) = delete;
	CCommFSM& operator=(const CCommFSM&) = delete;
	~CCommFSM() = default;
private:
	static constexpr StatePtr sStandby =
			static_cast<StatePtr>(&CCommFSM::onStandby);
	static constexpr StatePtr sRunning =
			static_cast<StatePtr>(&CCommFSM::onRunning);
};
#endif
