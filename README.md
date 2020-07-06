# Movie Store Simulator

## Project Information

Authors: [Bill Zhao](https://github.com/iambillzhao),
         [Lucas Bradley](https://github.com/LucasBradley01)

## Project Description


The files in this repository are the submissions of Assignment 4: Movies
of CSS 343 at the UW. This project was pair programmed by 
[Bill Zhao](https://github.com/iambillzhao) and 
[Lucas Bradley](https://github.com/LucasBradley01) in March 2020.

This project fully utilizes the benefits of polymorphism and factory patterns
of Object-oriented programming. In which, each functionality at different 
levels are being factored into smaller classes for changeability and
simplicity.

This movie rental store simulator allows customers to easily add genres, types
of media, and additional movies to the existing program. Currently, "borrow",
"return", "inventory", and "history" are being implemented as the core
functionality and more could be added with additional classes.

## Project Checklist

Development Platform: Microsoft Windows

Tested on Linux Lab: YES!

Tested on Travis CI: YES!

Fixed clang-tidy messages: YES!

Fixed valgrind messages: YES!

## Command Functionality Checklist

Inventory: Fully implemented!

History: Fully implemented!

Borrow: Fully implemented!

Return: Fully implemented!

## Location of error message or functionality

State the file and function where the information can be found

invalid command code: The request besides the allowed functions will be denied

invalid movie type: The movie will not be created and the program will continue
                    to operate under the original state

invalid customer ID: The customer will not be created and such customer-related
                     functions cannot be used, all access denied
 
invalid movie: The movie that are duplicate, or with missing information cannot
               be created and all related functions are automatically ignored
               until all information are gathered.

factory classes: defined in ``factory.cpp``.
<br> 'F' stands for comedy, 'C' stands for classic, 'D' stands for drama.

hashtable: hashtable is the container for all movies, with a string as its
           value and a movie pointer to the corresponding movie

container used for comedy movies: comedy movies are stored in the hashtable
                                  with its unique identifier f.

function for sorting comedy movies: defined in ``transaction.cpp``.

function where comedy movies are sorted: sorting elements are defined in
``comedy.cpp``.

functions called when retrieving a comedy movie based on title and year:
the function ``std::string Comedy::sortingElement()`` will be called to
identify the order of comedy movies and retrieve the movie according to
the given title and year.

functions called for retrieving and printing customer history:
``void printHistory() const`` in ``customer.cpp``.

container used for customer history: a vector of all transactions.

functions called when borrowing a movie: depending on the genre, it will call
                                         the borrow function in the
                                         corresponding class.

explain borrowing a movie that does not exist: the corresponding request will
                                               be denied and the transaction
                                               is failed because it can not be
                                               found in the store inventory.

explain borrowing a movie that has 0 stock: the corresponding request will be
                                            denied and the transaction is 
                                            failed because there is no more
                                            movies to borrow.

explain returning a movie that customer has not checked out: the corresponding
                                                             request will be
                                                             accepted and the
                                                             transaction is
                                                             recorded because
                                                             the movie could be
                                                             returned by a
                                                             friend of the
                                                             original borrower.

any static_cast or dynamic_cast: most functions are inherited and none are
                                 casted currently


