/*
 * hashtable.h is part of the Movie Store Simulator, a C++ program that
 * offers the function of borrow, return, or stock with up to 10,000
 * customers and 26 genres of movies
 *
 * @author Bill Zhao, Lucas Bradley
 * @date March 12th
*/

#pragma once
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "movie.h"
#include <map>
#include <string>

class HashTable {
  friend class Store;
public:
  // Default constructor
  HashTable();
  // Destructor
  ~HashTable();
  // Creates the hash
  int hash(char Key);
  // Inserts Movie pointer into correct positon
  bool insert(Movie* Film);
  // Prints out the entire hashtable
  void print();
  // Returns true if movie is in hash table
  bool find(Movie* Film);
  // Returns pointer to map according to key
  std::map<std::string, Movie*>* genreMap(char Key);

private:
  std::map<std::string, Movie*>** Table;
  char* Keys;
  int Elements;
  int Capacity;
};

#endif