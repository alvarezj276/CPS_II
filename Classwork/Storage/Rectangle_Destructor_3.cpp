// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title: Rectangle_Destructor_3.cpp
// Course: Computational Problem Solving CPET-II
// Developer: Dr G.H. Zion
// Date : Fall 2019 (2191)
// Description: Added Char identifier to Constuctor and
//				printed that identifier in the Destructors
//				main() Expicitly call the Destructor
//
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <iostream>			// cin & cout
#include <iomanip>			// I/O formating
#include <cmath>			// math functions
#include <string>

using namespace std;

class Rectangle
{
	private:
		string rectangle_name;// Added a character to identify the object
		float length;
		float width;
		float area;

	public:
		Rectangle (string, float = 0.0, float = 0.0);
		~Rectangle ();
		void Show_Rectangle();
		float Get_Area();
		void Set_L_W(float, float);
};

Rectangle::Rectangle(string n, float l, float w)
{
	rectangle_name = n;	// initialized the objects name
	length = l;
	width = w;
	area = length * width;
}

Rectangle::~Rectangle()	// printed the objects name
{
	cout << "Rectangle " << rectangle_name << " Destructed" << endl;
}

void Rectangle::Show_Rectangle()
{
	cout << fixed << setprecision (2);
	cout << "L = " << length;
	cout << ", W = " << width;
	cout << ", A = " << area <<endl;
}

float Rectangle::Get_Area()
{
	return(area);
}

void Rectangle::Set_L_W(float l, float w)
{
	length = l;
	width = w;
	area = length * width;
}








int main()
{
	Rectangle r1("one", 3.0, 4.0);
	Rectangle r2("two");
	Rectangle r3("three", 7.0, 8.0);

	float area;

	r1.Show_Rectangle();
	area = r1.Get_Area();
	cout << "Area for r1 = " << area << endl;

	r2.Set_L_W(5.0, 6.0);
	r2.Show_Rectangle();
	area = r2.Get_Area();
	cout << "Area for r2 = " << area << endl;

	area = r3.Get_Area();
	cout << "Area for r3 = " << area << endl;

	r1.~Rectangle();
	r2.~Rectangle();
	r3.~Rectangle();

	return 0;
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++




