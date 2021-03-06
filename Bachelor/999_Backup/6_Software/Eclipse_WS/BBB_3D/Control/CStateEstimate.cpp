/**
 * @file	CStateEstimate.cpp
 * @author	Michael Meindl
 * @date	16.02.2017
 * @brief	Method definitions for CStateEstimate.h
 */
#include "CStateEstimate.h"
#include <cmath>

CStateEstimate::CStateEstimate() :
	mACalibArr{ {"/root/control_data/sensor1_calib_data.csv", "/root/control_data/gyro1_calib_data.csv"},
				{"/root/control_data/sensor2_calib_data.csv", "/root/control_data/gyro2_calib_data.csv"},
				{"/root/control_data/sensor3_calib_data.csv", "/root/control_data/gyro3_calib_data.csv"},
				{"/root/control_data/sensor4_calib_data.csv", "/root/control_data/gyro4_calib_data.csv"},
				{"/root/control_data/sensor5_calib_data.csv", "/root/control_data/gyro5_calib_data.csv"},
				{"/root/control_data/sensor6_calib_data.csv", "/root/control_data/gyro6_calib_data.csv"} },

	mA_X_PolyArr{ {sA_X1_P1, sA_X1_P2}, {sA_X2_P1, sA_X2_P2},
				  {sA_X3_P1, sA_X3_P2}, {sA_X4_P1, sA_X4_P2},
				  {sA_X5_P1, sA_X5_P2}, {sA_X6_P1, sA_X6_P2} },
	mA_Y_PolyArr{ {sA_Y1_P1, sA_Y1_P2}, {sA_Y2_P1, sA_Y2_P2},
				  {sA_Y3_P1, sA_Y3_P2}, {sA_Y4_P1, sA_Y4_P2},
				  {sA_Y5_P1, sA_Y5_P2}, {sA_Y6_P1, sA_Y6_P2} },
	mW_X_PolyArr{ {sW_P1, sW_X1_P2}, {sW_P1, sW_X2_P2},
				  {sW_P1, sW_X3_P2}, {sW_P1, sW_X4_P2},
				  {sW_P1, sW_X5_P2}, {sW_P1, sW_X6_P2} },
	mW_Y_PolyArr{ {sW_P1, sW_Y1_P2}, {sW_P1, sW_Y2_P2},
				  {sW_P1, sW_Y3_P2}, {sW_P1, sW_Y4_P2},
				  {sW_P1, sW_Y5_P2}, {sW_P1, sW_Y6_P2} },
	mW_Z_PolyArr{ {sW_P1, sW_Z1_P2}, {sW_P1, sW_Z2_P2},
				  {sW_P1, sW_Z3_P2}, {sW_P1, sW_Z4_P2},
				  {sW_P1, sW_Z5_P2}, {sW_P1, sW_Z6_P2} },
    mADC_PolyArr{ {sADC1_P1, sADC1_P2}, {sADC2_P1, sADC2_P2}, {sADC3_P1, sADC3_P2} }
{


}
const CStateEstimate::OutputType& CStateEstimate::getValue()
{
	return mOutput;
}
const CStateEstimate::OutputType& CStateEstimate::calcOutput(const CSensorData& input)
{
	this->calculateG(input);
	this->calculateUK(input);
	this->calculateUR(input);

	return mOutput;
}
void CStateEstimate::calculateG(const CSensorData& input)
{
	constexpr Float32 B1Sum = sB1[0] + sB1[1] + sB1[2] + sB1[3];
	constexpr Float32 B2Sum = sB2[0] + sB2[1] + sB2[2] + sB2[3];
	constexpr Float32 B3Sum = sB3[0] + sB3[1] + sB3[2] + sB3[3];

	CMPUData tmp_data = input.mSensor1Data;
	tmp_data.mA_z = input.mSensor3Data.mA_x;
	mACalibArr[0].calibrate(tmp_data);

	tmp_data = input.mSensor2Data;
	tmp_data.mA_z = input.mSensor4Data.mA_x;
	mACalibArr[1].calibrate(tmp_data);

	tmp_data = input.mSensor3Data;
	tmp_data.mA_z = input.mSensor5Data.mA_x;
	mACalibArr[2].calibrate(tmp_data);

	tmp_data = input.mSensor4Data;
	tmp_data.mA_z = input.mSensor6Data.mA_x;
	mACalibArr[3].calibrate(tmp_data);

	tmp_data = input.mSensor5Data;
	tmp_data.mA_z = input.mSensor1Data.mA_x;
	mACalibArr[4].calibrate(tmp_data);

	tmp_data = input.mSensor6Data;
	tmp_data.mA_z = input.mSensor2Data.mA_x;
	mACalibArr[5].calibrate(tmp_data);


//	mOutput.scalarAt(1,1) = ( sB1[0]*mACalibArr[0].getK1Acceleration() + sB1[1]*mACalibArr[1].getK1Acceleration() +
//							 sB1[2]*mACalibArr[4].getK1Acceleration() + sB1[3]*mACalibArr[5].getK1Acceleration() ) / B1Sum;
//	mOutput.scalarAt(2,1) = ( sB2[0]*mACalibArr[0].getK2Acceleration() + sB2[1]*mACalibArr[1].getK2Acceleration() +
//							 sB2[2]*mACalibArr[2].getK2Acceleration() + sB2[3]*mACalibArr[3].getK2Acceleration() ) / B2Sum;
//	mOutput.scalarAt(3,1) = ( sB3[0]*mACalibArr[2].getK3Acceleration() + sB3[1]*mACalibArr[3].getK3Acceleration() +
//							 sB3[2]*mACalibArr[4].getK3Acceleration() + sB3[3]*mACalibArr[5].getK3Acceleration() ) / B3Sum;

	Float32 g1 = ( sB1[0]*mACalibArr[0].getK1Acceleration() + sB1[1]*mACalibArr[1].getK1Acceleration() +
			 sB1[2]*mACalibArr[4].getK1Acceleration() + sB1[3]*mACalibArr[5].getK1Acceleration() ) / B1Sum;
	Float32 g2 = ( sB2[0]*mACalibArr[0].getK2Acceleration() + sB2[1]*mACalibArr[1].getK2Acceleration() +
			 sB2[2]*mACalibArr[2].getK2Acceleration() + sB2[3]*mACalibArr[3].getK2Acceleration() ) / B2Sum;
	Float32 g3 = ( sB3[0]*mACalibArr[2].getK3Acceleration() + sB3[1]*mACalibArr[3].getK3Acceleration() +
			 sB3[2]*mACalibArr[4].getK3Acceleration() + sB3[3]*mACalibArr[5].getK3Acceleration() ) / B3Sum;
	Float32 gAbs = sqrtf(g1*g1 + g2*g2 + g3*g3);

	mOutput.scalarAt(1,1) = 0.0F;
	mOutput.scalarAt(2,1) = -asinf(g3/gAbs);
	mOutput.scalarAt(3,1) = -atan2f(g2/gAbs, g1/gAbs);
}
void CStateEstimate::calculateUK(const CSensorData& input)
{
	mOutput.scalarAt(4,1) = ( mACalibArr[0].getK1AngularVelocity() + mACalibArr[1].getK1AngularVelocity() +
							   mACalibArr[2].getK1AngularVelocity() + mACalibArr[3].getK1AngularVelocity() +
							   mACalibArr[4].getK1AngularVelocity() + mACalibArr[5].getK1AngularVelocity() ) / 6.0F;
	mOutput.scalarAt(5,1) = ( mACalibArr[0].getK2AngularVelocity() + mACalibArr[1].getK2AngularVelocity() +
							   mACalibArr[2].getK2AngularVelocity() + mACalibArr[3].getK2AngularVelocity() +
							   mACalibArr[4].getK2AngularVelocity() + mACalibArr[5].getK2AngularVelocity() ) / 6.0F;
	mOutput.scalarAt(6,1) = ( mACalibArr[0].getK3AngularVelocity() + mACalibArr[1].getK3AngularVelocity() +
							   mACalibArr[2].getK3AngularVelocity() + mACalibArr[3].getK3AngularVelocity() +
							   mACalibArr[4].getK3AngularVelocity() + mACalibArr[5].getK3AngularVelocity() ) / 6.0F;

}
void CStateEstimate::calculateUR(const CSensorData& input)
{
	mOutput.scalarAt(7,1) = mOutput.scalarAt(4,1) + mADC_PolyArr[0].calcOutput(static_cast<Float32>(input.mADCData.mADC1Value));
	mOutput.scalarAt(8,1) = mOutput.scalarAt(5,1) + mADC_PolyArr[1].calcOutput(static_cast<Float32>(input.mADCData.mADC2Value));
	mOutput.scalarAt(9,1) = mOutput.scalarAt(6,1) + mADC_PolyArr[2].calcOutput(static_cast<Float32>(input.mADCData.mADC3Value));
}
