/*
 * movie.h is part of the Movie Store Simulator, a C++ program that
 * offers the function of borrow, return, or stock with up to 10,000
 * customers and 26 genres of movies
 *
 * @author Bill Zhao, Lucas Bradley
 * @date March 12th
*/

#pragma once
#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>

class Movie {
public:
  // Default constructor
  Movie();
  // Virtual default constructor
  virtual ~Movie() = default;
  // Virtual print prints movie contents
  virtual void print() = 0;
  // Virtual type returns movie type
  virtual char type() = 0;
  // Virtual reformString in subclass returns
  // original input string
  virtual std::string reformString() = 0;
  // Virtual sortingElement in subcalss returns
  // formatted string according to class
  virtual std::string sortingElement() = 0;
  // Virtual inventoryDisplayHelper in subclass returns
  // a string of orginal plus the borrowed number
  virtual std::string inventoryDisplayHelper() = 0;
  // Virtual borrowMovie in subclass marks if movie borrowed
  // returns false if it rejects operation
  virtual bool borrowMovie() = 0;
  // Virtual returnMovie in subclass marks if movie returned
  // returns false if it rejects operation
  virtual bool returnMovie() = 0;
private:

};

#endif