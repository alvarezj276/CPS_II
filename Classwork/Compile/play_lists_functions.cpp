#include <string>
#include <iomanip>

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
	song nextaddr;
}

Create(){
	char select;
	if(list >= 5){
		cout << "Maximum number of playlists in library. Upgrade to premium for additional storage." << endl;
		break;
	}
	else{
		list++;
		cout << "New Playlist: \nEnter Playlist name: ";
		cin >> playlist->name;
		cout << "Choose Playlist entry-maker: \n  (R)anking     (D)ecade     (P)erformer     (G)enre";
		cin >> select; cin.ignore();
		do{

		}while(select == 'R' || select == 'r'
				|| select == 'D' || select == 'd'
				|| select == 'P' || select == 'f'
				|| select == 'G' || select == 'g')
	}
}
