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
#include <cctype>
#include <cstring>
#include <cstdio>
using namespace std;

struct passenger
{
	string fname;
	string lname;
	int credit;
	int reserve;
	string vehicle;
	int location;
	bool randomized=false;
	passenger *nextaddr;
};

// struct reserved
// {
// 	int reserve;
// 	string pfname;
// 	string plname;
// 	string vehicle;
// 	int location;
// 	reserved *nextaddr;
// };

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

// void display() {

// 	cout << "\n\n\tPick Up\t\tCompact\t\tSedan\n\t______\t\t _____\t\t_____\n";

// 	cout << "\t|PURPLE|\t|GREEN|\t\t| RED |\n";
// 	cout << "\t" << "|(" << pick[1] << ")(" << pick[2] << ")|";
// 	cout << "\t" << "|(" << comp[1] << ") (" << comp[2] << ")|";
// 	cout << "\t" << "|(" << sed[3] << ")   (" << sed[3] << ")|\n";

// 	cout << "\t\t\t" << "|(" << comp[1] << ") (" << comp[2] << ")|";
// 	cout << "\t" << "|(" << sed[3] << ")(" << sed[3] << ")(" << sed[3]<< ")|" << "\n\n";

// 	cout << "\t|YELLOW|\t| BLUE|\t\t|GREEN|\n";
// 	cout << "\t" << "|(" << pick[1] << ")(" << pick[2] << ")|";
// 	cout << "\t" << "|(" << comp[1] << ") (" << comp[2] << ")|";
// 	cout << "\t" << "|(" << sed[3] << ")   (" << sed[3] << ")|\n";

// 	cout << "\t\t\t" << "|(" << comp[1] << ") (" << comp[2] << ")|";
// 	cout << "\t" << "|(" << sed[3] << ")(" << sed[3] << ")(" << sed[3]<< ")|" << "\n\n";

// 	cout << "\t| RED|\t\t|YELLOW|\t|BLUE|\n";
// 	cout << "\t" << "|(" << pick[1] << ")(" << pick[2] << ")|";
// 	cout << "\t" << "|(" << comp[1] << ") (" << comp[2] << ")|";
// 	cout << "\t" << "|(" << sed[3] << ")   (" << sed[3] << ")|\n";

// 	cout << "\t\t\t" << "|(" << comp[1] << ") (" << comp[2] << ")|";
// 	cout << "\t" << "|(" << sed[3] << ")(" << sed[3] << ")(" << sed[3] << ")|" << "\n\n";

// }	
	
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
public:
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
public:
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
public:
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

	return head;
}

