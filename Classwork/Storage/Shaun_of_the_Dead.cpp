// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title : Shaun_of_the_Dead.cpp
// Course : Computational Problem Solving II (CPET-321)
// Developer : Matthew Chu
// Date : Sept 6 2019 (2191)
// Description : Program to spawn Zombie Hordes using structures
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

const int SIZE=50;

struct zombie{
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// Name : zombie
	// Purpose : instantiates zombie information
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	string type;
	char gender;
	int age;
	bool contagious;
};
zombie horde[SIZE];
string type[5]={"Crawler","Runner","Walker","Shambler","Spitter"};
char gender[2]={'M','F'};
bool contag;

void Display_Zombie(zombie tmp){
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// Name : Display_Zombie()
	// Input : zombie tmp
	// Output : none
	// Purpose : prints zombie
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	if(tmp.gender=='M') cout << "Male";
	else cout << "Female";
	cout << " " << tmp.type << "; Died @ Age " << tmp.age << "; And is ";
	if(tmp.contagious==false) cout << "not contagious." << endl;
	else cout << "contagious." << endl;
}

zombie Spawn_Zombie(){
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// Name : Spawn_Zombie()
	// Input : None
	// Output : zombie
	// Purpose : creates a randomized zombie
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	zombie tmp;
	int age=rand()%75+1;
	int test=rand()%2+1;
	if(test==1) contag=false;
	else contag=true;
	tmp={type[rand()%5], gender[rand()%2], age, contag};
	return tmp;
}

int main(){
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// Name : main()
	// Input : None
	// Output : void
	// Purpose : creates and prints zombies
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	int i=0;
	srand(time(NULL));
	while (i<SIZE){
		horde[i]=Spawn_Zombie();
		cout << "Zombie [" << i << "]: Is a ";
		Display_Zombie(horde[i]);
		i++;
	}
	return 0;
}
