//cd.h
/**************************************************************
Jacob Shumate
4/6/2013

Singly Linked List - cd struct header

Database containing cd's which are nodes that contain strings
for Artist/Band name, Album Title and integers for number of
tracks and Album release date for each node. Nodes also
contain pointers to the next cd node. 

Instructions for use: refer to driver.cpp

Compile: g++ -c cd_collection.cpp driver.cpp
g++ driver.o cd_collection.o -o <output_name>

Tested In: Linux Ubuntu/GNU Compiler/
***************************************************************/
#ifndef CD_H
#define CD_H
#include <string>
using namespace std;

//struct cd: node that holds data that includes artist name, 
//album, # of tracks and album year. It also holds a pointer 
//to the next node. The intent of cd is to be used as data 
//storage and a pointer for cd_collection as a linked list.

struct cd{

public:
	cd *next;
	string artist;
	string album;
	int tracks;
	int year;

		
};
#endif
