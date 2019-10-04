#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>			// needed for file I/O
#include <cstdlib>			// needed for exit()

using namespace std;

struct song
{
	string name;
	string artist;
	int rank;
	int year;
	int decade;
	char performer;
	int genre;
	song *nextaddr;
};

struct playlist
{
	string name;
	song *item;
	playlist *nextaddr;
};


int list;
playlist list_name[5];

void Show(playlist *head, string plname);

song *Read();

int getCount(playlist *head)
{
    if (head == NULL)
        return 0;
    return getCount(head->nextaddr)+1;
}

void Create(song *songhead, int list, playlist *list_name[]){
	/*
	 * Inputs: list size, playlists array, songs *head
	 */
	//to be moved to input

	//entry-maker
	char select;
	if(list >= 5){
		cout << "Maximum number of playlists in library. Upgrade to premium for additional storage." << endl;
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
			cout << "Choose Playlist entry-maker: \n  (R)anking     (D)ecade     (P)erformer     (G)enre\nEntry: ";
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
			case 'D':cout << "Enter song decade: ";
					cin >> position; cin.ignore();
					if(position == 50 || position == 60 || position == 70 || position == 80
							 || position == 90 || position == 00 || position == 10){
						while(tmpcurrent != NULL){
							if(tmpcurrent->decade == position){
								if(getCount(head)==1){
									current->item=tmpcurrent;
									current->nextaddr=NULL;
								}
								else{
									next->item=tmpcurrent;
									current->nextaddr=next;
									next->nextaddr=NULL;
									current=next;
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
					break;
			case 'p':
			case 'P':cout << "Enter song performer: ";
					cin >> checker; cin.ignore();
					current=head;
					while(tmpcurrent != NULL){
						if(tmpcurrent->performer==checker){
							if(getCount(head)==1){
								current->item=tmpcurrent;
								current->nextaddr=NULL;
							}
							else{
								next->item=tmpcurrent;
								current->nextaddr=next;
								next->nextaddr=NULL;
								current=next;
							}
						}
						tmpcurrent=tmpcurrent->nextaddr;
					}
					select=' ';
				break;
			case 'g':
			case 'G':cout << "|1| Latin\n|2| Country\n|3| Hip-Hop/Rap\n|4| Jazz\n|5| Dance/Electronic\n|6| R&B\n|7| Pop\n|8| Rock\n";
					cout << "Select " << head->name << " genre : ";
					cin >> position; cin.ignore();
					bool valid_genre=false;
					for(int i=1;i<9;i++){
						if(i==position)
							valid_genre=true;
					}
					if(valid_genre != true){
						cout << "Genre not valid. Reselect entry-maker" << endl;
						break;
					}
					while(tmpcurrent->nextaddr != NULL){
						if(tmpcurrent->genre==position){
							if(getCount(head)==1){
								cout << "added1" << endl;
								current->item=tmpcurrent;
								current->nextaddr=NULL;
							}
							else{
								cout << "added" << endl;
								next->item=tmpcurrent;
								current->nextaddr=next;
								next->nextaddr=NULL;
								current=next;
							}
						}
						tmpcurrent=tmpcurrent->nextaddr;
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


void Save(playlist *head, string plname, string fname);

int main(){

	int list=-1;
	playlist *list_name[5];
//	song TestSongA = {"THE TWIST", "Chubby Checker", 1, 1960, 60, 'M', 6, NULL};
//	playlist testplaylistA = {"Test Playlist #1",{"THE TWIST", "Chubby Checker", 1, 1960, 60, 'M', 6, NULL},NULL};

	//playlist testplaylistB = {"Test Playlist #2", "SMOOTH", "Santana Featuring Rob Thomas", 2, 1999, 'G', 8 };


	song *main_head;
//	playlist *playlistmain_head;

	main_head = Read();
	Create(main_head, list,list_name);
	string playlistname, filename;

	cout << "enter playlist name: \n";
	getline(cin,playlistname);
//
//	cout << "enter file name: "; cin >> filename;
//
//
//
//	//Save(main_head, filename);
//
	Show(list_name[0], playlistname);

}

song *Read(){
	ifstream inFile;

	inFile.open("billboard.txt");

	if (inFile.fail())
	{
		cout << "\nThe file did not successfully open... Program Terminated\n" << endl;
		exit (1);
	}

	song *current, *head;

	current = new song;
	head = current;

	do
	{
		getline(inFile, current->name);
		getline(inFile, current->artist);
		inFile >> current->rank; inFile.ignore();
		inFile >> current->year; inFile.ignore();
		inFile >> current->decade; inFile.ignore();
		inFile >> current->performer; inFile.ignore();
		inFile >> current->genre; inFile.ignore();

		if (inFile.eof())
		{
			current->nextaddr = NULL;
			break;
		}
		else
		{
			current->nextaddr = new song;
			current = current->nextaddr;
		}

	}
	while(true);

	inFile.close();

	return(head);
}

void Show(playlist *head, string plname){

	playlist *current = head;

	//	cout << "test 1" << endl;

	if (plname==(current->name))
		while (current != NULL){
			//			cout << "test 2" << endl;
			//			cout <<plname << endl;
			//			cout <<current->name<<endl;

			//			cout << "test 3" << endl;
			//			while (current != NULL)
			//			{
			//	cout << current->name << endl;
			cout << current->item->name << endl;
			cout << current->item->artist<< endl;
			cout << current->item->rank<< endl;
			cout << current->item->decade<< endl;
			cout << current->item->performer<< endl;
			cout << current->item->genre<< endl;

			current=current->nextaddr;

		}


	return;
}

void Save(playlist *head, string name) {



	name += ".txt";

	cout << name;

	ofstream outFile;

	outFile.open(name);

	playlist *current = head;

	while (current != NULL)
	{
		cout << current->name << endl;
		//		cout << current->artist<< endl;
		//		cout << current->rank<< endl;
		//		cout << current->decade<< endl;
		//		cout << current->performer<< endl;
		//		cout << current->genre<< endl;
		//

		current = current->nextaddr;
	}

	return;


}
