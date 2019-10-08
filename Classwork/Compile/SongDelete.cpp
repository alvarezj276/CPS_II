/*
 * SongDelete.cpp
 *
 *  Created on: Oct 6, 2019
 *      Author: meran
 */


#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>			// needed for file I/O
#include <cstdlib>			// needed for exit()

#include "SongHeader.h"
using namespace std;

playlist *Delete(string plname, int list, playlist *head[]){

	playlist *current, *previous;
	bool check = false;

	int match;


	for(int i=0;i<5;i++)
	{
		if(plname == head[i]->name){
			current=head[i];
			match = i;
			check=true;
			break;
		}

	}


	cout << "test" << endl;

//gets stuck right here
	if(check){
		while(check){
			head[match] = current->nextaddr;
			delete(current);
		}
		return(head[match]);
	}
	else{
		cout << "Name does not match available playlists"<<endl;
		return(NULL);
	}
}
