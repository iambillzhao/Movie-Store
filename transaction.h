/*
 * transaction.h is part of the Movie Store Simulator, a C++ program that
 * offers the function of borrow, return, or stock with up to 10,000
 * customers and 26 genres of movies
 *
 * @author Bill Zhao, Lucas Bradley
 * @date March 12th
*/

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "movie.h"
#include <string>

class Customer;

class Transaction {
public:
  // Constructs a transaction according to the input
  // string
  explicit Transaction(std::string Input);
  // Reforms the original code from the transaction data
  std::string reformString();
private:
  char Action;
  int CustomerID;
  char MediaType;
  char MovieType;
  std::string SortingElement;
};

#endif