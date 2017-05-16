/**
 * @file	CPoly1F1.h
 * @author	Michael Meindl
 * @date	18.04.2017
 * @brief	Class to calculate polynoms of first order mapping 1:1.
 */
#ifndef CPOLY1F1_H
#define CPOLY1F1_H
#include "Global.h"
#include <string.h>

class CPoly1F1
{
public:
	Float32 calcOutput(Float32 input);
public:
	CPoly1F1(const std::string& file);
	CPoly1F1(const CPoly1F1&) = delete;
	CPoly1F1& operator=(const CPoly1F1&) = delete;
	~CPoly1F1() = default;
private:
	Float32 mP1;
	Float32 mP2;
};

#endif
