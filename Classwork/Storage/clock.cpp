// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title: clock.cpp
// Course: Computational Problem Solving CPET-II
// Developer: Matthew Chu
// Date : Fall 2019 (2191)
// Description: Project #6
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <iomanip>
#include <math.h>

using namespace std;

class clock_12;
class clock_18{
private:
	int hour;
	int minute;
	int second;
public:
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// Name: clock_18
	// Input: int hour, int minute, int second
	// Output : none
	// Purpose: construct 18 hour clock with initial values
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	clock_18(int h=0,int m=0,int s=0){
		if(s>59){
			s=0;
			m++;
		}
		if(m>59){
			m=0;
			h++;
		}
		if(h>17)
			h=0;
		hour=h;
		minute=m;
		second=s;
	};
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// Name: setTime
	// Input: int hour, int minute, int second
	// Output : none
	// Purpose: set 18 hour clock
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	void setTime(int h,int m,int s){
		if(s>59){
			s=0;
			m++;
		}
		if(m>59){
			m=0;
			h++;
		}
		if(h>17)
			h=0;
		hour=h;
		minute=m;
		second=s;
	};
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// Name: operator>>
	// Input: istream& time_in, clock_18& X
	// Output : istream& time_in
	// Purpose: overload >> to set clock_18 hour,minute,second
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	friend istream& operator>>(istream& time_in, clock_18& X){
		cin >> X.hour;
		cin >> X.minute;
		cin >> X.second;
		return time_in;
	};
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// Name: operator<<
	// Input: ostream& time_out, const clock_18& X
	// Output : ostream& time_out
	// Purpose: overload << to print clock_18 hour,minute,second
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	friend ostream& operator<<(ostream& time_out, const clock_18& X){
		cout << setfill('0');
		cout << setw(2) << X.hour << ':';
		cout << setw(2) << X.minute << ':';
		cout << setw(2) << X.second << endl;
		return time_out;
	};
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// Name: operator++
	// Input: none
	// Output : clock_18
	// Purpose: increments clock by second
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	clock_18& operator++(){
		second++;
		if(second>59){
			second=0;
			minute++;
		}
		if(minute>59){
			minute=0;
			hour++;
		}
		if(hour>17){
			hour=0;
			second++;
		}
		return *this;
	};
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// Name: operator==
	// Input: const clock_18& X
	// Output : bool equal
	// Purpose: checks that time is equal
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	bool operator==(const clock_18& X){
		bool equal=false;
		if((hour==X.hour) && (minute==X.minute) && (second==X.second))
			equal=true;
		return equal;
	};
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// Name: operator<
	// Input: const clock_18& X
	// Output : bool less
	// Purpose: checks that first clock is < second clock
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	bool operator<(const clock_18& X){
		bool less=false;
		int t1=(hour*10000)+(minute*100)+second;
		int t2=(X.hour*10000)+(X.minute*100)+X.second;
		if(t1<t2)
			less=true;
		return less;
	};
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// Name: operator>
	// Input: const clock_18& X
	// Output : bool greater
	// Purpose: checks that first clock is > second clock
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	bool operator>(const clock_18& X){
		bool greater=false;
		int t1=(hour*10000)+(minute*100)+second;
		int t2=(X.hour*10000)+(X.minute*100)+X.second;
		if(t1>t2)
			greater=true;
		return greater;
	};
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// Name: operator long
	// Input: none
	// Output : long tmp
	// Purpose: converts clock to long number
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	operator long(){
		long tmp=(hour*3600)+(minute*60)+second;
		return tmp;
	};
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// Name: clock_18
	// Input: long X
	// Output : none
	// Purpose: sets clock_18 using long number
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	clock_18(long X){
		hour=X/3600;
		minute=(X-(hour*3600))/60;
		second=X-(hour*3600)-(minute*60);
		if(second>59){
			second-=60;
			minute++;
		}
		if(minute>59){
			minute=0;
			hour++;
		}
		if(hour>17){
			hour=0;
			second++;
		}
	};
	operator clock_12();
};

