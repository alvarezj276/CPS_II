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

struct reserved
{
	int reserve;
	string pfname;
	string plname;
	string vehicle;
	int location;
	reserved *nextaddr;
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
	Pickup(){ front = 5; }

	void setPickup(int f)
	{
		front = f;
		return;
	}
};

class Compact:public Car{
protected:
	int front,back1,back2;
public:
	Compact(){ front = 5; back1 = 3; back2=3; }

	void setCompact(int f, int b1, int b2)
	{
		front = f;
		back1 = b1;
		back2 = b2;
		return;
	}
};

class Sedan:public Car{
protected:
	int front,sideback1,sideback2,sidemiddle;
public:
	Sedan(){ front = 5; sideback1=2; sideback2=2; sidemiddle=1; }

	void setSedan(int f, int sb1, int sb2, int sm)
	{
		front = f;
		sideback1 = sb1;
		sideback2 = sb2;
		sidemiddle = sm;
		return;
	}
};

void Create(passenger *head){
	passenger *current=head;
	string first,last;
	bool quit=false;
	do{
		cout << "Enter name (first, last): ";
		cin >> first; cin >> last;
		bool namecheck=false;
		passenger *current;
		int type, vehicle,seat;
		char select=' ';
		while(current != NULL){
			if(first==current->fname && last==current->lname){
				namecheck=true;
				cout << current->fname <<" "<<current->lname << " has " << current->credit << " credits remaining." << endl;
				if(current->credit<=0)
					current->randomized=true;
				else current->randomized=false;
			}
			current = current->nextaddr;
		}
		if(namecheck==false)
			quit=true;
		else{
//			Print();
			cout << "Select by category? (Y/N)";
			cin >> select; cin.ignore();
			if(select=='Y' || select=='y'){
				cout << "Select vehicle type (1-3): ";
				cin >> type; cin.ignore();
				if(type==1){

				}
			}
			if(select=='N' || select=='n'){

			}
			else{
				cout << "Incorrect vehicle type. Please restart selection." << endl;
			}
		}
	}while(quit!=true);
}

passenger *Read(){
	ifstream inFile;

	inFile.open("seat_credits.txt");

	if (inFile.fail()){
		cout << "\nThe file did not successfully open... Program Terminated\n" << endl;
		exit (1);
	}

	passenger *current, *head;

	current = new passenger;
	head = current;

	do{
		inFile >> current->fname;
		inFile >> current->lname;
		inFile >> current->credit;inFile.ignore();
		if (inFile.eof()){
			current->nextaddr = NULL;
			break;
		}
		else{
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

	Pickup pick[3];
	pick[0].setCar("PURPLE","TRUCK");
	pick[1].setCar("YELLOW","TRUCK");
	pick[2].setCar("RED","TRUCK");
	Compact comp[3];
	comp[0].setCar("GREEN","COMPACT");
	comp[1].setCar("GREEN","COMPACT");
	comp[2].setCar("GREEN","COMPACT");
	Sedan sed[3];

	passenger *head = Read();
	cout << head->fname << endl;
	cout << head->lname << endl;
	cout << head->credit << endl;
}
