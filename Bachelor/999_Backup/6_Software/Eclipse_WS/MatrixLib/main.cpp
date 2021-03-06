#include <iostream>
#include "TMatrix.h"
using namespace std;


int main()
{
	TMatrix<3U, 3U> test1;
	TMatrix<7U, 3U> test2("Debug/Ld_mat.csv");
	test2.display();

	test1[1][1] = 3.0F;
	test1[2][1] = 4.0F;
	test1[3][1] = 5.0F;
	test1[1][2] = 6.0F;
	test1[2][2] = 7.0F;
	test1[3][2] = 8.0F;
	test1[1][3] = 9.0F;
	test1[2][3] = 10.0F;
	test1[3][3] = 11.0F;
	test1.display();

	TMatrix<3U, 3U> test3;
	test3[1][1] = 1;
	test3[2][2] = 1;
	test3[3][3] = 1;


	TMatrix<3U, 3U> test4;
	test4 = test1*test3;
	test3.display();
	test4.display();

	auto test5 = test2 * test1;
	test5.display();
	return 0;
}
