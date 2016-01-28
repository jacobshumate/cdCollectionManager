//driver.cpp

/*************************************************************
Jacob Shumate
4/6/2013

Singly Linked List - driver

Database containing cd's which are nodes that contain strings
for Artist/Band name, Album Title and integers for number of
tracks and Album release date for each node. Nodes also
contain pointers to the next cd node. 

Instructions for use:
Driver will print menu's for user.
The user will have choices to select from
and needs to enter integers to select
those particular given choices which will
then determine the function to be used by
cd_collection.

Compile: g++ -c cd_collection.cpp driver.cpp
g++ driver.o cd_collection.o -o <output_name>

Tested In: Linux Ubuntu/GNU Compiler/ 

*************************************************************/

#include <iostream>
#include <string>
#include "cd_collection.h"

using namespace std;

void printMenu()
{
		//Print menu 
		cout << endl << "Please select one of the following options:" << endl;
		cout << "1 Read a database from file" << endl;
		cout << "2 Write the database to a file" << endl;
		cout << "3 Print the database" << endl;
		cout << "4 Search for CDs by a specific artist" << endl;
		cout << "5 Add a CD" << endl;
		cout << "6 Delete a CD" << endl;
		cout << "7 Exit this program" << endl;
}

int getMenuChoice()
{
	int i;

	cout << endl << "Please enter your choice." << endl;
	cin >> i;
	cin.ignore(256, '\n');

	return i;
}

void runChoice( int choice, cd_collection &database )
{
	char file_name[100];
	string artist_name;
	string album_name;
	bool found;
	
	switch ( choice )
	{
		case  1: cout << "Enter a file name of your choice to read from: ";
			 cin >> file_name; 
			 cout << "Reading a database from file..." << endl << endl;
			 database.read_from_file(file_name); 
			 break;
		
		case  2: cout << "Enter a file name of your choice to write to: ";
			 cin >> file_name;
			 cout << "Writing a database to file" << endl << endl;
			 database.write_to_file(file_name);
			 break;
		
		case  3: cout << "Printing a database..." << endl << endl;
			 database.print_database();
			 break;
		
		case  4: cout << "Enter the name of an artist you're searching for: ";
			 cin >> artist_name;
			 cout << endl << "Searching for CD by a specific artist" << endl << endl;
			 database.find_artist(artist_name);
			 break;
	
		case  5: cout << "Please enter information for your new CD" << endl << endl;
			 database.add_cd();

		case  6: cout << "Please enter the name of the artist and album you would" << endl;
			 cout << "like to delete from your database" << endl << endl;
			 cout << "Artist: ";
			 cin >> artist_name;
			 cout << "Album: ";
			 cin >> album_name;
			 database.delete_cd(artist_name, album_name);
			 break;
			 	
		case  7: cout << endl << "Exiting Program, have a wonderful day!" << endl;
			 break;
		
		default: cout << endl << "Invalid choice." << endl;
			 break;
	}

}

int main()
{
	cd_collection database;

	int choice;

	cout << endl << "Welcome to your CD database.";

	while(choice != 7)
	{
		printMenu();
		choice = getMenuChoice();
		runChoice(choice, database);
	}
	
	return 0;
}
