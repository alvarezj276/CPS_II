/*
 * SongRead.cpp
 *
 *  Created on: Oct 6, 2019
 *      Author: meran
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>			// needed for file I/O
#include <cstdlib>			// needed for exit()

using namespace std;
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

