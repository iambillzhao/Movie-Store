/*
 * classic.h is part of the Movie Store Simulator, a C++ program that
 * offers the function of borrow, return, or stock with up to 10,000
 * customers and 26 genres of movies
 *
 * @author Bill Zhao, Lucas Bradley
 * @date March 12th
*/


#pragma once
#ifndef CLASSIC_H
#define CLASSIC_H

#include "movie.h"

class Classic : public Movie {
  friend class Store;
public:
  // No memory is allocated in the classic class
  // so it has a default destructor
  ~Classic() override = default;
  // The constructor takes a string and turns it into
  // a classic movie object
  explicit Classic(std::string Input);
  // This function simply prints the contents of the
  // classic movie object
  void print() override;
  // This is a accessor function for the type of movie
  char type() override;
  // This is a accessor function which reforms the
  // original string input
  std::string reformString() override;
  // This is an accessor for the sorting element of the classic movie
  std::string sortingElement() override;
  // Inventory display helper reforms the total string
  std::string inventoryDisplayHelper() override;
  // This function operates on the classic movie to mark
  // as borrowed or deny the function call
  bool borrowMovie() override;
  // This function operates ont he classic movie to mark
  // as returned or deny the function call
  bool returnMovie() override;
private:
  char Type;
  int Stock;
  std::string Director;
  std::string Title;
  std::string MajorActor;
  std::string Release;
  int Borrowed;
};


#endif