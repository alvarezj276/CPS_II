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

void Create(){
	int list;
	playlist list_name[5];
	char select;
	if(list >= 5){
		cout << "Maximum number of playlists in library. Upgrade to premium for additional storage." << endl;
		break;
	}
	else{
		list++;
		int position; char checker; string name;
		playlist *current,*head,*next;
		current = new playlist;
		int year=1950;
		int decade[7][10];
		for(int i=0;i<7;i++){
			for(int k=0;k<10;k++){
				decade[i][k]=year+k;
			}
			year+=10;
		}
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
						song *tmpcurrent;
						if(tmpcurrent->rank == position){
							if(getCount(head)>1)
								next = new playlist;
							current->item=tmpcurrent;
							next=current->nextaddr;
							break;
						}
						tmpcurrent=tmpcurrent->nextaddr;
					}
					break;
			case 'd':
			case 'D':cout << "Enter song decade: ";
					cin >> name;
					if(name != "50" || name != "60" || name != "70" || name != "80"
							 || name != "90" || name != "00" || name != "10"){
						cout << "Decade not valid. Reselect entry-maker" << endl;
						break;
					}
					while(true){
						song *tmpcurrent,*tmpprevious,*tmp;

						tmpcurrent=tmpcurrent->nextaddr;
						if(tmpcurrent->decade == position){
							if(getCount(head)>1)
								next = new playlist;
							current->item=tmpcurrent;
							next=current->nextaddr;
							break;
						}
						tmpcurrent=tmpcurrent->nextaddr;
					}
					break;
			case 'p':
			case 'P':cout << "Enter song performer: ";
					 cin >> checker;
				break;
			case 'g':
			case 'G':cout << "|1| Latin\n|2| Country\n|3| Hip-Hop/Rap\n|4| Jazz\n|5| Dance/Electronic\n|6| R&B\n|7| Pop\n|8| Rock\nEnter song genre number: ";
					 cin >> checker;
				break;
			}
		}while(select == 'R' || select == 'r'
				|| select == 'D' || select == 'd'
				|| select == 'P' || select == 'p'
				|| select == 'G' || select == 'g');
	}
}
