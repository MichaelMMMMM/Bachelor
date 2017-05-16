/*
 * @file Assertion.h
 * @author Michael Meindl
 * @date 24.9.2016
 * @brief Definition of a basic assertion function
 */
#ifndef SASSERTION_H
#define SASSERTION_H
#include <string>

void sAssertion(bool assert, const std::string& errMsg, bool exitOnError);

#endif
