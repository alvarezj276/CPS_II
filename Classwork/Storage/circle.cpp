// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 		circle.cpp
//		description : creates circle using classes
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>			// needed for file I/O
#include <cstdlib>			// needed for exit()
#include <math.h>

using namespace std;

class Circle{
	private: float radius, area;
	public: Circle(float=0.0);
		void ShowArea();
		void SetRadius(float);
};

Circle::Circle(float r){
	float pi=3.141592;
	radius=r;
	area=pi*pow(r,2.0);
}

void Circle::ShowArea(){
	cout << "R = " << fixed << setprecision(2) << radius <<
			" Area = " << setprecision(2) << area << "\n";
}

void Circle::SetRadius(float r){
	float pi=3.141592;
	radius=r;
	area=pi*pow(r,2.0);
}
int main(){
	Circle c1(5.0),c2,c3;

	c1.ShowArea();

	c2.SetRadius(3.5);
	c2.ShowArea();

	c3=c1;
	c3.ShowArea();

	return 0;
}
