/**
 * @file	TLQR.cpp
 * @author	Michael Meindl
 * @date	16.03.2017
 * @brief	Template specialization for TLQR.
 */
#include "TLQR.h"

template<>
TLQR<9U, 3U>::TLQR() : mK("/root/control_data/3D_K_mat.csv")
{

}
template<>
TLQR<3U, 1U>::TLQR() : mK("/root/control_data/1D_K_mat.csv")
{

}
