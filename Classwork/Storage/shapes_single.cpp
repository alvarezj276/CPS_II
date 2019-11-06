// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title: shapes_base.cpp
// Course: Computational Problem Solving CPET-II
// Developer: Dr G.H. Zion
// Date : Fall 2019 (2191)
// Description : Inheritance - base shape
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <iostream>
#include <iomanip>
using namespace std;

class Shape
{
	protected:
		string sName;
		char sColor;   // R = Red; G = Green; B = Blue

	public:
	    Shape()
	      { sName = " "; sColor = ' '; }

		void setShape(string name, char color)
		{
			sName = name;
			sColor = color;
			return;
		}

		void showShape()
		{
			cout << "Name : " << sName << endl;
			switch (sColor)
			{
				case 'R' :
				case 'r' : cout << "Color : Red" << endl;
					       break;
				case 'G' :
				case 'g' : cout << "Color : Green" << endl;
					       break;
				case 'B' :
				case 'b' : cout << "Color : Blue" << endl;
					       break;
				default  : cout << "Color : Unknown" << endl;
					       break;
			}
			return;
		}
};

class Rectangle:public Shape{
private:
	float width,height;
public:
	Rectangle(){ width = 0; height = 0; }

	void setSides(float w, float h)
	{
		width = w;
		height = h;
		return;
	}

	float calArea()
	{
		float area=width*height;
		return area;
	}
};

int main()
{
	Shape s1, s2;

	s1.setShape("Fred", 'R');
	s1.showShape();

	s2.setShape("Mary", 'B');
	s2.showShape();

	Rectangle r1;
	r1.setShape("Rect", 'R');
	r1.setSides(3,4);
	float tmp = r1.calArea();
	r1.showShape();
	cout << tmp << endl;
	return 0;
}



