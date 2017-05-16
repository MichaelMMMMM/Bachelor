/**
 * @file	CControlAction.h
 * @author	Michael Meindl
 * @date	08.02.2017
 * @brief	Action-Handler for the State-Machine.
 */
#ifndef CCONTROLACTION_H
#define CCONTROLACTION_H
#include "CControlActionBase.h"

class CControlAction : public CControlActionBase
{
public:
	void entryStandby();
	void exitStandby();
public:
	CControlAction();
	CControlAction(const CControlAction&) = delete;
	CControlAction& operator=(const CControlAction&) = delete;
	~CControlAction() = default;
};

#endif
