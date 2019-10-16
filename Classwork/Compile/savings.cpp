// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 		savings.cpp
//		description : creates circle using classes
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>			// needed for file I/O
#include <cstdlib>			// needed for exit()
#include <math.h>

using namespace std;

class Savings{
	private: double balance, rate, interest;
	public: Savings(double=0.0, double=0.0);
		void SetValues(double, double);
		void DisplaySavings();
};

Savings::Savings(double b, double r){
	balance=b;
	rate=r;
	interest=balance*(rate/100);
}

void Savings::SetValues(double b, double r){
	balance=b;
	rate=r;
	interest=b*(r/100);
}

void Savings::DisplaySavings(){
	cout << "Balance = " << fixed << setprecision(2) << balance <<
			" | Rate = " << setprecision(2) << rate <<
			" | Interest = " << setprecision(2) << interest << "\n";
}
int main(){
	Savings s1,s2(3456.78,8.9);

	s1.SetValues(1500.00,3.5);
	s1.DisplaySavings();

	s2.DisplaySavings();

	return 0;
}
