/*
 * coordinates.cpp
 *
 *  Created on: Aug 28, 2019
 *      Author: mxc6641
 */

#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <iomanip>

using namespace std;

int main(void){
	float x1,x2,y1,y2;
	float distance;
		cout << "Enter start and end x, then start and end y";
		cin >> x1 >> x2 >> y1 >> y2;
	distance=sqrt(pow(x2-x1,2.0)+pow(y2-y1,2.0));
	cout << fixed << setw(6) << setprecision(6) << distance;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
