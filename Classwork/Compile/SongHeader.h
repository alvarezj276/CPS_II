/*
 * SongHeader.h
 *
 *  Created on: Oct 6, 2019
 *      Author: meran
 */

#ifndef SONGHEADER_H_
#define SONGHEADER_H_


#include "SongHeader.h"

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


void Display(playlist *head[], int list, string plname);

song *Read();

playlist *Modify(string plname,int list, playlist *head[] );

playlist *Delete(string plname,int list, playlist *head[] );

void Create(song *songhead, int list, playlist *list_name[]);

void Save(playlist *head[], string name, int list);

#endif /* SONGHEADER_H_ */
