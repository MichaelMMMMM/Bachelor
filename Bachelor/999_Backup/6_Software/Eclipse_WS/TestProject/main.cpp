#include "CMPUCalib.h"
#include <iostream>
#include "TMatrix.h"
using namespace std;


int main()
{
	CMPUCalib myCalib("/root/control_data/sensor1_calib_data.csv");

	TMatrix<3U,3U> mat;
	mat.display();
	mat.scalarAt(1,1) = 5;
	mat.display();

	return 0;
}
