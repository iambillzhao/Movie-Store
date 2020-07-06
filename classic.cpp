/*
 * classic.cpp is part of the Movie Store Simulator, a C++ program that
 * offers the function of borrow, return, or stock with up to 10,000
 * customers and 26 genres of movies
 *
 * @author Bill Zhao, Lucas Bradley
 * @date March 12th
 */

#include "classic.h"

#include <iostream>

// The constructor takes a string and turns it into
// a classic movie object
Classic::Classic(std::string Input) {
  Type = Input[0];
  int It = 3;
  Stock = 0;

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

  while (!(Input[It] >= '0' && Input[It] <= '9')) {
    MajorActor += Input[It];
    It++;
  }
  MajorActor.erase(MajorActor.end() - 1, MajorActor.end());

  while (Input[It] != '\0') {
    Release += Input[It];
    It++;
  }

  Borrowed = 0;
}

// This is a accessor function for the type of movie
char Classic::type() { return Type; }

// This is a accessor function which reforms the
// original string input
std::string Classic::reformString() {
  std::string Result;
  Result += Type;
  return Result + ", " + std::to_string(Stock) + ", " + Director + ", " +
         Title + ", " + MajorActor + " " + Release;
}

// This is an accessor for the sorting element of the classic movie
std::string Classic::sortingElement() { return Release + " " + MajorActor; }

// This function simply prints the contents of the classic movie object
void Classic::print() {
  std::cout << Director << std::endl
            << Title << std::endl
            << MajorActor << std::endl
            << Release << std::endl
            << Stock << std::endl;
}

// Inventory display helper reforms the total string
std::string Classic::inventoryDisplayHelper() {
  return reformString() + ", " + std::to_string(Borrowed);
}

// This function operates on the classic movie to mark
// as borrowed or deny the function call
bool Classic::borrowMovie() {
  if (Stock == 0) {
    return false;
  }
  Stock--;
  Borrowed++;
  return true;
}

// This function operates on the classic movie to mark
// as returned or deny the function call
bool Classic::returnMovie() {
  if (Borrowed == 0) {
    return false;
  }
  Stock++;
  Borrowed--;
  return true;
}