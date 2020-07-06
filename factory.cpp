/*
 * factory.cpp is part of the Movie Store Simulator, a C++ program that
 * offers the function of borrow, return, or stock with up to 10,000
 * customers and 26 genres of movies
 *
 * @author Bill Zhao, Lucas Bradley
 * @date March 12th
 */

#include "factory.h"
#include <iostream>

// buildMovie takes a string Input and builds the
// movie according to specifications
Movie *Factory::buildMovie(std::string Input) {
  char Type = Input[0];

  if (Type == 'F')
    return new Comedy(Input);

  if (Type == 'C')
    return new Classic(Input);

  if (Type == 'D')
    return new Drama(Input);

  return nullptr;
}