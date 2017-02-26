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
    PHI_NONE 		= 0,
    PHI_COMP 		= 1,
    PHI__D_NONE 	= 2,
    PHI__D_PT1_5HZ 	= 3,
    PHI__D_PT1_10HZ = 4,
    PSI__D_NONE     = 5,
    PSI__D_PT1_5HZ  = 6,
    PSI__D_PT1_10HZ = 7
};

#endif
