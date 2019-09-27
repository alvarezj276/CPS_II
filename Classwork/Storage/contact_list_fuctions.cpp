// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title : contact_list_fuctions.cpp
// Course : Computational Problem Solving II (CPET-321)
// Developer : Matthew Chu
// Date : Fall 2019 (2191)
// Description : Project #3 Contact List
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "contact_list.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>			// needed for file I/O

using namespace std;

bool active=true;

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// menu()
//
//		input 		: void
//		output		: void
//		description : useless code to display the menu over and over...
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void menu(){
	cout << "Contact List Menu: \n";
	cout << "   (R)ead File       (W)rite File        (S)how Contacts  (I)nsert Contact\n";
	cout << "   (D)elete Contact  (U)pdate Contact    (T)oggle ICE     (Q)uit\n\n";
	cout << "Option..... : ";
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// getCount()
//
//		input 		: pointer to the head of the linked-list
//		output		: length of current linked-list
//		description : recursively goes through linked-list and counts number
//					  of contacts to be used for Insert function
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int getCount(contact *head)
{
    if (head == NULL)
        return 0;
    return getCount(head->nextaddr)+1;
}


// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Update()
//
//		input 		: pointer to the head of the linked-list and the
//					  position in the list
//		output		: pointer to the head of the updated linked-list.
//		description : modifies contact information at position specified
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
contact *Update(contact *head, int m){
	contact *current;

	current = head;
	string newname;
	string newnumber;
	string newem;
	char emergency,tmp;

	cout << "Updating Contact:\nEnter name : ";
	getline(cin, newname);
	cout << "Enter cell number: ";
	getline(cin, newnumber);
	cout << "Enter email: ";
	getline(cin, newem);
	do{
		cout << "Add to emergency contacts? (Y/N): \n";
		cin >> emergency; cin.ignore();
		switch(emergency){
		case 'Y':
		case 'y':tmp='1';
		break;
		case 'N':
		case 'n':tmp='0';
		break;
		}
		if(tmp=='0' || tmp=='1')
			break;
	}while(true);
	if (m==1)
	{
		head->name = newname;
		head->cellnumber=newnumber;
		head->email=newem;
		head->ICE=tmp;
	}
	else
	{
		for (int i=1; i<m; i++){
			current = current->nextaddr;
		}
		current->name=newname;
		current->cellnumber=newnumber;
		current->email=newem;
		current->ICE=tmp;
	}
	return (head);
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Toggle()
//
//		input 		: pointer to the head of the linked-list and the
//					  position in the list
//		output		: void
//		description : toggles ICE for contact specified
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Toggle(contact *head, int m){
	contact *current;

	current = head;

	for (int i=1; i<m; i++){
		current = current->nextaddr;
	}
	current->ICE=!current->ICE;

}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// quit()
//
//		input 		: void
//		output		: void
//		description : terminates the program
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void quit(){
	active=!active;
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Show()
//
//		input 		: pointer to head of list
//		output		: void
//		description : displays the contact information in the linked-list
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Show(contact *head)
{
	int cnt = 1;
	contact *current = head;
cout<<current->name<<endl;
	while (current != NULL){
		cout << right << setw(4) << cnt++ << ")  ";
		cout << left << setw(20) << current->name << left << setw(15) << current->cellnumber << left << setw(20) << current->email;
		if(current->ICE==1)
			cout << right << setw(21) << "<--- Emergency Contact";
		cout << "\n";
		current = current->nextaddr;
	}
	return;
}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Read()
//
//		input 		: void
//		output		: pointer to the head of the linked-list
//		description : reads the content of the file "contacts.txt" and
//					  builds the linked-list
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
contact *Read()
{
	ifstream inFile;

	inFile.open("contacts.txt");

	if (inFile.fail())
	{
		cout << "\nThe file did not successfully open... Program Terminated\n" << endl;
		exit (1);
	}
	contact *current, *head;

	current = new contact;
	head = current;

	do
	{
		getline(inFile, current->name);
		getline(inFile,current->cellnumber);
		getline(inFile,current->email);
		inFile>>current->ICE; inFile.ignore();

		if (inFile.eof())
		{
			current->nextaddr = NULL;
			break;
		}
		else
		{
			current->nextaddr = new contact;
			current = current->nextaddr;
		}
	}
	while (true);
	inFile.close();

	return (head);
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Write()
//
//		input 		: pointer to the head of the linked-list
//		output		: void
//		description : writes content of linked-list to output file
//					  "contacts_updated.txt"
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Write(contact *head)
{
	contact *current;
	current = head;
	if(head==NULL){
		current=Read();
	}
	ofstream outFile;
	outFile.open ("contacts_updated.txt");
	while(current->nextaddr != NULL){
		outFile<<current->name << endl;
		outFile<<current->cellnumber << endl;
		outFile<<current->email << endl;
		outFile<<current->ICE << endl;
		current=current->nextaddr;
	}
	outFile.close();
}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Delete()
//
//		input 		: pointer to the head of the linked-list and the
//					  position in the list
//		output		: pointer to the head of the updated linked-list.
//		description : deletes the contact at the postion entered.
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
contact *Delete(contact *head, int m)
{

	contact *current, *previous;

	current = head;

	if (m==1)
	{
		head = current->nextaddr;
	}
	else
	{
		for (int i=1; i<m; i++)
		{
			previous = current;
			current = current->nextaddr;
		}
		previous->nextaddr = current->nextaddr;
	}
	delete(current);
	return(head);
}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Insert()
//
//		input 		: pointer to the head of the linked-list and the
//					  position in the list
//		output		: pointer to the head of the updated linked-list.
//		description : inserted new contact at the postion entered.
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
contact *Insert(contact *head, int m)
{

	contact *current, *previous, *tmp;

	current = head;
	char emergency;

	tmp = new contact;
	cout << "New Contact:\nEnter name : \n";
	getline(cin, tmp->name);
	cout << "Enter cell number: \n";
	getline(cin, tmp->cellnumber);
	cout << "Enter email: \n";
	getline(cin, tmp->email);
	do{
		cout << "Add to emergency contacts? (Y/N): \n";
		cin >> emergency; cin.ignore();
		switch(emergency){
		case 'Y':
		case 'y':tmp->ICE=1;
				  break;
		case 'N':
		case 'n':tmp->ICE=0;
				  break;
		}
		if(tmp->ICE==0 || tmp->ICE==1)
			break;
	}while(true);

	if (m==1)
	{
		tmp->nextaddr = current;
		head = tmp;
	}
	else{
		if(m==(getCount(head)+1)){

			current=head;
			while(current->nextaddr != NULL)
				current=current->nextaddr;
			current->nextaddr=tmp;
			tmp->nextaddr=NULL;
		}
		else
		{
			for (int i=1; i<m; i++)
			{
				previous = current;
				current = current->nextaddr;
			}
			tmp->nextaddr = current;
			previous->nextaddr = tmp;

		}
	}

	return (head);
}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
