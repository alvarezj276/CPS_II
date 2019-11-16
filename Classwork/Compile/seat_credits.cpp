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

void Create(passenger *head, Pickup pick[3], Compact comp[3], Sedan sed[3]){
	passenger *current=head;
	string first,last;
	bool quit=false;
	do{
		cout << "Enter name (first, last): ";
		cin >> first; cin >> last;
		bool namecheck=false;
		passenger *current;
		string type, color;
		int seat;
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
			cout << "(V)ehicle or (S)pecific seating: ";
			cin >> select; cin.ignore();
			bool space=false;
			if(select=='V' || select=='v'){
				cout << "Select vehicle type: ";
				cin >> type;
				if(type=="TRUCK" || type=="Truck" || type=="truck"){
					if(current->credit<5){
						cout<<"Not enough credits. Please reselect." << endl;
						space=true;
					}
					else
						for(int i=0;i<3;i++){
							if(pick[i].front!=0){
								pick[i].front=0;
								current->credit-=5;
								space=true;
								break;
							}
						}
				}
				else{
					if(type=="COMPACT" || type=="Compact" || type=="compact"){
						if(current->credit<3){
							cout<<"Not enough credits. Please reselect." << endl;
							space=true;
						}
						else
							for(int i=0;i<3;i++){
								if(comp[i].front!=0){
									comp[i].front=0;
									if(current->credit<5)
										cout << "Not enough credits. Please reselect." << endl;
									else
										current->credit-=5;
									space=true;
									break;
								}
								if(comp[i].back1!=0){
									comp[i].back1=0;
									current->credit-=3;
									space=true;
									break;
								}
								if(comp[i].back2!=0){
									comp[i].back2=0;
									current->credit-=3;
									space=true;
									break;
								}
							}
					}
					else{
						if(type=="SEDAN" || type=="Sedan" || type=="sedan"){
							if(current->credit<1){
								cout<<"Not enough credits. Please reselect." << endl;
								space=true;
							}
							else
								for(int i=0;i<3;i++){
									if(sed[i].front!=0){
										sed[i].front=0;
										if(current->credit<5)
											cout << "Not enough credits. Please reselect." << endl;
										else
											current->credit-=5;
										space=true;
										break;
									}
									if(sed[i].sideback1!=0){
										sed[i].sideback1=0;
										if(current->credit<2)
											cout << "Not enough credits. Please reselect." << endl;
										else
											current->credit-=2;
										space=true;
										break;
									}
									if(sed[i].sideback2!=0){
										sed[i].sideback2=0;
										if(current->credit<2)
											cout << "Not enough credits. Please reselect." << endl;
										else
											current->credit-=2;
										space=true;
										break;
									}
									if(sed[i].sidemiddle!=0){
										sed[i].sidemiddle=0;
										current->credit-=1;
										space=true;
										break;
									}
								}
						}
					}
				}
				if(space==false)
					cout << "No room available in this vehicle type. Please reselect." << endl;
				else
					quit=true;
			}
			if(select=='S' || select=='s'){
				cout << "Select vehicle type: ";
				cin >> type;
				if(type=="TRUCK" || type=="Truck" || type=="truck"){
//					Print();
					if(current->credit<5){
						cout<<"Not enough credits. Please reselect." << endl;
						space=true;
					}
					for(int i=0;i<3;i++)
						if(pick[i].front!=0)
							space=true;
					if(space==false)
						cout<<"Not enough room. Please select another vehicle type." << endl;
					else{
						cout << "Select color of vehicle: ";
						cin>>color;
						if(color=="PURPLE" || color=="Purple" || color=="purple"){
							pick[0].front=0;
							current->credit-=5;
						}
						if(color=="YELLOW" || color=="Yellow" || color=="yellow"){
							pick[1].front=0;
							current->credit-=5;
						}
						if(color=="RED" || color=="Red" || color=="red"){
							pick[2].front=0;
							current->credit-=5;
						}
						else
							cout << "Color not found. Please reselect." << endl;
					}
				}
				else{
					if(type=="COMPACT" || type=="Compact" || type=="compact"){
						//						Print();
						if(current->credit<3){
							cout<<"Not enough credits. Please reselect." << endl;
							space=true;
						}
						for(int i=0;i<3;i++)
							if(comp[i].front!=0 || comp[i].back1!=0 || comp[i].back2!=0)
								space=true;
						if(space==false)
							cout<<"Not enough room. Please select another vehicle type." << endl;
						else{
							cout << "Select color of vehicle: ";
							cin>>color;
							if(color=="GREEN" || color=="Green" || color=="green"){
								cout << "Select seat (0-2): ";
								cin >> seat; cin.ignore();
								if(seat==0 || seat==1 || seat==2){
									if(seat==0){
										comp[0].front=0;
										current->credit-=5;
									}
									if(seat==1){
										comp[0].back1=0;
										current->credit-=3;
									}
									if(seat==2){
										comp[0].back2=0;
										current->credit-=3;
									}
								}
								else
									cout << "Seat not found. Please reselect." << endl;
							}
							if(color=="BLUE" || color=="Blue" || color=="blue"){
								cout << "Select seat (0-2): ";
								cin >> seat; cin.ignore();
								if(seat==0 || seat==1 || seat==2){
									if(seat==0){
										comp[1].front=0;
										current->credit-=5;
									}
									if(seat==1){
										comp[1].back1=0;
										current->credit-=3;
									}
									if(seat==2){
										comp[1].back2=0;
										current->credit-=3;
									}
								}
								else
									cout << "Seat not found. Please reselect." << endl;
							}
							if(color=="YELLOW" || color=="Yellow" || color=="yellow"){
								cout << "Select seat (0-2): ";
								cin >> seat; cin.ignore();
								if(seat==0 || seat==1 || seat==2){
									if(seat==0){
										comp[2].front=0;
										current->credit-=5;
									}
									if(seat==1){
										comp[2].back1=0;
										current->credit-=3;
									}
									if(seat==2){
										comp[2].back2=0;
										current->credit-=3;
									}
								}
								else
									cout << "Seat not found. Please reselect." << endl;
							}
						}
					}
					else{
						if(type=="SEDAN" || type=="Sedan" || type=="sedan"){
							//							Print();
							if(current->credit<1){
								cout<<"Not enough credits. Please reselect." << endl;
								space=true;
							}
							for(int i=0;i<3;i++)
								if(sed[i].front!=0 || sed[i].sideback1!=0 || sed[i].sideback2!=0 || sed[i].sidemiddle!=0)
									space=true;
							if(space==false)
								cout<<"Not enough room. Please select another vehicle type." << endl;
							else{
								cout << "Select color of vehicle: ";
								cin>>color;
								if(color=="RED" || color=="Red" || color=="red"){
									cout << "Select seat (0-3): ";
									cin >> seat; cin.ignore();
									if(seat==0 || seat==1 || seat==2 || seat==3){
										if(seat==0){
											sed[0].front=0;
											current->credit-=5;
										}
										if(seat==1){
											sed[0].sideback1=0;
											current->credit-=2;
										}
										if(seat==2){
											sed[0].sideback2=0;
											current->credit-=2;
										}
										if(seat==3){
											sed[0].sidemiddle=0;
											current->credit-=1;
										}
									}
									else
										cout << "Seat not found. Please reselect." << endl;
								}
								if(color=="GREEN" || color=="Green" || color=="green"){
									cout << "Select seat (0-3): ";
									cin >> seat; cin.ignore();
									if(seat==0 || seat==1 || seat==2 || seat==3){
										if(seat==0){
											sed[1].front=0;
											current->credit-=5;
										}
										if(seat==1){
											sed[1].sideback1=0;
											current->credit-=2;
										}
										if(seat==2){
											sed[1].sideback2=0;
											current->credit-=2;
										}
										if(seat==3){
											sed[1].sidemiddle=0;
											current->credit-=1;
										}
									}
									else
										cout << "Seat not found. Please reselect." << endl;
								}
								if(color=="BLUE" || color=="Blue" || color=="blue"){
									cout << "Select seat (0-3): ";
									cin >> seat; cin.ignore();
									if(seat==0 || seat==1 || seat==2 || seat==3){
										if(seat==0){
											sed[2].front=0;
											current->credit-=5;
										}
										if(seat==1){
											sed[2].sideback1=0;
											current->credit-=2;
										}
										if(seat==2){
											sed[2].sideback2=0;
											current->credit-=2;
										}
										if(seat==3){
											sed[2].sidemiddle=0;
											current->credit-=1;
										}
									}
									else
										cout << "Seat not found. Please reselect." << endl;
								}

							}
							if(space==false)
								cout << "No room available in this vehicle type. Please reselect." << endl;
							else
								quit=true;
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
	comp[1].setCar("BLUE","COMPACT");
	comp[2].setCar("YELLOW","COMPACT");
	Sedan sed[3];
	sed[0].setCar("RED","SEDAN");
	sed[1].setCar("GREEN","SEDAN");
	sed[2].setCar("BLUE","SEDAN");

	passenger *head = Read();
	cout << head->fname << endl;
	cout << head->lname << endl;
	cout << head->credit << endl;
}
