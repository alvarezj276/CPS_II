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

playlist *Modify(string plname, int list, playlist *head[], song *head_song){
	bool check = false;
	int match;
	playlist *current_playlist,*previous_playlist, *tmp_playlist=new playlist;
	song *current_song=head_song;

	char userchoice;
	int rank, position;

	for(int i=0;i<5;i++){
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
//	if(check){
		while(check)
		{
			cout << "Insert (I) or Delete (D): "; cin >> userchoice;
			switch(userchoice)
			{
			case 'I':
				cout << "Enter the Rank of the song you would like added to the playlist: "; cin >>rank;
				if(rank<10)
					cin.ignore();
				cout << "Enter the position you would like the song placed: "; cin >> position;
				if(position<10)
					cin.ignore();
				while(current_song != NULL){
					if(current_song->rank==rank)
						break;
					current_song=current_song->nextaddr;
				}
//				new_song->name = current_song->name;
//				new_song->artist = current_song->artist;
//				new_song->rank = current_song->rank;
//				new_song->year = current_song->year;
//				new_song->decade = current_song->decade;
//				new_song->performer = current_song->performer;
//				new_song->genre = current_song->genre;

				if (position==1)
				{
					tmp_playlist->item=current_song;
					tmp_playlist->nextaddr=head[match];
					tmp_playlist->name=head[match]->name;
					head[match]=tmp_playlist;
				}
				else{
					if(position==(getCount(head[match])+1)){
						current_playlist=head[match];
						while(current_playlist->nextaddr != NULL)
							current_playlist=current_playlist->nextaddr;
						current_playlist->nextaddr=tmp_playlist;
						tmp_playlist->nextaddr=NULL;
					}
					else
					{
						for (int i=1; i<position; i++){
							previous_playlist = current_playlist;
							current_playlist = current_playlist->nextaddr;
						}
						current_song->nextaddr = current_playlist->item;
						previous_playlist->item->nextaddr = current_song;

					}
				}
				check = false;
				break;
			case 'D':
				cout << "Enter the position of the song you would like deleted: "; cin >>position;

				if (position==1)
				{
//					if(current_playlist->nextaddr==NULL)
//						delete(head[match]);
//					else
						head[match] = head[match]->nextaddr;
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
		return head[match];
//	}
//	else{
		cout << "Name does not match available playlists"<<endl;
		return NULL;
//	}
}
