// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title : contact_list.cpp
// Course : Computational Problem Solving II (CPET-321)
// Developer : Matthew Chu
// Date : Fall 2019 (2191)
// Description : Project #3 Contact List
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <iostream>
#include <string>
#include <iomanip>
#include "contact_list.h"

using namespace std;

int main(){
	char entry;
	contact *main_head;
	int n;
	do{
		menu();
		cin>>entry;cin.ignore();
		switch(entry){
		case 'R':
		case 'r':main_head=Read();
				break;
		case 'W':
		case 'w':Write(main_head);
				break;
		case 'S':
		case 's':Show(main_head);
				break;
		case 'I':
		case 'i':cout << "Insert @ entry number: ";
				cin >> n; cin.ignore();
				main_head=Insert(main_head,n);
			break;
		case 'D':
		case 'd':cout << "Delete entry number: ";
				cin >> n; cin.ignore();
				main_head=Delete(main_head,n);
			break;
		case 'U':
		case 'u':cout << "Update entry number: ";
				cin >> n; cin.ignore();
				main_head=Update(main_head,n);
				break;
		case 'T':
		case 't':cout << "Toggle Emergency Contact @ Entry number: ";
				cin >> n;cin.ignore();
				Toggle(main_head,n);
				break;
		case 'Q':
		case 'q':cout << "Exiting program...\n\n\n\n Goodbye!" << endl;
				quit();
				break;
		}
	}while(active);
	quit();
	return 0;
}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
