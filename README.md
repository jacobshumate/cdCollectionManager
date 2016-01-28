# cdCollectionManager
CD Collection Manager is program written in C++ that contains cd's which are nodes that contain strings for Artist/Band name, Album Title and integers for number of tracks and Album release date for each node. Nodes also contain pointers to the next cd node. The user has serveral options to choose from including reading from files, writing to files, printing the database, searching for artist by name, adding a new cd and deleting artist/album from the current database.

To Compile:
```
g++ -c cd_collection.cpp driver.cpp
g++ driver.o cd_collection.o -o cd_test
```

![alt tag](https://i.imgur.com/S94XksN.jpg)
