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
CGData::CGData(Float32 g1, Float32 g2, Float32 g3) : mTime(0.0F), mG_k1(g1), mG_k2(g2), mG_k3(g3)
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
CUKData::CUKData(Float32 uk1, Float32 uk2, Float32 uk3) : mTime(0.0F), mUK_k1(uk1), mUK_k2(uk2), mUK_k3(uk3)
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
CURData::CURData(Float32 ur1, Float32 ur2, Float32 ur3) : mTime(0.0F), mUR_k1(ur1), mUR_k2(ur2), mUR_k3(ur3)
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
