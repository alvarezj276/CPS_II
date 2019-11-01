// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title: tinetype.cpp
// Course: Computational Problem Solving CPET-II
// Developer: Matthew Chu
// Date : Fall 2019 (2191)
// Description: creating lines in standard form
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <iomanip>
#include <math.h>

using namespace std;

class lineType
{
private:
	float a;
	float b;
	float c;

public:
	lineType(float m=1.0, float l=1.0, float p=1.0){
		a=m;
		b=l;
		c=p;
	};
	void setCoefficient(float m,float l, float p);
	void displayLine();
	void lineSlope();
	void lineIntersection(lineType X, lineType Y);

	bool operator==(lineType);
	bool operator||(lineType);
	bool operator&&(lineType);

};

void lineType::setCoefficient(float m, float l, float p){
	a=m;
	b=l;
	c=p;
};

void lineType::displayLine(){

	float absolute= b;
	char sign='+';
	cout << fixed << setprecision(2);
	cout << a << "x ";
	if(b<0){
		absolute=abs(b);
		sign='-';
	}
	cout << sign << ' ' << absolute <<"y = " << c;
}

void lineType::lineSlope(){
	cout << "slope = ";
	if(a==0) cout << 0 << endl;
	if(b==0) cout << "undefined" << endl;
	else cout << -a/b << endl;
}

void lineType::lineIntersection(lineType X, lineType Y){
	float x,y;
	string ytmp=" undefined";
	cout<< fixed << setprecision(2);
	cout << "x = ";
	if(( X.a!=0 && Y.b!=0) || ( X.b!=0 || Y.a!=0)){
		x=(( X.c*Y.b)-(Y.c* X.b))/(( X.a*Y.b)-(Y.a* X.b));
		cout << x << endl;
		if(Y.b!=0){
			y=(Y.c/Y.b)-((Y.a/Y.b)*x);
			ytmp= " "+to_string(y);
		}
	}
	else cout << "undefined" << endl;
	cout << "y =" << ytmp << endl;
}

bool lineType::operator ==(const lineType X){
	bool equal=false;

	if((X.a==a) && (X.b==b) && (X.c==c)){
		equal=true;
		cout << "==1"<<endl;
	}
	if((fmod(a,X.a)==0) && (fmod(b,X.b)==0) && (fmod(c,X.c)==0)){
		equal=true;
		cout << "==2" << endl;
	}
	cout << equal;
	return equal;
};

bool lineType::operator ||(const lineType X)
{
	bool parallel=false;

	if((X.a==0 && a==0) ||
			(X.b==0 && b==0))
		parallel=true;
	if((-X.a)/X.b == -a/b)
		parallel=true;
	cout << parallel;
	return parallel;
};

bool lineType::operator &&(const lineType X)
{
	bool perpendicular=false;

	if((X.a==0 && b==0) || (X.b==0 && a==0))
		perpendicular=true;
	if((-X.a/X.b)*(-a/b)==-1)
		perpendicular=true;
	cout << perpendicular;
	return perpendicular;
};