class clock_12{
private:
	int hour,minute,second;
	char meridiem;
public:
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// Name: clock_12
	// Input: int hour, int minute, int second, char meridiem
	// Output : none
	// Purpose: constructs clock_12 with initial values
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	clock_12(int h=0,int m=0,int s=0, char t='a'){
		hour=h;
		minute=m;
		second=s;
		meridiem=t;
	};
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// Name: operator>>
	// Input: istream& time_in, clock_12& X
	// Output : istream& time_in
	// Purpose: overload >> to set clock_12
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	friend istream& operator>>(istream& time_in, clock_12& X){
		cin >> X.hour;
		cin >> X.minute;
		cin >> X.second;
		cin >> X.meridiem;
		return time_in;
	};
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// Name: operator>>
	// Input: ostream& time_out, clock_12& X
	// Output : ostream& time_out
	// Purpose: overload << to set clock_12
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	friend ostream& operator<<(ostream& time_out, const clock_12& X){
		cout << setfill('0');
		cout << setw(2) << X.hour << ':';
		cout << setw(2) << X.minute << ':';
		cout << setw(2) << X.second << ' ';
		if(X.meridiem=='a')
			cout << setw(2) << "AM" << endl;
		else
			cout << setw(2) << "PM" << endl;
		return time_out;
	};
	operator clock_18();
};

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Name: clock_12
// Input: none
// Output : clock_12
// Purpose: converts clock_18 to clock_12
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
clock_18::operator clock_12(){
	int h=hour;
	int m=minute;
	int s=second;
	char t='a';
	if(hour >= 12){
		t='p';
		if(hour>12)
			h=hour-12;
	}
	return (clock_12(h,m,s,t));
};

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Name: clock_18
// Input: none
// Output : clock_18
// Purpose: converts clock_12 to clock_18
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
clock_12::operator clock_18(){
	int h=hour;
	int m=minute;
	int s=second;
	if(meridiem=='p')
		if(hour > 12)
			h=hour+12;
	return (clock_18(h,m,s));
};

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Name: main
// Input: none
// Output : none
// Purpose: runs program
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int main(){
	long t;
	clock_18 startTime,endTime,watchStart,watchEnd,timer;
	clock_12 watchStart_12, watchEnd_12;
	bool clock=true;
	do{
		cout << "Enter start time: ";
		cin >> startTime;
		cout << "Enter end time: ";
		cin >> endTime;
		cout << "Enter starting watch: ";
		cin >> watchStart;
		cout << "Enter ending watch: ";
		cin >> watchEnd;
		if((long(endTime) > long(startTime)) && (long(watchStart) < long(watchEnd))
				&& (long(watchStart) > long(startTime)) && (long(watchStart) < long(endTime))
				&& (long(watchEnd) < long(endTime)) && (long(watchEnd) > long(startTime))){
			while(startTime!=endTime){
				long start=long(startTime);
				if(start < long(watchStart))
					cout << "Sleeping | " ;
				if((start >= long(watchStart)) && (start<= watchEnd))
					cout << "On Watch | " ;
				if(start > long(watchEnd))
					cout << "Off-Duty | " ;
				cout << startTime;
				++startTime;
			}
			clock=false;
		}
		else
			cout << "Time incorrect, please re-enter values" << endl;
	}while(clock);
//	watchStart_12 = clock_12(&watchStart);
//	watchEnd_12 = clock_12(&watchEnd);
	cout << "\nSummary:\n---------------------------\nWatch Start (18) | ";
	cout << watchStart << endl;
	cout << "Watch End(18) | ";
	cout << watchEnd << endl;
//	cout << "Watch Start (12) | ";
//	cout << watchStart_12;
//	cout << "Watch End(12) | ";
//	cout << watchEnd_12;
	t=long(watchEnd)-long(watchStart);
	clock_18 finalTime(t);
	cout << "Total time | ";
	cout << finalTime << endl;
}
