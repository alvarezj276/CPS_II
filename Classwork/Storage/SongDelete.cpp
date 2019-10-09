// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 		Delete()
//		input 		: a pointer to the head of the play list linked-list and
//					  name of the play list
//		output		: a pointer to the head of the play list linked-list
//		description : deletes play list
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <iostream>
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

	if(check){
		if(size==1){
			head[match]=current->nextaddr;
			for(int i=match;i<5;i++){
				if(i+1<5)
					head[i]=head[i+1];
			}
			delete(current);
			return head[match];
		}
		else{
			for (int i=1; i<size; i++){
				previous = current;
				current = current->nextaddr;
				delete(previous);
			}
			head[match] = current->nextaddr;
			for(int i=match;i<5;i++){
				if(head[i]==head[match])
					head[i]=NULL;
				if(i+1<5)
					head[i]=head[i+1];
			}
			delete(current);
			return head[match];
		}
	}
	else{
		cout << "Name does not match available playlists"<<endl;
		return NULL;
	}
}
