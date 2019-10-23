// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title: Polar_Numbers_2.cpp
// Course: Computational Problem Solving CPET-II
// Developer: Dr G.H. Zion
// Date : Fall 2019 (2191)
// Description: Simple Class for Polar Numbers
//				Multiplier Operator Member Function
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <iomanip>

using namespace std;

class PolarNumber
{
	private:
		double magnitude;
		double angle;

	public:
		PolarNumber(double m = 0.0, double a = 0.0)
		{
			magnitude = m;
			angle = a;
		};

		void displayPolarNumber()
		{
			char sign = '+';

			if(angle < 0) sign = '-';
			cout << fixed << setprecision(2);
			cout << "MAG: " << setw(6) << magnitude << " @ ";
			cout << sign << setw(6) << abs(angle) << endl;
		};

		PolarNumber operator*(PolarNumber);
//		call-by-reference means no copy, save mem but potential to change main var
//		PolarNumber operator*(PolarNumber&);
//		const call-by-ref means main var protected
//		PolarNumber operator*(const PolarNumber&);
		PolarNumber operator/(PolarNumber);
};

PolarNumber PolarNumber::operator *(PolarNumber X)
{
	PolarNumber ans;

	ans.magnitude = magnitude * X.magnitude;
	ans.angle = angle + X.angle;

	return ans;
};

PolarNumber PolarNumber::operator /(PolarNumber X)
{
	PolarNumber ans;

	ans.magnitude = magnitude / X.magnitude;
	ans.angle = angle - X.angle;

	return ans;
};


int main()
{
	PolarNumber A (25.0, -45.0), B (-35.0, 68.0);
	PolarNumber C;

	cout << "(A) "; A.displayPolarNumber();
	cout << "(B) "; B.displayPolarNumber();

	C = A * B;

	cout << "(C) "; C.displayPolarNumber();

	C = A / B;

	cout << "(C) "; C.displayPolarNumber();


	return 0;;
}



