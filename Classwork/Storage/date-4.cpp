// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title: date-1.cpp
// Course: Computational Problem Solving CPET-II
// Developer: Dr G.H. Zion
// Date : Fall 2019 (2191)
// Description: Example of Date : I/O using ShowData()
//
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <iostream>			// cin & cout
#include <iomanip>			// I/O formating
#include <cmath>			// math functions
using namespace std;

class Date
{
  private:
    int month;
    int day;
    int year;

   public:
    Date(int mm = 1, int dd = 1, int yyyy = 2015)
      {month = mm; day = dd; year = yyyy;}

    void setDate(int mm, int dd, int yy)
      {month = mm; day = dd; year = yy;}

    void showDate();

    friend ostream& operator<<(ostream&, const Date&);
    friend istream& operator>>(istream&, Date&);
    operator long();
};

Date::operator long(){
	long date= (year*10000)+(day*100)+month;
	return date;
};

istream& operator >>(istream& X, Date& Y)
{
	cin >> Y.month;
	cin >> Y.day;
	cin >> Y.year;
	return X;
};
ostream& operator <<(ostream& X, const Date& Y)
{
	cout << setfill('0');
	cout << setw(2) << Y.month << '/' << setw(2) << Y.day;
	cout << '/' << setw(2) << Y.year % 100 << endl;
	return X;
};

void Date::showDate()
{
	cout << setfill('0');
	cout << setw(2) << month << '/' << setw(2) << day;
	cout << '/' << setw(2) << year % 100 << endl;
}

int main()
{
	Date a(12,18,2012), b,c,d;

	cout << "Date A = ";
//	a.showDate();
	cout << a;

	b.setDate(9,25,2017);
	cout << "Data B = ";
//	b.showDate();
	cout << b;

	cout << "Enter C\n";
	cin >> c;
	cout << c;

	return 0;
}
