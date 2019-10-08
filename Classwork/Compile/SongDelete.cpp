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
	int size;

	for(int i=0;i<5;i++){
		if(head[i]==NULL)
			break;
		if(plname == head[i]->name){
			current=head[i];
			match = i;
			check=true;
			break;
		}
	}

	size=getCount(head[match]);
	cout << "test" << endl;

//gets stuck right here
//	if(check){
//cout << "check test" << endl;
//		while(check){
//			cout << "delete check" << endl;
//			head[match] = head[match]->nextaddr;
//			delete(current);
//		}
//		cout << "loop break check" << endl;
//		return head[match];
//	}
//	else{
//		cout << "Name does not match available playlists"<<endl;
//		return NULL;
//	}

	if(check){
cout << "check test" << endl;
		if(size==1)
			head[match]=current->nextaddr;
		else{
			for (int i=1; i<size; i++){
				previous = current;
				current = current->nextaddr;
			}
			previous->nextaddr = current->nextaddr;
		}
		delete(current);
		return(head[match]);
	}
	else{
		cout << "Name does not match available playlists"<<endl;
		return NULL;
	}
}
