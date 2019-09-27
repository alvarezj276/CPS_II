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
}

struct playlist{
	string name;
	song item;
	playlist nextaddr;
}

int list;
playlist list_name[5];

void Create(){
	char select;
	if(list >= 5){
		cout << "Maximum number of playlists in library. Upgrade to premium for additional storage." << endl;
		break;
	}
	else{
		list++;
		int position; char performer; string name;
		cout << "New Playlist: \nEnter Playlist name: ";
		cin >> ;
		cout << "Choose Playlist entry-maker: \n  (R)anking     (D)ecade     (P)erformer     (G)enre";
		cin >> select; cin.ignore();
		do{
			switch(select){
			case 'r':
			case 'R':cout << "Enter song ranking: ";
					 cin >> position;

				break;
			case 'd':+
			case 'D':cout << "Enter song decade: ";
					 cin >> position;
				break;
			case 'p':
			case 'P':cout << "Enter song performer: ";
					 cin >> performer;
				break;
			case 'g':
			case 'G':cout << "|1| Latin\n|2| Country\n|3| Hip-Hop/Rap\n|4| Jazz\n|5| Dance/Electronic\n|6| R&B\n|7| Pop\n|8| Rock\nEnter song genre number: ";
					 cin >> position;
				break;
			}
		}while(select == 'R' || select == 'r'
				|| select == 'D' || select == 'd'
				|| select == 'P' || select == 'p'
				|| select == 'G' || select == 'g');
	}
}
