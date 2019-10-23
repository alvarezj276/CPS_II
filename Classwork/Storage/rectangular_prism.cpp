// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 		Title: rectangularprism.cpp
// 		Course: Computational Problem Solving 2
// 		Developer: MATTHEW CHU
// 		Date: Fall 2019
//		Description : Creates Rectangular Prism Using Classes
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>			// needed for file I/O
#include <cstdlib>			// needed for exit()
#include <math.h>

using namespace std;

class RectangularPrism{
	private: float length, width, height;
	public: RectangularPrism(float=1.0,float=1.0,float=1.0);
		void setLength(float);
		void setWidth(float);
		void setHeight(float);
		void setDimensions(float,float,float);
		void showDimensions();
		float calculateDiagonal();
		float calculateSurface();
		float calculateVolume();
};

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 		Name: RectangularPrism
// 		Input: float values for length, width, height
// 		Output: none
//		Purpose : instantiates values of Rectangular Prism
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
RectangularPrism::RectangularPrism(float l, float w, float h){
	length=l;
	width=w;
	height=h;
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 		Name: setLength
// 		Input: float value for length
// 		Output: none
//		Purpose : instantiates value of Rectangular Prism length
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void RectangularPrism::setLength(float l){
	length=l;
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 		Name: setWidth
// 		Input: float value for width
// 		Output: none
//		Purpose : instantiates value of Rectangular Prism width
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void RectangularPrism::setWidth(float w){
	width=w;
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 		Name: setHeight
// 		Input: float value for height
// 		Output: none
//		Purpose : instantiates value of Rectangular Prism height
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void RectangularPrism::setHeight(float h){
	height=h;
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 		Name: setDimensions
// 		Input: float values for length, width, height
// 		Output: none
//		Purpose : updates values of Rectangular Prism
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void RectangularPrism::setDimensions(float l, float w, float h){
	length=l;
	width=w;
	height=h;
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 		Name: showDimensions
// 		Input: none
// 		Output: none
//		Purpose : prints values of Rectangular Prism
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void RectangularPrism::showDimensions(){
	cout << "L = " << fixed << setprecision(2) << length <<
			", W = " << setprecision(2) << width <<
			", H = " << setprecision(2) << height << endl;
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 		Name: calculateDiagonal
// 		Input: none
// 		Output: none
//		Purpose : calculates value of Rectangular Prism diagonal
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
float RectangularPrism::calculateDiagonal(){
	float diagonal= sqrt(pow(length,2)+pow(width,2)+pow(height,2));
	return diagonal;
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 		Name: calculateSurface
// 		Input: none
// 		Output: none
//		Purpose : calculates value of Rectangular Prism surface area
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
float RectangularPrism::calculateSurface(){
	float surface= 2*((length*width)+(length*height)+(width*height));
	return surface;
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 		Name: calculateVolume
// 		Input: none
// 		Output: none
//		Purpose : calculates value of Rectangular Prism volume
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
float RectangularPrism::calculateVolume(){
	float volume=length*width*height;
	return volume;
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 		Name: main
// 		Input: none
// 		Output: none
//		Purpose : assembles final output
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int main(){
	RectangularPrism r1,r2,r3(2.0, 3.0, 4.0);
	r2.setDimensions(1.2, 3.4, 5.6);

	r1.showDimensions();
	cout << "Diagonal = " << fixed << setprecision(2) << r1.calculateDiagonal() << endl;
	cout << "Surface = " << fixed << setprecision(2) << r1.calculateSurface() << endl;
	cout << "Volume = " << fixed << setprecision(2) << r1.calculateVolume() << endl;
	cout << "\n";
	r2.showDimensions();
	cout << "Diagonal = " << fixed << setprecision(2) << r2.calculateDiagonal() << endl;
	cout << "Surface = " << fixed << setprecision(2) << r2.calculateSurface() << endl;
	cout << "Volume = " << fixed << setprecision(2) << r2.calculateVolume() << endl;
	cout << "\n";
	r3.showDimensions();
	cout << "Diagonal = " << fixed << setprecision(2) << r3.calculateDiagonal() << endl;
	cout << "Surface = " << fixed << setprecision(2) << r3.calculateSurface() << endl;
	cout << "Volume = " << fixed << setprecision(2) << r3.calculateVolume() << endl;
	cout << "\n";

	r1.setLength(9.0);
	r1.showDimensions();
	r1.setWidth(8.0);
	r1.showDimensions();
	r1.setHeight(7.0);
	r1.showDimensions();

	return 0;
}
