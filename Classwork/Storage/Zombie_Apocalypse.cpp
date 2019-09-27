// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title : Zombie_Apocalypse.cpp
// Course : Computational Problem Solving II (CPET-321)
// Developer : Matthew Chu
// Date : Sept 6 2019 (2191)
// Description : Program to create Zombie Apocalypse using structures
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

const int SIZE=10;

struct zombie{
	string type;
	char gender;
	int age;
	bool contagious;
};

void Display_Zombie(zombie tmp){
	if(tmp.gender=='M') cout << "Male";
	else cout << "Female";
	cout << " " << tmp.type << "; Died @ Age " << tmp.age << "; And is ";
	if(tmp.contagious==false) cout << "not contagious." << endl;
	else cout << "contagious." << endl;

}

int main(){

	zombie horde[SIZE]={{"Crawler", 'M', 45, false},
			{"Runner", 'F', 23, true},
			{"Shambler", 'M', 42, true},
			{"Thriller", 'M', 15, true},
			{"Sleeper", 'F', 58, false},
			{"Walker", 'M', 41, true},
			{"Spitter", 'F', 31, true},
			{"Chaser", 'F', 37, false},
			{"Runner", 'M', 25, true},
			{"Crawler", 'F', 30, true}};

	for (int i=0;i<SIZE;i++){
		cout << "Zombie [" << i << "]: Is a ";
		Display_Zombie(horde[i]);
	}

	return 0;
}
