/*
 * @file Assertion.cpp
 * @author Michael Meindl
 * @date 24.9.2016
 * @brief Function defintion for a basic assertion.
 */
#include "Assertion.h"
#include <iostream>
#include <cstdlib>
#include <errno.h>

extern int errno;

void sAssertion(bool assert, const char* errMsg, bool exitOnError)
{
	if(false == assert)
	{
		std::cerr << errMsg << ",errno: " << errno << std::endl;
		if(true == exitOnError)
		{
			exit(-1);
		}
	}
}
