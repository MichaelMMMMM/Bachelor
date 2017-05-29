/**
 * @file	CControlAction.h
 * @author	Michael Meindl
 * @date	5.1.2017
 * @brief	Class definitionf or the Control-FSM-Actionhandler.
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