void Create(passenger *head, Pickup pick[3], Compact comp[3], Sedan sed[3]){
	string first, last;
	bool quit=false;
	passenger *current;
	do{
		cout << "Enter name (first, last): ";
		cin >> first; cin >> last;
		bool namecheck=false;
		string type, color;
		current=head;
		int car_num,seat;
		char select=' ';
		while(current != NULL){
			if(first==current->fname && last==current->lname){
				namecheck=true;
				cout << current->fname <<" "<<current->lname << " has " << current->credit << " credits remaining." << endl;
				if(current->credit<=0){
					current->randomized=true;
					cout << current->fname << " " << current->lname << "will be assigned to remaining available seats." << endl;
				}
				else current->randomized=false;
			}
			current = current->nextaddr;
		}
		if(namecheck==false)
			quit=true;
		else{
//			Print();
			cout << "Choose selection (Category/Seat): ";
			cin >> select; cin.ignore();
			select=toupper(select);
			if(select=='C'){
				for(int i=0;i<3;i++){
					if(pick[i].front!=0){
						current->credit-=5;
						pick[i].front=0;
						quit=!quit;
						break;
					}else{
						if(comp[i].front!=0){
							current->credit-=5;
							comp[i].front=0;
							quit=!quit;
							break;
						}else
							if(sed[i].front!=0){
								current->credit-=5;
								sed[i].front=0;
								quit=!quit;
								break;
							}
					}
				}
			}else{
				if(select=='S'){
//					Print();
					cout << "Select vehicle type by number (1-3): ";
					cin >> car_num; cin.ignore();
					string tmp;
					if(car_num==1){
						if(current->credit<5){
							cout<<"-INVALID CREDIT LIMIT-/Please reselect."<<endl;
						}else
						{
							cout << "Select pickup by color: ";
							cin>>tmp;
							for(char x: tmp)
								color+=toupper(x);
							if(color=="PURPLE"){
								if(pick[0].front!=0){
									current->credit-=5;
									pick[0].front=0;
									quit=!quit;
									break;
								}
								else cout<<"Front seat occupied. Please reselect." << endl;
							}
							if(color=="YELLOW"){
								if(pick[1].front!=0){
									current->credit-=5;
									pick[1].front=0;
									quit=!quit;
									break;
								}
								else cout<<"Front seat occupied. Please reselect." << endl;
							}
							if(color=="RED"){
								if(pick[2].front!=0){
									current->credit-=5;
									pick[2].front=0;
									quit=!quit;
									break;
								}
								else cout<<"Front seat occupied. Please reselect." << endl;
							}else{
								cout << "-INVALID COLOR-\nPlease reselect." << endl;
							}
						}
					}
					if(car_num==2){
						if(current->credit<3){
							cout<<"-INVALID CREDIT LIMIT-/Please reselect."<<endl;
						}else{
							cout << "Select compact car by color: ";
							cin>>tmp;
							for(char x: tmp)
								color+=toupper(x);
							if(color=="GREEN"){
								cout<<"Enter seat (1-3): ";
								cin>>seat;cin.ignore();
								if(seat==1){
									if(comp[0].front!=0){
										current->credit-=5;
										comp[0].front=0;
										quit=!quit;
										break;
									}
									else cout<<"Front seat occupied. Please reselect." << endl;
								}
								if(seat==2){
									if(comp[0].back1!=0){
										current->credit-=3;
										comp[0].back1=0;
										quit=!quit;
										break;
									}
									else cout<<"Left back seat occupied. Please reselect." << endl;
								}
								if(seat==3){
									if(comp[0].back2!=0){
										current->credit-=3;
										comp[0].back2=0;
										quit=!quit;
										break;
									}
									else cout<<"Right back seat occupied. Please reselect." << endl;
								}else cout << "-INVALID SEAT-\nPlease reselect."<<endl;
							}
							if(color=="BLUE"){
								cout<<"Enter seat (1-3): ";
								cin>>seat;cin.ignore();
								if(seat==1){
									if(comp[1].front!=0){
										current->credit-=5;
										comp[1].front=0;
										quit=!quit;
										break;
									}
									else cout<<"Front seat occupied. Please reselect." << endl;
								}
								if(seat==2){
									if(comp[1].back1!=0){
										current->credit-=3;
										comp[1].back1=0;
										quit=!quit;
										break;
									}
									else cout<<"Left back seat occupied. Please reselect." << endl;
								}
								if(seat==3){
									if(comp[1].back2!=0){
										current->credit-=3;
										comp[1].back2=0;
										quit=!quit;
										break;
									}
									else cout<<"Right back seat occupied. Please reselect." << endl;
								}else cout <<"-INVALID SEAT-\nPlease reselect."<<endl;
							}
							if(color=="YELLOW"){
								cout<<"Enter seat (1-3): ";
								cin>>seat;cin.ignore();
								if(seat==1){
									if(comp[2].front!=0){
										current->credit-=5;
										comp[2].front=0;
										quit=!quit;
										break;
									}
									else cout<<"Front seat occupied. Please reselect." << endl;
								}
								if(seat==2){
									if(comp[2].back1!=0){
										current->credit-=3;
										comp[2].back1=0;
										quit=!quit;
										break;
									}
									else cout<<"Left back seat occupied. Please reselect." << endl;
								}
								if(seat==3){
									if(comp[2].back2!=0){
										current->credit-=3;
										comp[2].back2=0;
										quit=!quit;
										break;
									}
									else cout<<"Right back seat occupied. Please reselect." << endl;
								}else cout<<"-INVALID SEAT-\nPlease reselect."<<endl;
							}else{
								cout << "-INVALID COLOR-\nPlease reselect." << endl;
							}
						}
					}
					if(car_num==3){
						if(current->credit<5){
							cout<<"-INVALID CREDIT LIMIT-/Please reselect."<<endl;
						}else{
							cout << "Select sedan by color: ";
							cin>>tmp;
							for(char x: tmp)
								color+=toupper(x);
							if(color=="RED"){
								cout<<"Enter seat (1-4): ";
								cin>>seat;cin.ignore();
								if(seat==1){
									if(sed[0].front!=0){
										current->credit-=5;
										sed[0].front=0;
										quit=!quit;
										break;
									}
									else cout<<"Front seat occupied. Please reselect." << endl;
								}
								if(seat==2){
									if(sed[0].sideback1!=0){
										current->credit-=2;
										sed[0].sideback1=0;
										quit=!quit;
										break;
									}
									else cout<<"Left back seat occupied. Please reselect." << endl;
								}
								if(seat==3){
									if(sed[0].sidemiddle!=0){
										current->credit-=1;
										sed[0].sidemiddle=0;
										quit=!quit;
										break;
									}
									else cout<<"Middle back seat occupied. Please reselect." << endl;
								}
								if(seat==4){
									if(sed[0].sideback2!=0){
										current->credit-=2;
										sed[0].sideback2=0;
										quit=!quit;
										break;
									}
									else cout<<"Right back seat occupied. Please reselect." << endl;
								}else cout << "-INVALID SEAT-\nPlease reselect."<<endl;
							}
							if(color=="GREEN"){
								cout<<"Enter seat (1-4): ";
								cin>>seat;cin.ignore();
								if(seat==1){
									if(sed[1].front!=0){
										current->credit-=5;
										sed[1].front=0;
										quit=!quit;
										break;
									}
									else cout<<"Front seat occupied. Please reselect." << endl;
								}
								if(seat==2){
									if(sed[1].sideback1!=0){
										current->credit-=2;
										sed[1].sideback1=0;
										quit=!quit;
										break;
									}
									else cout<<"Left back seat occupied. Please reselect." << endl;
								}
								if(seat==3){
									if(sed[1].sidemiddle!=0){
										current->credit-=1;
										sed[1].sidemiddle=0;
										quit=!quit;
										break;
									}
									else cout<<"Middle back seat occupied. Please reselect." << endl;
								}
								if(seat==4){
									if(sed[1].sideback2!=0){
										current->credit-=2;
										sed[1].sideback2=0;
										quit=!quit;
										break;
									}
									else cout<<"Right back seat occupied. Please reselect." << endl;
								}else cout << "-INVALID SEAT-\nPlease reselect."<<endl;
							}
							if(color=="BLUE"){
								cout<<"Enter seat (1-4): ";
								cin>>seat;cin.ignore();
								if(seat==1){
									if(sed[2].front!=0){
										current->credit-=5;
										sed[2].front=0;
										quit=!quit;
										break;
									}
									else cout<<"Front seat occupied. Please reselect." << endl;
								}
								if(seat==2){
									if(sed[2].sideback1!=0){
										current->credit-=2;
										sed[2].sideback1=0;
										quit=!quit;
										break;
									}
									else cout<<"Left back seat occupied. Please reselect." << endl;
								}
								if(seat==3){
									if(sed[2].sidemiddle!=0){
										current->credit-=1;
										sed[2].sidemiddle=0;
										quit=!quit;
										break;
									}
									else cout<<"Middle back seat occupied. Please reselect." << endl;
								}
								if(seat==4){
									if(sed[2].sideback2!=0){
										current->credit-=2;
										sed[2].sideback2=0;
										quit=!quit;
										break;
									}
									else cout<<"Right back seat occupied. Please reselect." << endl;
								}else cout << "-INVALID SEAT-\nPlease reselect."<<endl;
							}else{
								cout << "-INVALID COLOR-\nPlease reselect." << endl;
							}
						}
					}else{
						cout<<"-INVALID VEHICLE-\nPlease reselect."<<endl;
					}
				}else{
					cout << "-INVALID SELECTION-\nPlease reselect." << endl;
				}
			}
		}
	}while(!quit);
}

