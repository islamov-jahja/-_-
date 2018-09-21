#include "stdafx.h"
#include "FuctionsForTriangle.h"

bool StringIsFloat(string longInString)
{
	int countOfPoints = 0;

	for (int i = 0; i < longInString.size(); i++)
	{

		if ((longInString[i] < '0' || longInString[i] > '9') && longInString[i] != '.' && longInString[i] != ',')
			return false;

		if (longInString[i] == '.' || longInString[i] ==',')
			countOfPoints++;

		if (countOfPoints > 1)
			return false;
	}

	return true;
}

bool TriangleExists(double a, double b, double c)
{
	if (a + b <= c || a + c <= b || c + b <= a)
		return false;
	else
		return true;
}


bool IsEquilateralTriangle(double a, double b, double c)
{
	if (fabs(a - b) < numeric_limits<double>::epsilon() && fabs(a - c) < numeric_limits<double>::epsilon())
		return true;
	else
		return false;
}

bool IsIsoscelesTriangle(double a, double b, double c)
{
	if (fabs(a - b) < numeric_limits<double>::epsilon() || fabs(a - c) < numeric_limits<double>::epsilon()
		|| fabs(b - c) < numeric_limits<double>::epsilon())
		return true;
	else
		return false;
}
