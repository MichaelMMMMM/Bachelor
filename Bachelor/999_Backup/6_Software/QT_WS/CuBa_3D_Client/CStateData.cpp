/**
 * @file	CStateData.cpp
 * @author	Michael Meindl
 * @date	16.02.2017
 * @brief	Metho definitions for CStateData, CGData, CUKData and CURData.
 */
#include "CStateData.h"
#include <iostream>
#include <iomanip>
using namespace std;

CGData::CGData() : mTime(0.0F), mG_k1(0.0F), mG_k2(0.0F), mG_k3(0.0F)
{

}
void CGData::display()
{
	cout << setw(15) << "G-Vector: " <<
			setw(8)  << "k1: " << setw(8)  << mG_k1 <<
			setw(8)  << "k2: " << setw(8)  << mG_k2 <<
			setw(8)  << "k3: " << setw(8)  << mG_k3 << endl;
}
CUKData::CUKData() : mTime(0.0F), mUK_k1(0.0F), mUK_k2(0.0F), mUK_k3(0.0F)
{

}
void CUKData::display()
{
	cout << setw(15) << "UK-Vector: " <<
			setw(8)  << "k1: " << setw(8) << mUK_k1 <<
			setw(8)  << "k2: " << setw(8) << mUK_k2 <<
			setw(8)  << "k3: " << setw(8) << mUK_k3 << endl;
}
CURData::CURData() : mTime(0.0F), mUR_k1(0.0F), mUR_k2(0.0F), mUR_k3(0.0F)
{

}
void CURData::display()
{
	cout << setw(15) << "UR-Vector: " <<
			setw(8)  << "k1: " << setw(8) << mUR_k1 <<
			setw(8)  << "k2: " << setw(8) << mUR_k2 <<
			setw(8)  << "k3: " << setw(8) << mUR_k3 << endl;
}
void CStateData::display()
{
	cout << "--------------- State-Data ---------------" << endl;
	mGData.display();
	mUKData.display();
	mURData.display();
}
