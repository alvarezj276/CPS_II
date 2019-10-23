// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title: Rectangle4.cpp
// Course: Computational Problem Solving CPET-II
// Developer: Dr G.H. Zion
// Date : Fall 2019 (2191)
// Description: Example of Classes : Rectangle
//				Constructor and Get_Area using in-line
//				member funcion
//
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <iostream>			// cin & cout
#include <iomanip>			// I/O formating
#include <cmath>			// math functions
#include <string>			// math functions

using namespace std;

class Rectangle
{
	private:
		float length;
		float width;
		float area;

	public:
		Rectangle (float l = 0.0, float w = 0.0)
			{
				length = l;
				width = w;
				area = length * width;
			}

		~Rectangle()
		{
			cout << "Rectangle Destructed" << endl;
		}

		void Show_Rectangle()
		{
			cout << fixed << setprecision (2);
			cout << "L = " << length;
			cout << ", W = " << width;
			cout << ", A = " << area <<endl;
		}

		float Get_Area() { return(area); }

		void Set_L_W(float l, float w)
		{
			length = l;
			width = w;
			area = length * width;
		}
};

int main()
{
	Rectangle r1(3.0, 4.0);
	Rectangle r2;

	float area;

	r1.Show_Rectangle();
	area = r1.Get_Area();
	cout << "Area for r1 = " << area << endl;

	r2.Set_L_W(5.0, 7.0);
	r2.Show_Rectangle();
	area = r2.Get_Area();
	cout << "Area for r2 = " << area << endl;

	return 0;
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++




