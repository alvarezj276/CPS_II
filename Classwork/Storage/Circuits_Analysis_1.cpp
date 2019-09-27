// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title : Circuits_Analysis_1.cpp
// Course : Computational Problem Solving II (CPET-321)
// Developer : Matthew Chu
// Date : Fall 2019 (2191)
// Description : Program to calculate the branch currents for a three loop
//				 mesh circuit given the circuit's Resistors and Voltage
//				 source values.  This program utilizes the Gauss-Elimination
//				 method
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <iostream>
#include <iomanip>
#include <math.h>
#include <fstream>			// needed for file I/O
#include <cstdlib>			// needed for exit()
#include "Circuits_Analysis_1.h"

using namespace std;


int main()
{
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// Name : main()
	// Input : None
	// Output : void
	// Purpose : imports circuit values and calls functions
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	ifstream inFile;
	inFile.open("circuit.dat");
	if (inFile.fail())
	{
		cout << "\nThe file did not successfully open... Program Terminated\n" << endl;
		exit (1);
	}
	for (int i = 0; i < 7; i++)
	{
		inFile >> val[i];
	}
	inFile.close();

	Init_Coefficient();
	Gauss_Elimination();
	Print_Current_Values();
	return 0;
}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
