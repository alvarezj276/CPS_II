/*
 * SongModify.cpp
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

playlist *Modify(string plname, int list, playlist *head[]){
	bool check = false;
	int match;
	playlist *current_playlist,*previous_playlist, *head_playlist, tmp_playlist;
	song *current_song, *new_song;

	char userchoice;
	int rank, position;

	for(int i=0;i<5;i++)
	{

		cout << "test #" << i << endl;
		cout << "entered playlist name: " << plname << endl;
		cout << "check :: " << head[i]->name << endl;

		if(plname == head[i]->name){
			cout << "test" << endl;
			current_playlist=head[i];
			match =i;
			check=true;
			break;
		}
	}


	if(check){
		while(check)
		{
			//current = just;
			cout << "Insert (I) or Delete (D): "; cin >> userchoice;

			switch(userchoice)
			{
				///insert isnt working
			case 'I':
				cout << "Enter the Rank of the song you would like added to the playlist: "; cin >>rank;
				cout << "Enter the position you would like the song placed: "; cin >> position;

				//				while((songcurrent->rank) < n){
				//								songcurrent = songcurrent->nextaddr;
				//							}

				new_song = new song;

				new_song->name = current_song->name;
				new_song->artist = current_song->artist;
				new_song->rank = current_song->rank;
				new_song->year = current_song->year;
				new_song->decade = current_song->decade;
				new_song->performer = current_song->performer;
				new_song->genre = current_song->genre;

				if (position==1)
				{
					//new_song->nextaddr = current_playlist->item;
					head[match]->item = new_song;
				}
				else
				{
					for (int i=1; i<position; i++)
					{
						previous_playlist = current_playlist;
						current_playlist = current_playlist->nextaddr;
					}
					new_song->nextaddr = current_playlist->item;
					previous_playlist->item->nextaddr = new_song;
				}



				if (position==1)
				{
					//tmp->nextaddr = current;
					head[match] = new_song;
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





				check = false;
				break;


			case 'D':
				cout << "Enter the position of the song you would like deleted: "; cin >>position;

				if (position==1)
				{
					head[match] = current_playlist->nextaddr;
				}
				else
				{
					for (int i=1; i<position; i++)
					{
						previous_playlist = current_playlist;
						current_playlist = current_playlist->nextaddr;
					}
					previous_playlist->nextaddr = current_playlist->nextaddr;
				}
				delete(current_playlist);
				check = false;
				break;
			}
		}
		return(head[match]);
	}
	else{
		cout << "Name does not match available playlists"<<endl;
		return(NULL);
	}
}
