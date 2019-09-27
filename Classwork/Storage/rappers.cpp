// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title : rappers.cpp
// Course : Computational Problem Solving II (CPET-321)
// Developer : Dr G. H. Zion
// Date : Fall 2019 (2191)
// Description : Linked-List of rappers' names read from a external file
//				 named "rapper_names.txt".  After displaying the list the
//				 user is prompted to add a new name and then to delete a
//				 nane from the list.
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>			// needed for file I/O
#include <cstdlib>			// needed for exit()

using namespace std;

struct RapperType
{
  string name;
  RapperType *nextaddr;
};

void display_rappers(RapperType *head);

void modify_rapper(RapperType *head, int m);

RapperType *read_rappers();

RapperType *delete_rapper(RapperType *head, int m);

RapperType *insert_rapper(RapperType *head, int m);

int main()
{
	RapperType *main_head;

	int n;

	main_head = read_rappers();
	display_rappers(main_head);

	cout << "Insert Rapper @ Position (n) :";
	cin >> n; cin.ignore();

	main_head = insert_rapper(main_head, n);
	display_rappers(main_head);

	cout << "Delete Rapper @ Position (n) :";
	cin >> n; cin.ignore();

	main_head = delete_rapper(main_head, n);
	display_rappers(main_head);

	cout<<"Modify Rapper @ Position (n) :";
	cin>>n;cin.ignore();

	modify_rapper(main_head, n);
	display_rappers(main_head);

	return 0;
}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


void modify_rapper(RapperType *head, int m){
	RapperType *current;// *previous;
	string tmp;

	current = head;
	cout << "Enter new Rapper Name: ";
	getline(cin, tmp);

	if (m==1)
	{
		head->name = tmp;
	}
	else
	{
		for (int i=1; i<m; i++){
			current = current->nextaddr;
		}
		current->name=tmp;
	}
}


// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// display_rappers()
//
//		input 		: pointer to head of list
//		output		: void
//		description : displays the rappers' names in the linked-list
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void display_rappers(RapperType *head)
{
	int cnt = 1;

	RapperType *current = head;

	cout << "Rapper Names:" << endl;

	while (current != NULL)
	{
		cout << right << setw(4) << cnt++ << ")  ";
		cout << left << setw(20) << current->name << endl;
		current = current->nextaddr;
	}
	cout << endl;

	return;
}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// read_rappers()
//
//		input 		: N/A
//		output		: pointer to the head of the linked-list
//		description : reads the content of the file "rapper_names.txt" and
//					  builds the linked-list
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
RapperType *read_rappers()
{
	ifstream inFile;

	inFile.open("rapper_names.txt");

	if (inFile.fail())
	{
		cout << "\nThe file did not successfully open... Program Terminated\n" << endl;
		exit (1);
	}

	RapperType *current, *head;

	current = new RapperType;
	head = current;

	do
	{
		getline(inFile, current->name);

		if (inFile.eof())
		{
			current->nextaddr = NULL;
			break;
		}
		else
		{
			current->nextaddr = new RapperType;
			current = current->nextaddr;
		}
	}
	while (true);

	inFile.close();

	return (head);
}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// delete_rapper()
//
//		input 		: pointer to the head of the linked-list and the
//					  position in the list where the name is to be deleted.
//		output		: pointer to the head of the updated linked-list.
//		description : deletes the rapper's name at the postion entered.
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
RapperType *delete_rapper(RapperType *head, int m)
{

	RapperType *current, *previous;

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
// insert_rapper()
//
//		input 		: pointer to the head of the linked-list and the
//					  position in the list where the name is to be deleted.
//		output		: pointer to the head of the updated linked-list.
//		description : inserted the rapper's name at the postion entered.
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

RapperType *insert_rapper(RapperType *head, int m)
{

	RapperType *current, *previous, *tmp;

	current = head;

	tmp = new RapperType;
	cout << "Rapper's Name : ";
	getline(cin, tmp->name);

	if (m==1)
	{
		tmp->nextaddr = current;
		head = tmp;
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
	return (head);
}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

