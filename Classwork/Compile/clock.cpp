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
		hour=h;
		minute=m;
		second=s;
	};
	void setTime(int h,int m,int s){
		hour=h;
		minute=m;
		second=s;
	};
	friend istream& operator>>(istream& time_in, const clock_18& X){
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
			if(minute>59){
				minute=0;
				hour++;
				if(hour>17){
					hour=0;
					second++;
				}
			}
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
	};
	operator clock_12();
};

class clock_12{
private:
	int hour,minute,second;
public:
	clock_12(int h=0,int m=0,int s=0){
		hour=h;
		minute=m;
		second=s;
	};
	friend istream& operator>>(istream& time_in, const clock_12& X){
		cin >> X.hour;
		cin >> X.minute;
		cin >> X.second;
		return time_in;
	};
	friend ostream& operator<<(ostream& time_out, const clock_12& X){
		cout << setfill('0');
		cout << setw(2) << X.hour << ':';
		cout << setw(2) << X.minute << ':';
		cout << setw(2) << X.second << ':';
		return time_out;
	};
	operator clock_18();
};

clock_18::operator clock_12(){
	int h=hour;
	int m=minute;
	int s=second;
	return clock_12(h,m,s);
};

clock_12::operator clock_18(){
	int h=hour;
	int m=minute;
	int s=second;
	return clock_18(h,m,s);
};

int main(){
	clock_18 startTime,endTime,watchStart,watchEnd;
	clock_12 watchStart_12, watchEnd_12;
}
