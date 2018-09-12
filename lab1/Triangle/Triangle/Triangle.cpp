// Triangle.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

const int INPUT_ERROR = 1;

bool StringIsFloat(string vertexInString);
bool TriangleExists(float a, float b, float c);
bool IsEquilateralTriangle(float a, float b, float c);
bool IsIsoscelesTriangle(float a, float b, float c);
int main()
{
	cout << "Enter the sides of the triangle through a space" << endl;
	float long1, long2, long3;
	string longInString1, longInString2, longInString3;
	cin >> longInString1 >> longInString2 >> longInString3;
	
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
			cout << "Equilateral triangle";
		else if (IsIsoscelesTriangle(long1, long2, long3))
			cout << "Isosceles triangle";
		else
			cout << "Triangle";
	}

	system("pause");
    return 0;
}


bool StringIsFloat(string longInString)
{
	int countOfPoints = 0;

	for (int i = 0; i < longInString.size(); i++)
	{

		if ((longInString[i] < '0' || longInString[i] > '9') && longInString[i] != '.')
			return false;

		if (longInString[i] == '.')
			countOfPoints++;

		if (countOfPoints > 1)
			return false;
	}

	return true;
}

bool TriangleExists(float a, float b, float c)
{
	if (a + b <= c || a + c <= b || c + b <= a)
		return false;
	else
		return true;
}


bool IsEquilateralTriangle(float a, float b, float c)
{
	if (fabs(a - b) < numeric_limits<double>::epsilon() && fabs(a - c) < numeric_limits<double>::epsilon())
		return true;
	else
		return false;
}

bool IsIsoscelesTriangle(float a, float b, float c)
{
	if (fabs(a - b) < numeric_limits<double>::epsilon() || fabs(a - c) < numeric_limits<double>::epsilon()
		|| fabs(b - c) < numeric_limits<double>::epsilon())
		return true;
	else
		return false;
}
