//cd_collection.cpp
/**************************************************************
Jacob Shumate
4/6/2013

Singly Linked List - cd_collection class definitions

Database containing cd's which are nodes that contain strings
for Artist/Band name, Album Title and integers for number of
tracks and Album release date for each node. Nodes also
contain pointers to the next cd node. 

Instructions for use: refer to driver.cpp

Compile: g++ -c cd_collection.cpp driver.cpp
g++ driver.o cd_collection.o -o <output_name>

Tested In: Linux Ubuntu/GNU Compiler/
***************************************************************/

#include "cd_collection.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//default constructor

cd_collection::cd_collection()
{
	first = NULL;
	last = NULL;
	size = 0;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//destructor

cd_collection::~cd_collection()
{
	cd *temp;
	cd *current;
	current = first;

	//while there are nodes in the list,
	//set temp to the current node, advance
	//first to the next node, deallocate
	//the memory occupied.
	while(current != NULL)
	{
		temp = current;
		current = current->next;
		delete temp;
	}

	first = NULL;
	last = NULL;
	size = 0;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void cd_collection::insert_sorted(const cd* newCD)
{
	cd *trail_current;
	cd *current;
	cd *new_cd;
	bool search;

	//copy all objects of newCD
	//to new_cd to be stored
	//in linked list
	new_cd = new cd;
	new_cd->artist = newCD->artist;
	new_cd->album = newCD->album;
	new_cd->tracks = newCD->tracks;
	new_cd->year = newCD->year;
	new_cd->next = NULL;

	//if cd_collection is empty
	if(first == NULL)
	{
		first = new_cd;
		last = new_cd;
		size++;
	}
	
	else
	{
		current = first;
		search = false;
		
		while(current != NULL && !search)
		{
			//compares artist's names in descending order
			if(current->artist > new_cd->artist)
				search = true;

			//keep track of previous node and
			//advance onto next node 	
			else
			{
				trail_current = current;
				current = current->next;
			}
		}
		//if artist name is alphabetically
		//larger than current, set current
		//to last and new_node to first
		if (current == first)
		{
			first = new_cd;
			first->next = current;
			size++;
		}

		//insert new_node between previous and
		//current node, reset pointers as well
		else
		{
			trail_current->next = new_cd;
			new_cd->next = current;

			if(current == NULL)
				last = new_cd;
			
			size++;
		}

		//reset last pointer
		while(current != NULL)
		{
			if(current->next == NULL)
				last = current;
			
			trail_current = current;
			current = current->next;
		}
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void cd_collection::find_artist(const string& artist_name)
{
	cd *current;
	cd *trail_current;
	bool search;

	current = first;
	search = false;
	
	//loop through nodes starting with first until artist
	//can be found, if not return search as false
	while(current != NULL)
	{	
		if(current->artist == artist_name)
		{
			search = true;
		
			cout << endl;
			cout << "Artist was found!" << endl;
			cout << "CD's by this artist that is" << endl; 
			cout << "located in this database are:" << endl;

			//printing cd's of located artist
			while(current->artist == artist_name)
			{
				cout << endl << "Album Title: " << current->album << endl;
				cout << "# of Tracks: " << current->tracks << endl;
				cout << "Year Released: " << current->year << endl;

				current = current->next;
			}

			break;

		}
		else
		{
			trail_current = current;
			current = current->next;
		}
	}
	
	//if search was never set to true
	//then artist wasn't found
	if(!search)
		cout << "Artist could not be found in database." << endl;
	
	
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void cd_collection::print_database()
{
	cd *current;
	current = first;

	//loop through nodes starting with first until
	//all node data has been printed out
	while(current != NULL)
	{
		cout << "Artist Name: " << current->artist << endl;
		cout << "Album Title: " << current->album << endl;
		cout << "# of Tracks: " << current->tracks << endl;
		cout << "Release year: " << current->year << endl << endl;
		
		current = current->next;	
	}
	cout << "Your CD database contains " << size << " artists." << endl;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void cd_collection::read_from_file(char file_name[])
{

	ifstream infile;
	cd *temp;
	string buffer;
	
	
	infile.open(file_name);

	//checks if specified file name
        //can not be located
        while(infile.fail())
        {
                cout << "File could not be located." << endl;
                cout << "Please enter correct file name: ";
                cin >> file_name;
                infile.open(file_name);
		cin.ignore(256,'\n');
        }

	temp = new cd;

	//read lines until end of file
	while(getline(infile, temp->artist))
	{
		//infile.clear();
			
		//temp = new cd;

		//getline(infile, temp->artist);
		//cout << temp->artist << endl;

		getline(infile, temp->album);
		//cout << temp->album << endl;

		infile >> temp->tracks;

		infile >> temp->year;

		infile.ignore(256, '\n');

		//cout << temp->tracks << endl;
		//cout << temp->year << endl;
			
		insert_sorted(temp);

		//delete temp;

		if(!infile.good())
			break;
	}
	
	delete temp;

	infile.close();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void cd_collection::write_to_file(char file_name[])
{
	ofstream outfile;
	//int temp_size = size;
	
	outfile.open(file_name);
		
	cd *current;
        current = first;

        //loop through nodes starting with first until
        //all node data has been printed out
        while(current != NULL)
        {
                outfile << current->artist << endl;
                outfile << current->album << endl;
                outfile << current->tracks << endl;
                outfile << current->year << endl << endl;

                current = current->next;
        }

	outfile.close();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void cd_collection::add_cd()
{
	cd *temp;
	temp = new cd;
	
	//promps user for information on cd they
	//want to enter
	cout << "Please enter cd information for each field displayed." << endl;
	cout << endl << "Artist/Band Name: ";
	getline(cin, temp->artist);
	cout << endl << "Album Title: ";
	getline(cin, temp->album);
	cin.ignore(256, '\n');
	cout << endl << "Number of Tracks: ";
	cin >> temp->tracks;
	cin.ignore(256, '\n');
	cout << endl << "Album release year: ";
	cin >> temp->year;
	cin.ignore(256, '\n');
	
	//pass new node of information
	//into insert_sorted function
	//which will create another node
	//that will store the information
	//until program is closed
	insert_sorted(temp);
	
	delete temp;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void cd_collection::delete_cd(const string& artist_name, const string& album_name)
{
	cd *current;
	cd *trail_current;
	cd *temp;
	bool search;
	
	current = first;
	search = false;

	//if first album matches, set next node
	//to first, delete matching cd
	if(first->album == album_name)
	{	
		current = current->next;
		temp = first;
		delete temp;
		first = current;
		size--;
	}
		
	else		
		//else traverse through entire list until
		//cd is found or transverse to last node
		while(current != NULL)
		{
			if(current->album == album_name)
			{
				temp = current;
				current = current->next;
				trail_current->next = current;
				delete temp;
				size--;
				search = true;

				if(current->next == NULL)
				{
					last = current;
					last->next = NULL;
				}
				
				//break while loop
				break;
			}
				
			else
			{
				trail_current = current;
				current = current->next;
			}
		}
	
	//if search is never set to true
	//then do this
	if(!search)
	cout << "This CD could not be found." << endl;

	//else shows it ran through loop
	//found cd and set search to true
	else
	cout << "CD has been deleted." << endl;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

