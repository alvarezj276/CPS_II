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
	song item;
	playlist *nextaddr;
};

void Show(playlist *head, string plname);

song *Read();

playlist *Modify(playlist *head, string plname,int list, playlist *list_name[] );

playlist *Delete(playlist *head, string plname,int list, playlist *list_name[] );


//void Save(playlist *head, string plname, string fname);

void Create(song *head);
int list;
	playlist list_name[5];


int main(){


	string filename, playlistname;
	bool end= true;
	char userinput;

	song *main_head;

	playlist *playlistmain_head;

	main_head = Read();

	song TestSongA = {"THE TWIST", "Chubby Checker", 1, 1960, 60, 'M', 6, NULL};

	song TestSongB = {"THE Turn", "Chubby ", 2, 1970, 70, 'G', 2, NULL};

	playlist testplaylistA = {"Test Playlist", TestSongA, NULL};


	//playlist list_name[0] = testplaylistA;


	while(end)
	{
		cout << "Playlist Creater Menu:" << endl;
		cout << right << setw(4) << "(C)reate" << right  << setw(4) << "(P)review" <<  setw(4) << "(M)odify" << endl;
		cout << right << setw(4) << "(S)ave" << right  << setw(4) << "(D)elete" << setw(4) << "(Q)uit" << endl;
		cout << "Option....... : " << endl;

		cin >> userinput; cin.ignore();

		switch(userinput)
		{
		case 'C':
			//create
			Create(main_head);
			break;
		case 'P':
			cout << "enter playlist name: ";
			getline(cin,playlistname);
			Show(playlistmain_head, playlistname);
			break;
		case 'M':
			cout << "enter playlist name: ";
			getline(cin,playlistname);
			//Modify(playlistmain_head, playlistname,list, list_name[0]);
			break;
		case 'D':
			cout << "Delete Playlist : ";
			getline(cin,playlistname);
				//Delete(playlistmain_head, playlistname, list , list_name);
			break;
		case 'S':
			cout << "enter playlist name: ";
			getline(cin,playlistname);
			cout << "enter file name: "; cin >> filename;
			//save
			break;

		case 'Q':
			cout << "Have a Nice Day" << endl;
			end = false;
			break;
		default :
			cout << "Invalid , please enter one of the following : " << endl;
		}
	}
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

	cout << "test 1" << endl;

	while (current != NULL)
	{

		cout << "test 2" << endl;
		cout <<plname << endl;

		//string tmp = current->name;

		if (plname.compare(current->name))
		{

			cout << "test 3" << endl;
			while (current != NULL)
			{
				//	cout << current->name << endl;
				cout << current->item.name << endl;
				cout << current->item.artist<< endl;
				cout << current->item.rank<< endl;
				cout << current->item.decade<< endl;
				cout << current->item.performer<< endl;
				cout << current->item.genre<< endl;

				current = current->nextaddr;

			}
			break;
		}
		else
			current = current->nextaddr;
	}
	return;
}

void Save(playlist *head, string name) {

	//name += ".txt";

	cout << name;

	ofstream outFile;

	//outFile.open(name + ".txt");

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


	outFile.close();
	return;


}

playlist *Modify(playlist *head, string plname, int list, playlist *list_name[]){
	bool check = false;

	playlist *current,*previous;

	current = head;

	char userchoice;
	int n, m;

	for (int i=0; i<list; i++)
	{
		if (list_name[i]->name == plname)
		{
			check = true;
		}

	}

	while(check)
	{
		cout << "Insert (I) or Delete (D): "; cin >> userchoice;

		switch(userchoice)
		{
		case 'I':
			cout << "Enter the Rank of the song you would like added to the playlist: "; cin >>n;
			cout << "Enter the position you would like the song placed: "; cin >> m;

			for (int i=1; i<m; i++)
			{
				previous = current;
				current = current->nextaddr;
			}
			current->item.rank = m;
			break;
		case 'D':
			cout << "Enter the position of the song you would like deleted: "; cin >>n;

			if (n==1)
			{
				head = current->nextaddr;
			}
			else
			{
				for (int i=1; i<n; i++)
				{
					previous = current;
					current = current->nextaddr;
				}
				previous->nextaddr = current->nextaddr;
			}
			delete(current);
			break;
		}


	}

	return(head);
}

playlist *Delete(playlist *head, string plname, int list, playlist *list_name[]){
	playlist *current, *previous;
	current = head;
	bool check = false;

	for (int i=0; i<list; i++)
		{
			if (list_name[i]->name == plname)
			{
				check = true;
			}

		}

	while(check){
		previous = current->nextaddr;
		delete(current);
		current = previous;
	}

	return(head);

}