int main()
{
	lineType W,X,Y,Z,tmp,tmp2;
	int option;
	float a,b,c;
	char letter,letter2;
	string e="EQUAL",pa="PARALLEL",per="PERPENDICULAR";
	bool equal=true,parallel=true,perpendicular=true,quit=false;
	do{
		cout << "|1|Set\n|2|Display\n|3|Slope\n|4|Equal\n|5|Parallel\n|6|Perpendicular\n|7|Intersection\n|8|Quit";
		cout << "\nSelect an option: ";
		cin >> option; cin.ignore();
		switch(option){
		case 1:
				cout << "|W|   |X|   |Y|   |Z|\nSelect line: ";
				cin >> letter; cin.ignore();
				if(letter=='W'||letter=='w')
					tmp=W;
				if(letter=='X'||letter=='x')
					tmp=X;
				if(letter=='Y'||letter=='y')
					tmp=Y;
				if(letter=='Z'||letter=='z')
					tmp=Z;
				cout << "Enter coefficient a: ";
				cin >> a;
				cout << "Enter coefficient b: ";
				cin >> b;
				cout << "Enter coefficient c: ";
				cin >> c;
				tmp.setCoefficient(a,b,c);
				break;
		case 2:
				cout << "|W|   |X|   |Y|   |Z|\nSelect line: ";
				cin >> letter; cin.ignore();
				if(letter=='W'||letter=='w')
					W.displayLine();
				if(letter=='X'||letter=='x')
					X.displayLine();
				if(letter=='Y'||letter=='y')
					X.displayLine();
				if(letter=='Z'||letter=='z')
					Z.displayLine();
				cout << endl;
			break;
		case 3:
				cout << "|W|   |X|   |Y|   |Z|\nSelect line: ";
				cin >> letter; cin.ignore();
				if(letter=='W'||letter=='w')
					W.lineSlope();
				if(letter=='X'||letter=='x')
					X.lineSlope();
				if(letter=='Y'||letter=='y')
					Y.lineSlope();
				if(letter=='Z'||letter=='z')
					Z.lineSlope();
			break;
		case 4:
				cout << "|W|   |X|   |Y|   |Z|\nSelect line 1: ";
				cin >> letter; cin.ignore();
				if(letter=='W'||letter=='w')
					tmp=W;
				if(letter=='X'||letter=='x')
					tmp=X;
				if(letter=='Y'||letter=='y')
					tmp=Y;
				if(letter=='Z'||letter=='z')
					tmp=Z;
				cout << "|W|   |X|   |Y|   |Z|\nSelect line 2: ";
				cin >> letter2; cin.ignore();
				if(letter2=='W'||letter2=='w')
					tmp2=W;
				if(letter2=='X'||letter2=='x')
					tmp2=X;
				if(letter2=='Y'||letter2=='y')
					tmp2=Y;
				if(letter2=='Z'||letter2=='z')
					tmp2=Z;
				equal=(tmp==tmp2);
				if(equal==false)
					e="NOT "+e;
				cout << letter << " and " << letter2  << " are " << e << endl;
			break;
		case 5:
				cout << "|W|   |X|   |Y|   |Z|\nSelect line 1: ";
				cin >> letter; cin.ignore();
				if(letter=='W'||letter=='w')
					tmp=W;
				if(letter=='X'||letter=='x')
					tmp=X;
				if(letter=='Y'||letter=='y')
					tmp=Y;
				if(letter=='Z'||letter=='z')
					tmp=Z;
				cout << "|W|   |X|   |Y|   |Z|\nSelect line 2: ";
				cin >> letter2; cin.ignore();
				if(letter2=='W'||letter2=='w')
					tmp2=W;
				if(letter2=='X'||letter2=='x')
					tmp2=X;
				if(letter2=='Y'||letter2=='y')
					tmp2=Y;
				if(letter2=='Z'||letter2=='z')
					tmp2=Z;
				parallel=tmp||tmp2;
				if(!parallel)
					e="NOT"+pa;
				cout << letter << " and " << letter2  << " are " << pa << endl;
			break;
		case 6:
				cout << "|W|   |X|   |Y|   |Z|\nSelect line 1: ";
				cin >> letter; cin.ignore();
				if(letter=='W'||letter=='w')
					tmp=W;
				if(letter=='X'||letter=='x')
					tmp=X;
				if(letter=='Y'||letter=='y')
					tmp=Y;
				if(letter=='Z'||letter=='z')
					tmp=Z;
				cout << "|W|   |X|   |Y|   |Z|\nSelect line 2: ";
				cin >> letter2; cin.ignore();
				if(letter2=='W'||letter2=='w')
					tmp2=W;
				if(letter2=='X'||letter2=='x')
					tmp2=X;
				if(letter2=='Y'||letter2=='y')
					tmp2=Y;
				if(letter2=='Z'||letter2=='z')
					tmp2=Z;
				perpendicular=tmp&&tmp2;
				if(!perpendicular)
					e="NOT"+per;
				cout << letter << " and " << letter2  << " are " << per << endl;
			break;
		case 7:
				cout << "|W|   |X|   |Y|   |Z|\nSelect line 1: ";
				cin >> letter; cin.ignore();
				if(letter=='W'||letter=='w')
					tmp=W;
				if(letter=='X'||letter=='x')
					tmp=X;
				if(letter=='Y'||letter=='y')
					tmp=Y;
				if(letter=='Z'||letter=='z')
					tmp=Z;
				cout << "|W|   |X|   |Y|   |Z|\nSelect line 2: ";
				cin >> letter2; cin.ignore();
				if(letter2=='W'||letter2=='w')
					tmp2=W;
				if(letter2=='X'||letter2=='x')
					tmp2=X;
				if(letter2=='Y'||letter2=='y')
					tmp2=Y;
				if(letter2=='Z'||letter2=='z')
					tmp2=Z;
				parallel=tmp||tmp2;
				if(!parallel)
					tmp.lineIntersection(tmp,tmp2);
			break;
		case 8:
			quit=true;
			break;
		}
	}while(quit==false);
	return 0;
}



