// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 		Main()
//		description : Allows a user to create, and modify play list
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>			// needed for file I/O
#include <cstdlib>			// needed for exit()

using namespace std;

#include "SongHeader.h"

int list;
playlist list_name[5];

int getCount(playlist *head){
	if (head == NULL)
		return 0;
	return (getCount(head->nextaddr)+1);
}

void Create(song *songhead, int list, playlist *list_name[]){
	/*
	 * Inputs: list size, playlists array, songs *head
	 * Description: creates playlist according to user choices
	 */
	char select;
	const int PLAYLIST_SIZE=200;
	if(list >= 5){
		cout << "Maximum number of playlists in library. Upgrade to premium for additional storage." << endl;
	}
	else{
		int position; char checker;
		playlist *current=new playlist,*head=new playlist,*next=new playlist;
		song *tmpcurrent= new song;
		tmpcurrent=songhead;
		cout << "New Playlist: \nEnter Playlist name: ";
		getline(cin,current->name);
		head=current;
		current->nextaddr=NULL;
		list_name[list]=head;
		do{
			bool first=true,valid_genre=false;
			cout << "Choose Playlist entry-maker: \n  (R)anking     (D)ecade     (P)erformer     (G)enre     (M)ulti-Entry\nEntry: ";
			cin >> select; cin.ignore();
			switch(select){
			case 'r':
			case 'R':cout << "Enter song ranking: ";
			cin >> position;
			if(position<10)
				cin.ignore();
			if(position>PLAYLIST_SIZE && position<1){
				cout << "Song ranking not valid. Reselect entry-maker" << endl;
				break;
			}
			while(true){
				if(tmpcurrent->rank == position){
					if(getCount(head)==1){
						current->item=tmpcurrent;
						current->nextaddr=NULL;
					}
					else{
						current->nextaddr=next;
						next->item=tmpcurrent;
						next->nextaddr=NULL;
					}
					break;
					select=' ';
				}
				tmpcurrent=tmpcurrent->nextaddr;
			}
			select=' ';
			break;
			case 'd':
			case 'D':cout << "Enter song decade (60, 70, 80, 90, 00, 10): ";
			cin >> position; //cin.ignore();
			if(position == 50 || position == 60 || position == 70 || position == 80
					|| position == 90 || position == 00 || position == 10){
				tmpcurrent=songhead;
				for(int i=0; i<PLAYLIST_SIZE; i++){
					if(tmpcurrent->decade==position){
						if(current->nextaddr==NULL && first){
							current->item=tmpcurrent;
							current->nextaddr=NULL;
							first=!first;
						}
						else{
							current=head;
							playlist *next=new playlist;
							next->item=tmpcurrent;
							while(current->nextaddr != NULL)
								current=current->nextaddr;
							current->nextaddr=next;
							next->nextaddr=NULL;
						}
					}
					tmpcurrent=tmpcurrent->nextaddr;
				}
			}
			else{
				cout << "Decade not valid. Reselect entry-maker" << endl;
				break;
			}
			select=' ';
			cin.ignore();
			break;
			case 'p':
			case 'P':cout << "Enter performer type (MUST BE CAPITAL M, F, OR D) : ";
			cin >> checker; cin.ignore();
			if(checker == 'F' || checker =='M' || checker =='D'){
				tmpcurrent=songhead;
				for(int i=0; i<PLAYLIST_SIZE; i++){
					if(tmpcurrent->performer==checker){
						if(current->nextaddr==NULL && first){
							current->item=tmpcurrent;
							current->nextaddr=NULL;
							first=!first;
						}
						else{
							current=head;
							playlist *next=new playlist;
							next->item=tmpcurrent;
							while(current->nextaddr != NULL)
								current=current->nextaddr;
							current->nextaddr=next;
							next->nextaddr=NULL;
						}
					}
					tmpcurrent=tmpcurrent->nextaddr;
				}
			}
			else{
				cout << "Performer not valid. Reselect entry-maker" << endl;
				break;
			}
			select=' ';
			break;
			case 'g':
			case 'G':cout << "|1| Latin\n|2| Country\n|3| Hip-Hop/Rap\n|4| Jazz\n|5| Dance/Electronic\n|6| R&B\n|7| Pop\n|8| Rock\n";
			cout << "Select " << head->name << " genre : ";
			cin >> position; cin.ignore();
			for(int i=1;i<9;i++){
				if(i==position)
					valid_genre=true;
			}
			if(valid_genre != true){
				cout << "Genre not valid. Reselect entry-maker" << endl;
				break;
			}
			tmpcurrent=songhead;
			for(int i=0; i<PLAYLIST_SIZE; i++){
				if(tmpcurrent->genre==position){
					if(current->nextaddr==NULL && first){
						current->item=tmpcurrent;
						current->nextaddr=NULL;
						first=!first;
					}
					else{
						current=head;
						playlist *next=new playlist;
						next->item=tmpcurrent;
						while(current->nextaddr != NULL)
							current=current->nextaddr;
						current->nextaddr=next;
						next->nextaddr=NULL;
					}
				}
				tmpcurrent=tmpcurrent->nextaddr;
			}
			select=' ';
			break;
			case 'm':
			case 'M': int decade, genre; char performer;
			cout << "Enter Song Decade: ";
			cin >> decade;
			if(decade == 50 || decade == 60 || decade == 70 || decade == 80
					|| decade == 90 || decade == 00 || decade == 10){
				cout << "Enter Song Performer Type: ";
				cin >> performer; cin.ignore();
				if(performer == 'F' || performer =='M' || performer =='G'){
					cout << "|1| Latin\n|2| Country\n|3| Hip-Hop/Rap\n|4| Jazz\n"
							"|5| Dance/Electronic\n|6| R&B\n|7| Pop\n|8| Rock\n";
					cout << "Select " << head->name << " genre : ";
					cin >> genre; cin.ignore();
					for(int i=1;i<9;i++){
						if(i==genre)
							valid_genre=true;
					}
					if(valid_genre != true){
						cout << "Genre not valid. Reselect entry-maker" << endl;
						break;
					}
					tmpcurrent=songhead;
					for(int i=0; i<PLAYLIST_SIZE; i++){
						if(tmpcurrent->performer==performer &&
								tmpcurrent->decade==decade && tmpcurrent->genre==genre){
							if(current->nextaddr==NULL && first){
								current->item=tmpcurrent;
								current->nextaddr=NULL;
								first=!first;
							}
							else{
								current=head;
								playlist *next=new playlist;
								next->item=tmpcurrent;
								while(current->nextaddr != NULL)
									current=current->nextaddr;
								current->nextaddr=next;
								next->nextaddr=NULL;
							}
						}
						tmpcurrent=tmpcurrent->nextaddr;
					}
				}
				else{
					cout << "Performer not valid. Reselect entry-maker" << endl;
					break;
				}
			}
			else{
				cout << "Decade not valid. Reselect entry-maker" << endl;
				break;
			}
			select=' ';
			break;
			}
		}while(select == 'R' || select == 'r'
				|| select == 'D' || select == 'd'
						|| select == 'P' || select == 'p'
								|| select == 'G' || select == 'g');
	}
}


