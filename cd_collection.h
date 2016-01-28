//cd_collection.h
/**************************************************************
Jacob Shumate
4/6/2013

Singly Linked List - cd_collection class header

Database containing cd's which are nodes that contain strings
for Artist/Band name, Album Title and integers for number of
tracks and Album release date for each node. Nodes also
contain pointers to the next cd node. 

Instructions for use: refer to driver.cpp

Compile: g++ -c cd_collection.cpp driver.cpp
g++ driver.o cd_collection.o -o <output_name>

Tested In: Linux Ubuntu/GNU Compiler/
***************************************************************/

#ifndef CD_COLLECTION_H
#define CD_COLLECTION_H
#include "cd.h"
using namespace std;

//class cd_collection: The class represents a linked list
//of struct cd, which is a chain of nodes. Each node holds
//cd data, and each node except the last points to the next
//node. The last node points to NULL.

class cd_collection{

private:
	int size;
	cd *first;
	cd *last;
	
public:
	cd_collection();
		//Default constructor
		//Postcondition: list = NULL;

	~cd_collection();
		//Destructor
		//delete all the nodes from the list.
		//Postcondition: first = NULL, last = NULL,
		//count = 0;

	void insert_sorted(const cd* newCD);
		//Function determines where to insert new_cd.
		//Postcondition: first points to the new list,
		//new_cd is inserted at the proper place in the
		//list, and count is incremented by 1.

	void find_artist(const string& artist_name);
		//Function to determine whether artist_name is in
		//the list.
		//Postcondition: Returns true if artist_name is the
		//list otherwise the value false is returned.

	void print_database();
		//Function prints data of each artist 
		//from entire list.
		//Postcondition: prints artist name, album title,
		//# of tracks and release year.

	void read_from_file(char file_name[]);
		//Function takes a file name as input and uses
		//insert_sorted to store the information in
		//sorted order in the list.
		//Postcondition: first points to the new list,
		//information is inserted at the proper place
		//in the list according to artist name, and
		//count is incremented by 1.

	void write_to_file(char file_name[]);
		//Function writes the information from the list
		//and into file from given input.
		//Postcondition: prints artist name, album title,
		//# of tracks and release year into another file
		//of chosen name from input.

	void add_cd();
		//Function asks the user for a new CD's information,
		//and uses insert_sorted to store the record in the 
		//list.
		//Postcondition: prompts user to input information
		//for artist name, album title, # of tracks and
		//release year, which calls insert_sorted, stores
		//the information in the list and count is incremented
		//by 1.

	void delete_cd(const string& artist_name, const string& album_name);
		//Function takes an artist's name and an album's name
		//as input, searches the list and if such a record
		//exists it deletes the record of the first CD with
		//a matching arist and album title.
};

#endif
