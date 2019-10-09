// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 		Modify()
//		input 		: a pointer to the head of the play list linked-list and
//					  name of the play list, a pointer to the head of the song
//					  linked list
//		output		: a pointer to the head of the play list
//		description : allows user to insert or delete songs in created play lists
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <iostream>
#include "SongHeader.h"


playlist *Modify(string plname, int list, playlist *head[], song *head_song){

	bool check = false;
	int match;
	playlist *current_playlist,*previous_playlist, *tmp_playlist=new playlist;
	song *current_song=head_song;

	char userchoice;
	int rank, position;

	for(int i=0;i<5;i++){
		if(head[i]==NULL)
			break;
		if(plname == head[i]->name){
			current_playlist=head[i];
			match =i;
			check=true;
			break;
		}
	}
	if(check){
		while(check)
		{

			Display(head, list, plname);
			cout << "Insert (I) or Delete (D): "; cin >> userchoice;
			switch(userchoice)
			{
			case 'I':
			case 'i':
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
				if (position==1)
				{
					tmp_playlist->item=current_song;
					tmp_playlist->nextaddr=head[match];
					tmp_playlist->name=head[match]->name;
					head[match]=tmp_playlist;
				}
				else{
					if(position >(getCount(head[match])+1)){
						cout << "Error: Song not available at position " << position << endl;
					}
					else{
						if(position==(getCount(head[match])+1)){
							current_playlist=head[match];
							while(current_playlist->nextaddr != NULL)
								current_playlist=current_playlist->nextaddr;
							current_playlist->nextaddr=tmp_playlist;
							tmp_playlist->item = current_song;  //here
							tmp_playlist->nextaddr=NULL;
						}
						else
						{
							for (int i=1; i<position; i++){
								previous_playlist = current_playlist;
								current_playlist = current_playlist->nextaddr;
							}
							tmp_playlist->nextaddr=current_playlist;
							tmp_playlist->item=current_song;
							previous_playlist->nextaddr=tmp_playlist;
						}
					}
				}
				check = false;
				break;
			case 'D':
			case 'd':
				cout << "Enter the position of the song you would like deleted: "; cin >>position;

				if (position==1)
				{
						head[match] = head[match]->nextaddr;
				}
				else
				{
					if(position > getCount(head[match])){
						cout << "Error: Song not found at position " << position << endl;
						break;
					}
					else{
						for (int i=1; i<position; i++)
						{
							previous_playlist = current_playlist;
							current_playlist = current_playlist->nextaddr;
						}
						previous_playlist->nextaddr = current_playlist->nextaddr;
					}
				}
				delete(current_playlist);
				check = false;
				break;
			}
		}
		return head[match];
	}
	else{
		cout << "Name does not match available playlists"<<endl;
		return NULL;
	}
}