int main(){

	playlist *list_name[5];

	string filename, playlistname;
	bool end= true;
	char userinput;

	song *main_head;

	main_head = Read();

	list = -1;

	cout << "WELCOME TO MATTHEWS & PEDRO PLAYLIST EDITOR" << endl;

	while(end)
	{
		cout << "Playlist Creater Menu:" << endl;
		cout << right << setw(5) << "(C)reate"  << setw(15) << "(P)review" <<  setw(15) << "(M)odify" << endl;
		cout << right << setw(5) << "(S)ave " << setw(15) << "(D)elete" << setw(14) << "(Q)uit" << endl;
		cout << "Option....... : ";

		cin >> userinput; cin.ignore();

		switch(userinput)
		{
		case 'C':
		case 'c':
			//create
			list++;
			Create(main_head, list, list_name);
			break;
		case 'P':
		case 'p':
			//display
			cout << "enter playlist name: ";
			getline(cin,playlistname);
			Display(list_name, list, playlistname);
			break;
		case 'M':
		case 'm':
			//modify
			cout << "enter playlist name: ";
			getline(cin,playlistname);
			Modify(playlistname, list, list_name, main_head);
			break;
		case 'D':
		case 'd':
			//delete
			cout << "Delete Playlist : ";
			getline(cin,playlistname);
			Delete(playlistname, list , list_name);
			break;
		case 'S':
		case 's':
			//save
			cout << "enter playlist name: ";
			getline(cin,playlistname);
			cout << "enter file name: "; cin >> filename;
			Save(list_name, filename, playlistname,list);
			break;

		case 'Q':
		case 'q':
			cout << "Have a Nice Day" << endl;
			end = false;
			break;
		default :
			cout << "Invalid, please enter one of the following : " << endl;
		}
	}

}
