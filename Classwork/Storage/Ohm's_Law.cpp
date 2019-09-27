// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title : Ohm's Law.cpp
// Course : Computational Problem Solving II (CPET-321)
// Developer : Matthew Chu
// Date : Sept 6 2019 (2191)
// Description : Program to calculate volts using Ohm's Law
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

const int SIZE=10;

void calc_volts(double volts[SIZE], double current[SIZE], double resistance[SIZE]){
	for(int i=0; i<SIZE; i++){
		volts[i]=current[i]*resistance[i];
	}
}

int main()
{
	double volts[SIZE];
	double current[SIZE]={10.62,14.89,13.21,16.55,18.62,9.47,6.58,18.32,12.15,3.98};
	double resistance[SIZE]={4,8.5,6,7.35,9,15.3,3,5.4,2.9,4.8};
	calc_volts(volts, current, resistance);
	for(int i=0; i<SIZE; i++){
		cout << "voltage[" << i <<"] = " << fixed << setprecision(2) << volts[i] << endl;
	}
	return 0;
}
