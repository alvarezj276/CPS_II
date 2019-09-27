// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title : Circuits_Analysis_1.cpp
// Course : Computational Problem Solving II (CPET-321)
// Developer : Matthew Chu
// Date : Fall 2019 (2191)
// Description : Header file for circuit functions
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef CIRCUITS_ANALYSIS_1_H_
#define CIRCUITS_ANALYSIS_1_H_

const int SIZE = 3;			// SIZE of the circuit (i.e. # of branches)
const int ELEMENT=7;

extern float coef[SIZE][SIZE+1];	// declare an array to store the coefficients
// note : format is [ROW][COLUMN]

extern float ans[SIZE];			// declare an array to store answers
extern float val[ELEMENT];

void Init_Coefficient();
void Gauss_Elimination();
void Print_Current_Values();

#endif /* CIRCUITS_ANALYSIS_1_H_ */
