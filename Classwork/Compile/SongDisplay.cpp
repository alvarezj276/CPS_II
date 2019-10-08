/*
 * SongDisplay.cpp
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

void Display(playlist *head[], int list, string plname){
	playlist *current;
	bool check = false;

	for(int i=0;i<5;i++)
	{

		cout << "test #" << i << endl;
		cout << "entered playlist name: " << plname << endl;
		cout << "check :: " << head[i]->name << endl;

		if(plname == head[i]->name){
			cout << "test" << endl;
			current=head[i];

			check=true;
			break;
		}
	}



	if (check){
		cout << plname<< ":\n____________________________________\n";
		if(current==NULL)
			cout<<"Playlist empty"<<endl;
		else{
			int i=1;
			while(current != NULL){

				cout << "#" << i << "." << endl;
				cout << "Song: "<< current->item->name << endl;
				cout << "Artist: " << current->item->artist<< endl;
				cout << "Billboard Ranking (#): " << current->item->rank<< endl;
				cout << "Year of Release: " << current->item->year << endl;
				cout << "Song Decade: " << current->item->decade<< endl;
				cout << "Song Performer: " << current->item->performer<< endl;
				cout << "Song Genre (#): " << current->item->genre << endl;
				cout << "------------------------------------\n";

				current = current->nextaddr;
				i++;
			}
		}
	}
	else{
		cout << "Playlist name not found" << endl;
		//current = current->nextaddr;
	}
}




