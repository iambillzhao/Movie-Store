/*
 * transaction.cpp is part of the Movie Store Simulator, a C++ program that
 * offers the function of borrow, return, or stock with up to 10,000
 * customers and 26 genres of movies
 *
 * @author Bill Zhao, Lucas Bradley
 * @date March 12th
 */

#include "transaction.h"

// Constructs a transaction according to the input
// string
Transaction::Transaction(std::string Input) {
  Action = Input[0];
  int It = 2;
  CustomerID = 0;

  while (Input[It] != ' ') {
    CustomerID *= 10;
    CustomerID += Input[It] - '0';
    It++;
  }
  It++;
  MediaType = Input[It];
  It += 2;
  MovieType = Input[It];
  It += 2;

  while (Input[It] != '\0') {
    SortingElement += Input[It];
    It++;
  }
}

// Reforms the original code from the transaction data
std::string Transaction::reformString() {
  std::string Result;
  Result += Action;
  Result += " " + std::to_string(CustomerID) + " " + MediaType + " " +
            MovieType + " " + SortingElement;
  return Result;
}