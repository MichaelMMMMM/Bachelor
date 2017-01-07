/**
 * @file	EFilter.h
 * @author	Michael Meindl
 * @date	29.9.2016
 * @brief	Enumeration to specify the different filter.
 */
#ifndef EFILTER_H
#define EFILTER_H
#include "Global.h"

enum class EFilter : UInt32
{
	PHI_NONE = 0,
	PHI_COMP = 1,
	PHI_KALMAN = 2,
	PHI__D_NONE = 3,
	PHI__D_KALMAN = 4,
	PSI__D_NONE = 5,
	PSI__D_MEAN4 = 6,
	PSI__D_MEAN8 = 7,
	PSI__D_MEAN16 = 8
};

#endif
