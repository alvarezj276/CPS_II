// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 		Read()
//		input 		: n/a
//		output		: a pointer to the head of the song linked-list
//		description : reads song info from billboard txt file and inputs the info
//					  to the song linked-list
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <iostream>
#include <fstream>			// needed for file I/O
#include <cstdlib>			// needed for exit()
#include "SongHeader.h"

song *Read(){
	ifstream inFile;

	inFile.open("billboard.txt");

	if (inFile.fail())
	{
		cout << "\nThe file did not successfully open... Program Terminated\n" << endl;
		exit (1);
	}

	song *current, *head;

	current = new song;
	head = current;

	do
	{
		getline(inFile, current->name);
		getline(inFile, current->artist);
		inFile >> current->rank; inFile.ignore();
		inFile >> current->year; inFile.ignore();
		inFile >> current->decade;inFile.ignore();
		inFile >> current->performer; inFile.ignore();
		inFile >> current->genre; inFile.ignore();

		if (inFile.eof())
		{
			current->nextaddr = NULL;
			break;
		}
		else
		{
			current->nextaddr = new song;
			current = current->nextaddr;
		}

	}
	while(true);

	inFile.close();

	return(head);
}
