// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 		Save()
//		input 		: a pointer to the head of the play list linked-list and
//					  name of the play list, name of output file
//		output		: n/a
//		description : prints play list content out to a text file
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <iostream>
#include <fstream>			// needed for file I/O
#include "SongHeader.h"

void Save(playlist *head[], string name,string playlistname, int list) {


	playlist *current;
	bool valid_name=false;
	cout << "save" << endl;
	for(int i=0;i<5;i++)
	{
		if(head[i]==NULL)
			break;
		if(playlistname == head[i]->name){
			current=head[i];
			valid_name=true;
			break;
		}
	}
	name += ".txt";
	if(valid_name){
		ofstream outFile;
		outFile.open(name);
		cout << "file out" << endl;
		if(current==NULL)
			outFile<<"Playlist empty"<<endl;
		else{
			outFile << current->name << ":\n____________________________________\n";
			while (current->nextaddr != NULL)
			{
				outFile<< "Song: "<< current->item->name << endl;
				outFile<< "Artist: " << current->item->artist << endl;
				outFile<< "Billboard Ranking (#): " << current->item->rank << endl;
				outFile<< "Year of Release: " << current->item->year << endl;
				outFile<< "Song Decade: " << current->item->decade << endl;
				outFile<< "Song Performer: " << current->item->performer << endl;
				outFile<< "Song Genre (#): " << current->item->genre << endl;
				outFile<< "------------------------------------\n";

				current=current->nextaddr;
			}
		}
		outFile.close();
	}
	else cout << "Name does not match available playlists" << endl;
	return;
}
