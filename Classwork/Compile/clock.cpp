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
	void setTime(int h,int m,int s){
		hour=h;
		minute=m;
		second=s;
	};
	friend istream& operator>>(istream& time_in, clock_18& X){
		cin >> X.hour;
		cin >> X.minute;
		cin >> X.second;
		return time_in;
	};
	friend ostream& operator<<(ostream& time_out, const clock_18& X){
		cout << setfill('0');
		cout << setw(2) << X.hour << ':';
		cout << setw(2) << X.minute << ':';
		cout << setw(2) << X.second << ':';
		return time_out;
	};
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
	bool operator==(const clock_18& X){
		bool equal=false;
		if((hour==X.hour) && (minute==X.minute) && (second==X.second))
			equal=true;
		return equal;
	};
	bool operator<(const clock_18& X){
		bool less=false;
		int t1=(hour*10000)+(minute*100)+second;
		int t2=(X.hour*10000)+(X.minute*100)+X.second;
		if(t1<t2)
			less=true;
		return less;
	};
	bool operator>(const clock_18& X){
		bool greater=false;
		int t1=(hour*10000)+(minute*100)+second;
		int t2=(X.hour*10000)+(X.minute*100)+X.second;
		if(t1>t2)
			greater=true;
		return greater;
	};
	operator long(){
		long tmp=((int)hour*3600)+((int)minute*60)+(int)second;
		return tmp;
	};
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
	clock_12(int h=0,int m=0,int s=0, char t='a'){
		hour=h;
		minute=m;
		second=s;
		meridiem=t;
	};
	friend istream& operator>>(istream& time_in, clock_12& X){
		cin >> X.hour;
		cin >> X.minute;
		cin >> X.second;
		cin >> X.meridiem;
		return time_in;
	};
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

clock_12::operator clock_18(){
	int h=hour;
	int m=minute;
	int s=second;
	if(meridiem=='p')
		if(hour > 12)
			h=hour+12;
	return (clock_18(h,m,s));
};

int main(){
	long t,start,end;
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
		if((long(endTime) < long(startTime)) && (long(watchStart) < long(watchEnd))
				&& (long(watchStart) > long(startTime)) && (long(watchStart) < long(endTime))
				&& (long(watchEnd) < long(endTime)) && (long(watchEnd) > long(startTime))){
			do{
				start=long(startTime);
				end=long(endTime);
				if(start < long(watchStart))
					cout << "Sleeping | ";
				if((start >= long(watchStart)) && (start<= watchEnd))
					cout << "On Watch | ";
				if(start > long(watchEnd))
					cout << "Off-Duty | ";
				cout << startTime;
				++startTime;
			}while(startTime!=endTime);
			clock=false;
		}
		else
			cout << "Time incorrect, please re-enter values" << endl;
	}while(clock);
	watchStart_12 = clock_12(watchStart);
	watchEnd_12 = clock_12(watchEnd);
	cout << "Summary:\nWatch Start (18) | ";
	cout << watchStart;
	cout << "Watch End(18) | ";
	cout << watchEnd;
	cout << "Watch Start (12) | ";
	cout << watchStart_12;
	cout << "Watch End(12) | ";
	cout << watchEnd_12;
	t=long(watchEnd)-long(watchStart);
	clock_18 finalTime(t);
	cout << "Total time | ";
	cout << finalTime;
}
