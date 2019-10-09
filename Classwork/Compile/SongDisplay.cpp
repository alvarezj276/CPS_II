// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 		Display()
//		input 		: a pointer to the head of the play list linked-list and
//					  name of the play list
//		output		: n/a
//		description : displays songs in specific play lists
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <iostream>
#include <iomanip>
#include "SongHeader.h"

void Display(playlist *head[], int list, string plname){
	playlist *current;
	bool check = false;

	for(int i=0;i<5;i++)
	{
		if(plname == head[i]->name){
			current=head[i];
			check=true;
			break;
		}
	}
	if (check){
		cout << plname<< ":\n________________________________________________________________________\n";
		if(current==NULL)
			cout<<"Playlist empty"<<endl;
		else{
			int i=1;
			while(current != NULL){

				cout << "SONG #" << i << "." << endl;
				cout << "Song: "<< current->item->name << endl;
				cout << "Artist: " << current->item->artist<< endl;
				cout << "Billboard Ranking (#)" << " | " << "Year of Release" << " | " << "Song Decade" << " | " << "Performer Type" << " | " << "Genre" << endl;
				cout << setw(10) <<current->item->rank  << setw(24) << current->item->year << setw(16) << current->item->decade  << setw(14)<<current->item->performer  << setw(12)<<current->item->genre << endl;
				cout << "------------------------------------------------------------------------------\n";

				current = current->nextaddr;
				i++;
			}
		}
	}
	else{
		cout << "PLAYLIST NOT FOUND PLEASE TRY AGAIN" << endl;
	}
}
