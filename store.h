/*
 * store.h is part of the Movie Store Simulator, a C++ program that
 * offers the function of borrow, return, or stock with up to 10,000
 * customers and 26 genres of movies
 *
 * @author Bill Zhao, Lucas Bradley
 * @date March 12th
*/

#ifndef STORE_H
#define STORE_H

#include "classic.h"
#include "comedy.h"
#include "customer.h"
#include "drama.h"
#include "factory.h"
#include "hashtable.h"
#include "movie.h"
#include <iostream>
#include <map>
#include <string>

class Store {

public:
  // Default constructor
  Store();
  // Takes three strings which are file names and fills in all fo the
  // data according to the contents of the files
  Store(const std::string &Movies, const std::string &Customers, const std::string &Commands);
  // Store destructor
  ~Store();
  // Inserts film in the correct postion of inventory
  bool insertFilm(std::string Code);
  // Inserts customer int he correct positon of Customers
  bool insertCustomer(std::string Code);
  // Checks if film exists in the inventory
  bool findFilm(Movie* Film);
  // Displays the contents of the inventory in sorted order
  void inventoryDisplay();
  // Displays specific customers history
  void historyDisplay(int CustomerCode);
  // Borrow film will take command and edit Customers and
  // inventory accordingly
  bool borrowFilm(std::string Code);
  // Return film will take command and edit Customers and
  // inventory accordingly
  bool returnFilm(std::string Code);
  // Takes a code and adds the information to the
  // customers history
  bool addTransaction(std::string Code);
  // Determines which action to do depending on code
  bool action(std::string Code);
private:
  HashTable Inventory;
  std::map<int, Customer*> Customers;
  Factory F;
};

#endif