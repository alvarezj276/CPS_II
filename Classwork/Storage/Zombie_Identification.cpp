// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title : Zombie_Identification.cpp
// Course : Computational Problem Solving II (CPET-321)
// Developer : Matthew Chu
// Date : Sept 6 2019 (2191)
// Description : Program to create Zombie Hordes using structures
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

const int SIZE=10;

int main(){
	struct zombie{
		string type;
		char gender;
		int age;
		bool contagious;
	};

	zombie zombie_1={"Crawler", 'M', 45, false};
	zombie zombie_2={"Runner", 'F', 23, true};
	zombie zombie_3={"Shambler", 'M', 42, true};

		cout << "Zombie 1: Is a ";
		if(zombie_1.gender=='M') cout << "Male";
		else cout << "Female";
		cout << " " << zombie_1.type << "; Died @ Age " << zombie_1.age << "; And is ";
		if(zombie_1.contagious==false) cout << "not contagious." << endl;
		else cout << "contagious." << endl;

		cout << "Zombie 2: Is a ";
		if(zombie_2.gender=='M') cout << "Male";
		else cout << "Female";
		cout << " " << zombie_2.type << "; Died @ Age " << zombie_2.age << "; And is ";
		if(zombie_2.contagious==false) cout << "not contagious." << endl;
		else cout << "contagious." << endl;

		cout << "Zombie 3: Is a ";
		if(zombie_3.gender=='M') cout << "Male";
		else cout << "Female";
		cout << " " << zombie_3.type << "; Died @ Age " << zombie_3.age << "; And is ";
		if(zombie_3.contagious==false) cout << "not contagious." << endl;
		else cout << "contagious." << endl;

	return 0;
}
