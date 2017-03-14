/**
 * @file	AState.cpp
 * @author	Michael Meindl
 * @date	14.03.2017
 * @brief	Init of the static member variables.
 */
#include "AState.h"

EEvent AState::sInternalQueue = EEvent::DEFAULT_IGNORE;
UInt32 AState::sQueueSize     = 0U;
