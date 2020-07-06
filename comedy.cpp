/*
 * comedy.cpp is part of the Movie Store Simulator, a C++ program that
 * offers the function of borrow, return, or stock with up to 10,000
 * customers and 26 genres of movies
 *
 * @author Bill Zhao, Lucas Bradley
 * @date March 12th
 */

#include "comedy.h"
#include <iostream>

// The constructor takes a string and turns it into
// a comedy movie object
Comedy::Comedy(std::string Input) {
  Type = Input[0];
  int It = 3;
  Stock = 0;
  Year = 0;

  while (Input[It] != ',') {
    Stock *= 10;
    Stock += Input[It] - '0';
    It++;
  }
  It += 2;

  while (Input[It] != ',') {
    Director += Input[It];
    It++;
  }
  It += 2;

  while (Input[It] != ',') {
    Title += Input[It];
    It++;
  }
  It += 2;

  while (Input[It] != '\0') {
    Year *= 10;
    Year += Input[It] - '0';
    It++;
  }

  Borrowed = 0;
}

// This is a accessor function for the type of movie
char Comedy::type() { return Type; }

// This is a accessor function which reforms the
// original string input
std::string Comedy::reformString() {
  std::string Result;
  Result += Type;
  return Result + ", " + std::to_string(Stock) + ", " + Director + ", " +
         Title + ", " + std::to_string(Year);
}

// This is an accessor for the sorting element of the classic movie
std::string Comedy::sortingElement() {
  return Title + ", " + std::to_string(Year);
}

// This function simply prints the contents of the comedy movie object
void Comedy::print() {
  std::cout << Director << std::endl
            << Title << std::endl
            << Year << std::endl
            << Stock << std::endl;
}

// Inventory display helper reforms the total string
std::string Comedy::inventoryDisplayHelper() {
  return reformString() + ", " + std::to_string(Borrowed);
}

// This function operates on the comedy movie to mark
// as borrowed or deny the function call
bool Comedy::borrowMovie() {
  if (Stock == 0) {
    return false;
  }
  Stock--;
  Borrowed++;
  return true;
}

// This function operates on the comedy movie to mark
// as returned or deny the function call
bool Comedy::returnMovie() {
  if (Borrowed == 0) {
    return false;
  }
  Stock++;
  Borrowed--;
  return true;
}