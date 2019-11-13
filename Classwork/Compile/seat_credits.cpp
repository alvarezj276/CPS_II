// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title: seat_credits.cpp
// Course: Computational Problem Solving CPET-II
// Developer: MATTHEW CHU & John Alvarez
// Date : Fall 2019 (2191)
// Description: Problem #2
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <iostream>
#include <iomanip>
#include <math.h>
#include <fstream>			// needed for file I/O
#include <cstdlib>			// needed for exit()
using namespace std;

struct passenger
{
	string fname;
	string lname;
	int credit;
	bool randomized=false;
	passenger *nextaddr;
};

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

void Create(passenger *head){
//	//do
//	//enter name : first, last
//	//if confirm database, proceed + report remaining seats
//		//if seats<=0 randomized=true; print error + exit
//		//else randomized=false;
//	//else print error + exit
//	//while()
//	passenger *current=head;
//	string first,last;
//	bool quit=false;
//	do{
//		cout << "Enter name (first, last): ";
//		cin >> first; cin >> last;
//		bool namecheck=false;
//		passenger *current;
//		while(current != NULL){
//			if(first==current->fname && last==current->lname){
//				namecheck=true;
//				if()
//			}
//			current = current->nextaddr;
//		}
//
//	}while(quit!=true);
}

passenger *Read(){
	ifstream inFile;

	inFile.open("seat_credits.txt");

	if (inFile.fail())
	{
		cout << "\nThe file did not successfully open... Program Terminated\n" << endl;
		exit (1);
	}

	passenger *current, *head;

	current = new passenger;
	head = current;

	do
	{
		inFile >> current->fname;
		inFile >> current->lname;
		inFile >> current->credit;inFile.ignore();

		if (inFile.eof())
		{
			current->nextaddr = NULL;
			break;
		}
		else
		{
			current->nextaddr = new passenger;
			current = current->nextaddr;
		}

	}
	while(true);

	inFile.close();

	return(head);
}

int main()
{
	//Create(head)
	//Display()
	//Modify()
	//Delete()
	//Print()
	//Reservation()

	passenger *head = Read();
	cout << head->fname << endl;
	cout << head->lname << endl;
	cout << head->credit << endl;
}
