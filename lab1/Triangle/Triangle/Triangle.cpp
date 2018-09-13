// Triangle.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include "FuctionsForTriangle.h"
using namespace std;

const int INPUT_ERROR = 1;

const int COUNT_OF_ARGUMENTS = 4;
int main(int argc, char *argv[])
{
	if (argc != COUNT_OF_ARGUMENTS)
	{
		cout << "wrong number of arguments, they should be 3";
		return INPUT_ERROR;
	}


	float long1, long2, long3;
	string longInString1, longInString2, longInString3;
	longInString1 = argv[1];
	longInString2 = argv[2];
	longInString3 = argv[3];
	
	if (StringIsFloat(longInString1) && StringIsFloat(longInString2) && StringIsFloat(longInString3))
	{
		long1 = stof(longInString1);
		long2 = stof(longInString2);
		long3 = stof(longInString3);
	}
	else
		return INPUT_ERROR;

	if (TriangleExists(long1, long2, long3))
	{
		if (IsEquilateralTriangle(long1, long2, long3))
			cout << "equilateral triangle";
		else if (IsIsoscelesTriangle(long1, long2, long3))
			cout << "isosceles triangle";
		else
			cout << "simple triangle";
	}
	else
		cout << "there is no such triangle";

    return 0;
}
