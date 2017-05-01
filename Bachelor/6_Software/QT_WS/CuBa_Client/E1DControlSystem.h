#ifndef E1DCONTROLSYSTEM_H
#define E1DCONTROLSYSTEM_H
#include "Global.h"

enum class E1DControlSystem : UInt32
{
    COMP_LQR 		= 0U,
    PHI_OBS_LQR 	= 1U,
    FULL_OBS_LQR	= 2U
};

#endif
