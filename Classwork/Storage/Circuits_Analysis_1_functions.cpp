// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title : Circuits_Analysis_1.cpp
// Course : Computational Problem Solving II (CPET-321)
// Developer : Matthew Chu
// Date : 2019
// Description : Functions to calculate the branch currents for a three loop
//				 mesh circuit given the circuit's Resistors and Voltage
//				 source values.  This program utilizes the Gauss-Elimination
//				 method
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <iostream>
#include <iomanip>
#include <math.h>
#include "Circuits_Analysis_1.h"

using namespace std;


float coef[SIZE][SIZE+1];	// declare an array to store the coefficients
// note : format is [ROW][COLUMN]

float ans[SIZE];			// declare an array to store answers
float val[ELEMENT];

int r,c,k;

void Init_Coefficient(){
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// Name : Init_Coefficient()
	// Input : None
	// Output : void
	// Purpose : instantiates the coefficients
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	//	const double val[0] = 1.0;		// Value for resistor val[0]
	//	const double val[1] = 1.0;		// Value for resistor val[1]
	//	const double val[2] = 1.0;		// Value for resistor val[2]
	//	const double val[3] = 1.0;		// Value for resistor val[3]
	//	const double val[4] = 1.0;		// Value for resistor val[4]
	//	const double val[5] = 5.0;		// Value for voltage source val[5]
	//	const double val[6] = 8.0;		// Value for voltage source val[6]
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// Construct the coefficient array using the given Resistor and Voltage
	// Source values.
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	coef[0][0] = (val[0] + val[1]);
	coef[0][1] = -(val[1]);
	coef[0][2] = 0;
	coef[0][3] = val[5];
	coef[1][0] = -(val[1]);
	coef[1][1] = (val[1] + val[2] + val[3]);
	coef[1][2] = -(val[3]);
	coef[1][3] = 0;
	coef[2][0] = 0;
	coef[2][1] = -(val[3]);
	coef[2][2] = (val[3] + val[4]);
	coef[2][3] = -(val[6]);
}
void Gauss_Elimination(){
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// Name : Gauss_Elimination()
	// Input : None
	// Output : void
	// Purpose : uses global coefficient array to compute asnwer array using
	//				 Gauss Elimination
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// Gauss-Elimination for solving a System of Linear Equations
	//
	//  Steps:  1) Pivotisation
	//			2) Gauss Elimination
	//			3) Back-Substitution
	//
	//  For more details on the Gauss-Elimination process please see:
	//           https://en.wikipedia.org/wiki/Gaussian_elimination
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// Steps #1 : Pivotisation +++++++++++++++++++++++++++++++++++++++++++++
	double tmp1;

	for (r=0; r<SIZE; r++)
		for (k=r+1; k<SIZE; k++)
			if (abs(coef[r][r]) < abs(coef[k][r]))
				for (c=0; c<=SIZE; c++)
				{
					tmp1 = coef[r][c];
					cout << coef [r][c] << endl;
					coef[r][c] = coef[k][c];
					coef[k][c] = tmp1;
				}
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	// Steps #2 : Gauss Elimination ++++++++++++++++++++++++++++++++++++++++
	double tmp2;
	for (r=0; r<SIZE-1; r++)
		for (k=r+1; k<SIZE; k++)
		{
			tmp2 = coef[k][r] / coef[r][r];
			for (c=0; c<=SIZE; c++)
				coef[k][c] = coef[k][c] - tmp2 * coef[r][c];
		}
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	// Steps #3 : Back-Substitution ++++++++++++++++++++++++++++++++++++++++
	for (r=SIZE-1; r>=0; r--)
	{
		ans[r] = coef[r][SIZE];
		for (c=r+1; c<SIZE; c++)
			if (c!=r)
				ans[r] = ans[r] - coef[r][c] * ans[c];
		ans[r] = ans[r] / coef[r][r];
	}
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

}
void Print_Current_Values(){
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// Name : Print_Current_Values()
	// Input : None
	// Output : void
	// Purpose : prints global ans array to console
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	// Print the calculated branch currents ++++++++++++++++++++++++++++++++
	cout<<"\nThe branch currents are as follows:" << endl;
	cout << fixed << setprecision(3);
	for (r=0; r<SIZE; r++)
		cout << "i[" << r+1 << "] = " << setw(8) << ans[r] <<endl;
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
}
