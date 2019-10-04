#include <string>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

struct song{
	string name;
	string artist;
	int rank;
	int year;
	int decade;
	char performer;
	int genre;
	song *nextaddr;
}

struct playlist{
	string name;
	song item;
	playlist *nextaddr;
}
int getCount(playlist *head)
{
    if (head == NULL)
        return 0;
    return getCount(head->nextaddr)+1;
}

void Create(song *songhead){
	/*
	 * Inputs: list size, playlists array, songs *head
	 */
	//to be moved to input
	int list; 
	playlist list_name[5];
	
	//entry-maker
	char select; 
	if(list >= 5){
		cout << "Maximum number of playlists in library. Upgrade to premium for additional storage." << endl;
		break;
	}
	else{
		list++;
		int position; char checker;
		playlist *current,*head,*next;
		song *tmpcurrent=songhead;
		current = new playlist;
//		int year=1950;
//		int decade[7][10];
//		for(int i=0;i<7;i++){
//			for(int k=0;k<10;k++){
//				decade[i][k]=year+k;
//			}
//			year+=10;
//		}
		cout << "New Playlist: \nEnter Playlist name: ";
		getline(cin,current->name);
		list_name[list]=current;
		head=current;
		do{
			cout << "Choose Playlist entry-maker: \n  (R)anking     (D)ecade     (P)erformer     (G)enre";
			cin >> select; cin.ignore();
			switch(select){
			case 'r':
			case 'R':cout << "Enter song ranking: ";
					cin >> position; cin.ignore();
					if(position>200){
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
								next = new playlist;
								current->nextaddr=next;
								next->item=tmpcurrent;
								next->nextaddr=NULL;
							}
							break;
						}
						tmpcurrent=tmpcurrent->nextaddr;
					}
					break;
			case 'd':
			case 'D':cout << "Enter song decade: ";
					cin >> position;
					if(position != "50" || position != "60" || position != "70" || position != "80"
							 || position != "90" || position != "00" || position != "10"){
						cout << "Decade not valid. Reselect entry-maker" << endl;
						break;
					}
					while(tmpcurrent != NULL){
						if(tmpcurrent->decade == position){
							if(getCount(head)==1){
								current->item=tmpcurrent;
								current->nextaddr=NULL;
							}
							else{
								next = new playlist;
								current->nextaddr=next;
								next->item=tmpcurrent;
								next=current->nextaddr;
							}
						}
						tmpcurrent=tmpcurrent->nextaddr;
					}
					break;
			case 'p':
			case 'P':cout << "Enter song performer: ";
					cin >> checker;
					while(tmpcurrent != NULL){
						if(tmpcurrent->performer==checker){
							if(getCount(head)==1){
								current->item=tmpcurrent;
								current->nextaddr=NULL;
							}
							else{
								next = new playlist;
								current->nextaddr=next;
								next->item=tmpcurrent;
								next=current->nextaddr;
							}
						}
						tmpcurrent=tmpcurrent->nextaddr;
					}
				break;
			case 'g':
			case 'G':cout << "|1| Latin\n|2| Country\n|3| Hip-Hop/Rap\n|4| Jazz\n|5| Dance/Electronic\n|6| R&B\n|7| Pop\n|8| Rock\nEnter song genre number: ";
					cout << "Select " << head->name << " genre : ";
					cin >> position;
					bool valid_genre=false;
					for(int i=1;i<9;i++){
						if(i==position)
							valid_genre=true;
					}
					if(valid_genre != true){
						cout << "Genre not valid. Reselect entry-maker" << endl;
						break;
					}
					while(tmpcurrent != NULL){
						if(tmpcurrent->genre==position){
							if(getCount(head)==1){
								current->item=tmpcurrent;
								current->nextaddr=NULL;
							}
							else{
								next = new playlist;
								current->nextaddr=next;
								next->item=tmpcurrent;
								next=current->nextaddr;
							}
						}
						tmpcurrent=tmpcurrent->nextaddr;
					}
				break;
			}
		}while(select == 'R' || select == 'r'
				|| select == 'D' || select == 'd'
				|| select == 'P' || select == 'p'
				|| select == 'G' || select == 'g');
	}
}
