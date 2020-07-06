/*
 * hashtable.cpp is part of the Movie Store Simulator, a C++ program that
 * offers the function of borrow, return, or stock with up to 10,000
 * customers and 26 genres of movies
 *
 * @author Bill Zhao, Lucas Bradley
 * @date March 12th
 */

#include "hashtable.h"
#include <cstdint>

constexpr int64_t INITIALIZATION_SIZE = 10;

// Default constructor
HashTable::HashTable() {
  Table = new std::map<std::string, Movie *> *[INITIALIZATION_SIZE];
  Keys = new char[INITIALIZATION_SIZE];
  for (int I = 0; I < INITIALIZATION_SIZE; I++) {
    Table[I] = nullptr;
    Keys[I] = '\0';
  }
  Elements = 0;
  Capacity = INITIALIZATION_SIZE;
}

// Destructor
HashTable::~HashTable() {
  for (int I = 0; I < Capacity; I++) {
    std::map<std::string, Movie *> *Curr = Table[I];
    if (Curr != nullptr) {
      auto It = Curr->begin();
      while (It != Curr->end()) {
        delete It->second;
        Curr->erase(It);
        It = Curr->begin();
      }
      delete Curr;
      Curr = nullptr;
    }
  }
  delete[] Table;
  delete[] Keys;
}

// Creates the hash
int HashTable::hash(char Key) { return Key % Capacity; }

// Inserts Movie pointer into correct positon
bool HashTable::insert(Movie *Film) {
  if (Elements == Capacity) {
    return false;
  }
  char Key = Film->type();
  int I;
  for (I = hash(Key); Keys[I] != '\0' && Keys[I] != Key;
       I = ((I + 1) % Capacity))
    ;
  if (Keys[I] == Key) {
    Table[I]->insert(make_pair(Film->sortingElement(), Film));
    return true;
  }
  Keys[I] = Key;
  Table[I] = new std::map<std::string, Movie *>;
  Table[I]->insert(make_pair(Film->sortingElement(), Film));
  return true;
}

// Prints out the entire hashtable
void HashTable::print() {
  for (int I = 0; I < Capacity; I++) {
    std::cout << I << ": " << Keys[I] << std::endl;
  }
}

// Returns true if movie is in hash table
bool HashTable::find(Movie *Film) {
  if (Film == nullptr) {
    return false;
  }
  char Key = Film->type();
  int Hash = hash(Key);
  int I;
  for (I = Hash; Keys[I] != Key && Table[I] != nullptr;
       I = ((I + 1) % Capacity))
    ;
  if (Keys[I] == Key) {
    return Table[I]->find(Film->sortingElement()) != Table[I]->end();
  }
  return false;
}

// Returns pointer to map according to key
std::map<std::string, Movie *> *HashTable::genreMap(char Key) {
  int Hash = hash(Key);
  int I;
  for (I = Hash; Keys[I] != Key && Table[I] != nullptr;
       I = ((I + 1) % Capacity))
    ;
  if (Keys[I] == Key) {
    return Table[I];
  }
  return nullptr;
}
