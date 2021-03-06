/**
 * @file	CPoly1F1.cpp
 * @author	Michael Meindl
 * @date	18.04.2017
 * @brief	Method definitions for CPoly1F1.
 */
#include "CPoly1F1.h"
#include <ostream>
#include <fstream>
using namespace std;

CPoly1F1::CPoly1F1(const std::string& file) : mP1(0.0F), mP2(0.0F)
{
	std::ifstream stream;
	std::string data;

	stream.open(file);

	stream >> data;
	string tmp  = data.substr(0, data.find(","));
	mP1  		= std::stof(tmp);
	data        = data.substr(data.find(",")+1);
	mP2         = std::stof(data);
}
Float32 CPoly1F1::calcOutput(Float32 input)
{
	return mP1 * input + mP2;
}
