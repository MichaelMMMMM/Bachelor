/**
 * @file	CControlActionBase.cpp
 * @author	Michael Meindl
 * @date	5.1.2017
 * @brief	Method defitions for CControlActionBase.
 */
#include "CControlActionBase.h"

CHardware CControlActionBase::sHardware;
CTimerTask CControlActionBase::sTimerTask;
CThread	CControlActionBase::sTimerThread(&CControlActionBase::sTimerTask,
										 CThread::PRIORITY_NORM);
CProxy& CControlActionBase::sProxy = CProxy::getInstance();
