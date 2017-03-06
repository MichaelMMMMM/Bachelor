#include <iostream>
#include "TMatrix.h"
using namespace std;

template<const UInt32 n>
using TVector = TMatrix<n, 1>;

int main()
{

	TMatrix<3U,3U> mat;
	mat.display();
	mat.scalarAt(1,1) = 5;
	mat.display();
	TMatrix<3U,3U> mat2;
	mat2.scalarAt(1,2) = 3;
	mat2.display();
	mat2 = mat2 + mat;
	mat2.display();

	TMatrix<3U, 3U> mat3 = mat*mat2;
	TVector<3U> vec1;
	TMatrix<3U, 1U> vec2 = mat*vec1;
	vec2.display();
	mat3.display();

	TVector<3U> yVec("/home/michael/Desktop/Bachelor/Bachelor/6_Software/Eclipse_WS/MatrixLib/Debug/Yvec_mat.csv");
	TMatrix<7U, 3U> lMat("/home/michael/Desktop/Bachelor/Bachelor/6_Software/Eclipse_WS/MatrixLib/Debug/Ld_mat.csv");
	TVector<7U> aVec = lMat*yVec;
	aVec.display();
	lMat.display();

	return 0;
}
