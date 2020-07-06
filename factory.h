/*
 * factory.h is part of the Movie Store Simulator, a C++ program that
 * offers the function of borrow, return, or stock with up to 10,000
 * customers and 26 genres of movies
 *
 * @author Bill Zhao, Lucas Bradley
 * @date March 12th
*/

#pragma once
#ifndef FACTORY_H
#define FACTORY_H

#include "classic.h"
#include "comedy.h"
#include "drama.h"
#include "movie.h"
#include <string>

class Factory {
public:
  // buildMovie takes a string Input and builds the
  // movie according to specifications
  Movie* buildMovie(std::string Input);
};


#endif