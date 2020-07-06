/*
 * store.cpp is part of the Movie Store Simulator, a C++ program that
 * offers the function of borrow, return, or stock with up to 10,000
 * customers and 26 genres of movies
 *
 * @author Bill Zhao, Lucas Bradley
 * @date March 12th
 */

#include "store.h"
#include <fstream>

// Default constructor
Store::Store() = default;

// Takes three strings which are file names and fills in all fo the
// data according to the contents of the files
Store::Store(const std::string &Movies, const std::string &Customers,
             const std::string &Commands) {
  std::ifstream InputStream;
  InputStream.open(Movies.c_str());
  if (!InputStream.is_open()) {
    return;
  }
  std::string Code;
  char Char;
  InputStream.get(Char);
  while (!InputStream.eof()) {
    if (Char != '\0' && Char != '\n') {
      Code += Char;
    } else {
      insertFilm(Code);
      Code.erase();
    }
    InputStream.get(Char);
  }
  insertFilm(Code);
  Code.erase();
  InputStream.close();

  InputStream.open(Customers.c_str());
  if (!InputStream.is_open()) {
    return;
  }
  InputStream.get(Char);
  while (!InputStream.eof()) {
    if (Char != '\0' && Char != '\n') {
      Code += Char;
    } else {
      insertCustomer(Code);
      Code.erase();
    }
    InputStream.get(Char);
  }
  insertCustomer(Code);
  Code.erase();
  InputStream.close();

  InputStream.open(Commands.c_str());
  if (!InputStream.is_open()) {
    return;
  }
  InputStream.get(Char);
  while (!InputStream.eof()) {
    if (Char != '\0' && Char != '\n') {
      Code += Char;
    } else {
      action(Code);
      Code.erase();
    }
    InputStream.get(Char);
  }
  action(Code);
  Code.erase();
  InputStream.close();
}

// Store destructor
Store::~Store() {
  for (auto &Customer : Customers) {
    delete Customer.second;
  }
}

// Inserts film in the correct postion of inventory
bool Store::insertFilm(std::string Code) {
  Movie *Film = F.buildMovie(std::move(Code));
  if (Film == nullptr) {
    return false;
  }
  return Inventory.insert(Film);
}

// Checks if film exists in the inventory
bool Store::findFilm(Movie *Film) { return Inventory.find(Film); }

// Inserts customer int he correct positon of Customers
bool Store::insertCustomer(std::string Code) {
  auto *Cust = new Customer(Code);
  int CustomerCode = 0;
  int It = 0;

  while (Code[It] != ' ') {
    CustomerCode *= 10;
    CustomerCode += Code[It] - '0';
    It++;
  }
  if (Customers.find(CustomerCode) != Customers.end()) {
    delete Cust;
    return false;
  }
  Customers[CustomerCode] = Cust;
  return true;
}

// Displays the contents of the inventory in sorted order
void Store::inventoryDisplay() {
  std::cout << "Inventory:\n\n";
  // F,D,C
  std::map<std::string, Movie *> *GenreMapF = Inventory.genreMap('F');
  std::cout << "Comedy: " << std::endl;
  std::cout << "Genre, Stock, Director, Title, Year of Release, Borrowed\n";
  auto FItF = GenreMapF->begin();
  while (FItF != GenreMapF->end()) {
    std::cout << FItF->second->inventoryDisplayHelper() << std::endl;
    FItF++;
  }
  std::cout << std::endl;

  std::map<std::string, Movie *> *GenreMapD = Inventory.genreMap('D');
  std::cout << "Drama: " << std::endl;
  std::cout << "Genre, Stock, Director, Title, Year of Release, Borrowed\n";
  auto FItD = GenreMapD->begin();
  while (FItD != GenreMapD->end()) {
    std::cout << FItD->second->inventoryDisplayHelper() << std::endl;
    FItD++;
  }
  std::cout << std::endl;

  std::map<std::string, Movie *> *GenreMapC = Inventory.genreMap('C');
  std::cout << "Classic: " << std::endl;
  std::cout
      << "Genre, Stock, Director, Title, Major Actor Release Date, Borrowed\n";
  auto FItC = GenreMapC->begin();
  while (FItC != GenreMapC->end()) {
    std::cout << FItC->second->inventoryDisplayHelper() << std::endl;
    FItC++;
  }
  std::cout << std::endl;
}

// Displays specific customers history
void Store::historyDisplay(int CustomerCode) {
  if (Customers.find(CustomerCode) == Customers.end()) {
    return;
  }
  Customers[CustomerCode]->printHistory();
}

// Borrow film will take command and edit Customers and
// inventory accordingly
bool Store::borrowFilm(std::string Code) {
  int It = 2;
  // int CustomerCode = 0;

  while (Code[It] != ' ') {
    It++;
  }

  It += 3;
  char MovieType = Code[It];
  It += 2;

  std::string SortingElement;
  while (Code[It] != '\0') {
    SortingElement += Code[It];
    It++;
  }

  std::map<std::string, Movie *> *GenreMap = Inventory.genreMap(MovieType);
  if (GenreMap == nullptr) {
    return false;
  }

  if (GenreMap->find(SortingElement) == GenreMap->end()) {
    return false;
  }
  if (!GenreMap->at(SortingElement)->borrowMovie()) {
    return false;
  }

  addTransaction(Code);
  return true;
}

// Return film will take command and edit Customers and
// inventory accordingly
bool Store::returnFilm(std::string Code) {
  int It = 2;
  // int CustomerCode = 0;

  while (Code[It] != ' ') {
    It++;
  }

  It += 3;
  char MovieType = Code[It];
  It += 2;

  std::string SortingElement;
  while (Code[It] != '\0') {
    SortingElement += Code[It];
    It++;
  }

  std::map<std::string, Movie *> *GenreMap = Inventory.genreMap(MovieType);
  if (GenreMap == nullptr) {
    return false;
  }

  if (GenreMap->find(SortingElement) == GenreMap->end()) {
    return false;
  }

  if (!GenreMap->at(SortingElement)->returnMovie()) {
    return false;
  }

  addTransaction(Code);
  return true;
}

// Takes a code and adds the information to the
// customers history
bool Store::addTransaction(std::string Code) {
  int CustomerCode = 0;
  int It = 2;

  while (Code[It] != ' ') {
    CustomerCode *= 10;
    CustomerCode += Code[It] - '0';
    It++;
  }

  if (Customers.find(CustomerCode) == Customers.end()) {
    return false;
  }
  Customers[CustomerCode]->addTransaction(Code);
  return true;
}

// Determines which action to do depending on code
bool Store::action(std::string Code) {
  if (Code[0] == 'B') {
    return borrowFilm(Code);
  }
  if (Code[0] == 'R') {
    return returnFilm(Code);
  }
  if (Code[0] == 'H') {
    int It = 2;
    int CustomerCode = 0;
    while (Code[It] != '\0') {
      CustomerCode *= 10;
      CustomerCode += Code[It] - '0';
      It++;
    }
    historyDisplay(CustomerCode);
    return true;
  }
  if (Code[0] == 'I') {
    inventoryDisplay();
    return true;
  }
  return false;
}