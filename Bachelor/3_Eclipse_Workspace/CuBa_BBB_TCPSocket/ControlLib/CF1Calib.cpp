/**
 * @file	CF1Calib.cpp
 * @author	Michael Meindl
 * @date	18.04.2017
 * @brief	Method definitions for CF1Calib.
 */
#include "CF1Calib.h"

CF1Calib::CF1Calib() : mST1_A_Poly{ {"config/at1_f1_x_poly.csv"}, {"config/at1_f1_y_poly.csv"}, {"config/at1_f1_z_poly.csv"} },
					   mST2_A_Poly{ {"config/at2_f1_x_poly.csv"}, {"config/at2_f1_y_poly.csv"}, {"config/at2_f1_z_poly.csv"} },
					   mST3_A_Poly{ {"config/at3_f1_x_poly.csv"}, {"config/at3_f1_y_poly.csv"}, {"config/at3_f1_z_poly.csv"} },
					   mST4_A_Poly{ {"config/at4_f1_x_poly.csv"}, {"config/at4_f1_y_poly.csv"}, {"config/at4_f1_z_poly.csv"} },
					   mS1_W_Poly{ {"config/w1_f1_x_poly.csv"}, {"config/w1_f1_y_poly.csv"}, {"config/w1_f1_z_poly.csv"} },
					   mS2_W_Poly{ {"config/w2_f1_x_poly.csv"}, {"config/w2_f1_y_poly.csv"}, {"config/w2_f1_z_poly.csv"} },
					   mS3_W_Poly{ {"config/w3_f1_x_poly.csv"}, {"config/w3_f1_y_poly.csv"}, {"config/w3_f1_z_poly.csv"} },
					   mS4_W_Poly{ {"config/w4_f1_x_poly.csv"}, {"config/w4_f1_y_poly.csv"}, {"config/w4_f1_z_poly.csv"} },
					   mS5_W_Poly{ {"config/w5_f1_x_poly.csv"}, {"config/w5_f1_y_poly.csv"}, {"config/w5_f1_z_poly.csv"} },
					   mS6_W_Poly{ {"config/w6_f1_x_poly.csv"}, {"config/w6_f1_y_poly.csv"}, {"config/w6_f1_z_poly.csv"} },
					   mADC_Poly{ {"config/adc1_f1_poly.csv"}, {"config/adc2_f1_poly.csv"}, {"config/adc3_f1_poly.csv"} }
{

}
const CF1Calib::OutputType& CF1Calib::calcOutput(const CF1Calib::InputType& input)
{
	mOutput.mST1_A[0] = mST1_A_Poly[0].calcOutput(static_cast<Float32>(input.mSensor1Data.mA_y));
	mOutput.mST1_A[1] = mST1_A_Poly[1].calcOutput(static_cast<Float32>(input.mSensor1Data.mA_x));
	mOutput.mST1_A[2] = mST1_A_Poly[2].calcOutput(static_cast<Float32>(input.mSensor3Data.mA_x));

	mOutput.mST2_A[0] = mST2_A_Poly[0].calcOutput(static_cast<Float32>(input.mSensor2Data.mA_y));
	mOutput.mST2_A[1] = mST2_A_Poly[1].calcOutput(static_cast<Float32>(input.mSensor2Data.mA_x));
	mOutput.mST2_A[2] = mST2_A_Poly[2].calcOutput(static_cast<Float32>(input.mSensor4Data.mA_x));

	mOutput.mST3_A[0] = mST3_A_Poly[0].calcOutput(static_cast<Float32>(input.mSensor5Data.mA_x));
	mOutput.mST3_A[1] = mST3_A_Poly[1].calcOutput(static_cast<Float32>(input.mSensor3Data.mA_y));
	mOutput.mST3_A[2] = mST3_A_Poly[2].calcOutput(static_cast<Float32>(input.mSensor5Data.mA_y));

	mOutput.mST4_A[0] = mST4_A_Poly[0].calcOutput(static_cast<Float32>(input.mSensor6Data.mA_x));
	mOutput.mST4_A[1] = mST4_A_Poly[1].calcOutput(static_cast<Float32>(input.mSensor4Data.mA_y));
	mOutput.mST4_A[2] = mST4_A_Poly[2].calcOutput(static_cast<Float32>(input.mSensor6Data.mA_y));

	mOutput.mS1_W[0]  = mS1_W_Poly[0].calcOutput(static_cast<Float32>(input.mSensor1Data.mW_x));
	mOutput.mS1_W[1]  = mS1_W_Poly[1].calcOutput(static_cast<Float32>(input.mSensor1Data.mW_y));
	mOutput.mS1_W[2]  = mS1_W_Poly[2].calcOutput(static_cast<Float32>(input.mSensor1Data.mW_z));

	mOutput.mS2_W[0]  = mS1_W_Poly[0].calcOutput(static_cast<Float32>(input.mSensor2Data.mW_x));
	mOutput.mS2_W[1]  = mS1_W_Poly[1].calcOutput(static_cast<Float32>(input.mSensor2Data.mW_y));
	mOutput.mS2_W[2]  = mS1_W_Poly[2].calcOutput(static_cast<Float32>(input.mSensor2Data.mW_z));

	mOutput.mS3_W[0]  = mS1_W_Poly[0].calcOutput(static_cast<Float32>(input.mSensor3Data.mW_x));
	mOutput.mS3_W[1]  = mS1_W_Poly[1].calcOutput(static_cast<Float32>(input.mSensor3Data.mW_y));
	mOutput.mS3_W[2]  = mS1_W_Poly[2].calcOutput(static_cast<Float32>(input.mSensor3Data.mW_z));

	mOutput.mS4_W[0]  = mS1_W_Poly[0].calcOutput(static_cast<Float32>(input.mSensor4Data.mW_x));
	mOutput.mS4_W[1]  = mS1_W_Poly[1].calcOutput(static_cast<Float32>(input.mSensor4Data.mW_y));
	mOutput.mS4_W[2]  = mS1_W_Poly[2].calcOutput(static_cast<Float32>(input.mSensor4Data.mW_z));

	mOutput.mS5_W[0]  = mS1_W_Poly[0].calcOutput(static_cast<Float32>(input.mSensor5Data.mW_x));
	mOutput.mS5_W[1]  = mS1_W_Poly[1].calcOutput(static_cast<Float32>(input.mSensor5Data.mW_y));
	mOutput.mS5_W[2]  = mS1_W_Poly[2].calcOutput(static_cast<Float32>(input.mSensor5Data.mW_z));

	mOutput.mS6_W[0]  = mS1_W_Poly[0].calcOutput(static_cast<Float32>(input.mSensor6Data.mW_x));
	mOutput.mS6_W[1]  = mS1_W_Poly[1].calcOutput(static_cast<Float32>(input.mSensor6Data.mW_y));
	mOutput.mS6_W[2]  = mS1_W_Poly[2].calcOutput(static_cast<Float32>(input.mSensor6Data.mW_z));

	mOutput.mADC[0]   = mADC_Poly[0].calcOutput(static_cast<Float32>(input.mADCData.mADC1Value));
	mOutput.mADC[1]   = mADC_Poly[1].calcOutput(static_cast<Float32>(input.mADCData.mADC2Value));
	mOutput.mADC[2]   = mADC_Poly[2].calcOutput(static_cast<Float32>(input.mADCData.mADC3Value));
	return mOutput;
}
const CF1Calib::OutputType& CF1Calib::getValue() const
{
	return mOutput;
}
