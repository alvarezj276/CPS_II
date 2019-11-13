// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title: seat_credits.cpp
// Course: Computational Problem Solving CPET-II
// Developer: MATTHEW CHU
// Date : Fall 2019 (2191)
// Description: Problem #2
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

class Car
{
	protected:
		string color;
		string type;

	public:
	    Car()
	      { color = " "; type = " "; }

		void setCar(string c, string t)
		{
			color = c;
			type = t;
			return;
		}

//		void showCar()
//		{
//			cout << "Name : " << sName << endl;
//			switch (sColor)
//			{
//				case 'R' :
//				case 'r' : cout << "Color : Red" << endl;
//					       break;
//				case 'G' :
//				case 'g' : cout << "Color : Green" << endl;
//					       break;
//				case 'B' :
//				case 'b' : cout << "Color : Blue" << endl;
//					       break;
//				default  : cout << "Color : Unknown" << endl;
//					       break;
//			}
//			return;
//		}
};

class Pickup:public Car{
protected:
	int front;
public:
	Pickup(){ front = 0; }

	void setPickup(int f)
	{
		front = f;
		return;
	}
};

class Compact:public Car{
protected:
	int front,back;
public:
	Compact(){ front = 0; back = 0; }

	void setCompact(int f, int b)
	{
		front = f;
		back = b;
		return;
	}
};

class Sedan:public Car{
protected:
	int front,sideback,sidemiddle;
public:
	Sedan(){ front = 0; sideback=0; sidemiddle=0; }

	void setSedan(int f, int sb, int sm)
	{
		front = f;
		sideback = sb;
		sidemiddle = sm;
		return;
	}
};

int main()
{
	//Create()
	//Display()
	//Modify()
	//Delete()
	//Print()
	//Reservation()
}
