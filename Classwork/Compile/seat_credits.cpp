// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title: shapes_complete.cpp
// Course: Computational Problem Solving CPET-II
// Developer: MATTHEW CHU
// Date : Fall 2019 (2191)
// Description: Project #7
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <iostream>
#include <iomanip>
#include <math.h>
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
protected:
	float width,length;
public:
	Rectangle(){ width = 0; length = 0; }

	void setSides(float w, float h)
	{
		width = w;
		length = h;
		return;
	}

	float calArea()
	{
		float area=width*length;
		return area;
	}
};

class Cuboid:public Rectangle{
private:
	float height;
public:
	Cuboid(){ height = 0; }

	void setLength(float l)
	{
		height = l;
		return;
	}

	float calVolume()
	{
		float volume=calArea()*height;
		return volume;
	}
};

class Circle:public Shape{
protected:
	float radius;
public:
	Circle(){ radius = 0; }

	void setRadius(float r)
	{
		radius = r;
		return;
	}

	float calArea()
	{
		float area=3.1415*pow(radius,2.0);
		return area;
	}
};

class Cylinder: virtual public Circle{
protected:
	float height;
public:
	Cylinder(){ height = 0; }

	void setHeight(float h)
	{
		height = h;
		return;
	}

	float calVolume()
	{
		float vol=calArea()*height;
		return vol;
	}
};

class Sphere: virtual public Circle{
protected:
	float volume;
public:
	float calVolume()
	{
		volume=calArea()*1.3333*radius;
		return volume;
	}
};

class Spherelinder:public Cylinder, public Sphere{
public:
	float calVolume()
	{
		float sl=Cylinder::calVolume() + Sphere::calVolume();
		return sl;
	}
};

int main()
{
	Shape s1, s2;

//	s1.setShape("Fred", 'R');
//	s1.showShape();
//
//	s2.setShape("Mary", 'B');
//	s2.showShape();

	Rectangle r1;
	r1.setShape("Rectangle", 'R');
	r1.setSides(3,4);
	float area = r1.calArea();
	r1.showShape();
	cout << "Area: " << area << endl;
	cout << "----------" << endl;
	Cuboid c1;
	c1.setShape("Cuboid", 'R');
	c1.setSides(3,4);
	c1.showShape();
	float area1 = c1.calArea();
	cout << "Area: " << area1 << endl;
	c1.setLength(5);
	float vol = c1.calVolume();
	cout << "Volume: " << vol << endl;
	cout << "----------" << endl;
	Circle c2;
	c2.setShape("Circle", 'R');
	c2.setRadius(2);
	c2.showShape();
	float area2=c2.calArea();
	cout << "Area: " << area2 << endl;
	cout << "----------" << endl;
	Sphere s3;
	s3.setShape("Sphere", 'R');
	s3.setRadius(2);
	s3.showShape();
	float area3=s3.calArea();
	cout << "Area: " << area3 << endl;
	float vol1=s3.calVolume();
	cout << "Volume: " << vol1 << endl;
	cout << "----------" << endl;
	Cylinder c3;
	c3.setShape("Cylinder", 'R');
	c3.setRadius(2);
	c3.showShape();
	float area4=c3.calArea();
	cout << "Area: " << area4 << endl;
	c3.setHeight(5);
	float vol2=c3.calVolume();
	cout << "Volume: " << vol2 << endl;
	cout << "----------" << endl;
	Spherelinder s4;
	s4.setShape("Spherelinder", 'R');
	s4.setRadius(2);
	s4.showShape();
	float area5=s4.calArea();
	cout << "Area: " << area5 << endl;
	s4.setHeight(5);
	float vol3=s4.calVolume();
	cout << "Volume: " << vol3 << endl;
}
