#include "TLinHierarchy.h"
#include "CA.h"
#include "CB.h"
#include "TActionHolder.h"
#include "CMPUCalib.h"

using CActionList = TYPELIST_2(CA, CB);
using CSignalFlow = TLinHierarchy<CActionList, TActionHolder>;

int main()
{
	CMPUCalib myCalib('control_data/sensor1_calib_data.csv');

	return 0;
}
