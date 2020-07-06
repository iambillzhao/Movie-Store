/*
 * Customer.cpp is part of the Movie Store Simulator, a C++ program that
 * offers the function of borrow, return, or stock with up to 10,000
 * customers and 26 genres of movies
 *
 * @author Bill Zhao, Lucas Bradley
 * @date March 12th
 */

#include "customer.h"

/*
 * Constructs a customer with a given ID and name
 *
 * @param Input   a given string with the customer's ID, first name, and
 *                last name.
 */
Customer::Customer(std::string Input) {
  CustomerID = 0;
  int It = 0;

  while (Input[It] != ' ') {
    CustomerID *= 10;
    if (CustomerID > 9999)
      return;
    CustomerID += Input[It] - '0';
    It++;
  }
  It++;

  while (Input[It] != '\0') {
    Name += Input[It];
    It++;
  }
}

/*
 * Destructs the customer and delete all from the store
 */
Customer::~Customer() {
  for (auto I : History) {
    delete I;
  }
}

/*
 * Adds the given transaction to the given customer's history
 *
 * @param Input   the given transaction detail with information of the movie
 *                and the detailed action
 */
bool Customer::addTransaction(std::string Input) {
  auto *Current = new Transaction(std::move(Input));
  History.push_back(Current);
  return true;
}

/*
 * Prints the customer's history to console
 */
void Customer::printHistory() const {
  std::cout << "Customer " << CustomerID << " " << Name << " "
            << "History:\n";
  for (auto I : History) {
    std::cout << I->reformString() << std::endl;
  }
}
