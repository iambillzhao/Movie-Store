/*
 * Customer.h is part of the Movie Store Simulator, a C++ program that
 * offers the function of borrow, return, or stock with up to 10,000
 * customers and 26 genres of movies
 *
 * @author Bill Zhao, Lucas Bradley
 * @date March 12th
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "movie.h"
#include "transaction.h"
#include <iostream>
#include <string>
#include <vector>

class Customer {
public:
  explicit Customer(std::string Input);
  ~Customer();
  bool addTransaction(std::string Input);
  void printHistory() const;

private:
  int CustomerID;                     // ID of this customer
  std::string Name;                   // Whole name of this customer
  std::vector<Transaction*> History;  // All transaction history for
                                      // this customer
};

#endif