int main()
{
	//Create(head)
	//Display()
	//Modify()
	//Delete()
	//Print()
	//Reservation()

// 	do {
// 		cout << "Menu: " << endl;
// 		cout << "(1)Create Reservation" << setw() << "(2)Display Reservation"  << setw()
// 				<< "(3)Modify Reservation"  << setw() << "(4)Print Reservation"  << setw() << endl;
// 		cout << "(5)Delete Reservation " << setw() << "(6)Print Vehicle Assignment"  << setw() << "(7)Reservation Print" << endl;
// 		cout << "option:";
// 		cin >> option;
// 		switch (option) {
// 		case '1':
// 			create();

// 			break;
// 		case '2':
// 			break;
// 		case '3':
// 			break;
// 		case '4':
// 			break;
// 		case '5':
// 			break;
// 		case '6':
// 			cout << "Enter: " << endl;
// 			cout << "1) Purple Pickup" << right << setw(20)
// 					<< "2) Yellow Pickup" << right << setw(20)
// 					<< "3) Red Pickup" << endl;
// 			cout << "4) Green Compact" << right << setw(19) << "5) Blue Compact"
// 					<< right << setw(25) << "6) Yellow Compact" << endl;
// 			cout << "7) Red Sedan" << right << setw(24) << "8) Green Sedan"
// 					<< right << setw(20) << "9) Blue Sedan" << endl;
// 			cin >> option;
// 			switch (option) {
// 			case '1':
// 				break;
// 			case '2':
// 				();
// 				break;
// 			case '3':
// 				();
			
// 				break;
// 			}

// 		};
// 	} while (true);
	
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
	Create(head,pick,comp,sed);
//	string tmp="Can you Re@d this?";
//	string tmp2;
//	cout<<tmp << endl;
//	for (char x : tmp)
//		tmp+=toupper(x);
//	cout << tmp;
	cout << head->fname << endl;
	cout << head->lname << endl;
	cout << head->credit << endl;
}
