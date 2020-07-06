/**
 * Testing ass4 movie store functions
 *
 * @author Yusuf Pisan
 * @date 19 Jan 2019
 */

#include "customer.h"
#include "factory.h"
#include "hashtable.h"
#include "store.h"
#include "transaction.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

// Tests that file reading is working
void testStore1() {
  std::cout << "=====================================" << std::endl;
  std::cout << "Start testStore1" << std::endl;
  // Should do something more, but lets just read files
  // since each implementation will
  std::string Cfile = "testcommands-1.txt";
  std::stringstream Out;
  std::ifstream Fs(Cfile);
  assert(Fs.is_open());
  char CommandType;
  std::string Discard;
  while (Fs >> CommandType) {
    Out << CommandType;
    getline(Fs, Discard);
  }
  Fs.close();
  std::string Result = "IHHBRIBBIH";
  assert(Out.str() == Result);
  std::cout << "End testStore1" << std::endl;
}

// Test that the factory works as expected
void factoryTest() {
  std::cout << "=====================================" << std::endl;
  std::cout << "Start factoryTest" << std::endl;
  Factory Fact;

  Movie *D = Fact.buildMovie("D, 10, Steven Spielberg, Schindler's List, 1993");
  assert(D->reformString() ==
         "D, 10, Steven Spielberg, Schindler's List, 1993");
  assert(D->type() == 'D');
  assert(D->sortingElement() == "Steven Spielberg, Schindler's List");
  delete D;

  Movie *F = Fact.buildMovie("F, 10, Nora Ephron, You've Got Mail, 1998");
  assert(F->reformString() == "F, 10, Nora Ephron, You've Got Mail, 1998");
  assert(F->type() == 'F');
  assert(F->sortingElement() == "You've Got Mail, 1998");
  delete F;

  Movie *C =
      Fact.buildMovie("C, 10, George Cukor, Holiday, Katherine Hepburn 9 1938");
  assert(C->reformString() ==
         "C, 10, George Cukor, Holiday, Katherine Hepburn 9 1938");
  assert(C->type() == 'C');
  assert(C->sortingElement() == "9 1938 Katherine Hepburn");
  delete C;

  Movie *Z =
      Fact.buildMovie("Z, 10, George Cukor, Holiday, Katherine Hepburn 9 1938");
  assert(Z == nullptr);
  std::cout << "End factoryTest" << std::endl;
}

// Tests that the store works as expected
void storeTest() {
  std::cout << "=====================================" << std::endl;
  std::cout << "Start storeTest" << std::endl;
  Store Sto;
  Factory Fac;

  assert(Sto.insertFilm("D, 10, Steven Spielberg, Schindler's List, 1993"));
  Movie *D = Fac.buildMovie("D, 10, Steven Spielberg, Schindler's List, 1993");
  assert(Sto.findFilm(D));
  delete D;

  assert(Sto.insertFilm("F, 10, Nora Ephron, You've Got Mail, 1998"));
  Movie *F = Fac.buildMovie("F, 10, Nora Ephron, You've Got Mail, 1998");
  assert(Sto.findFilm(F));
  delete F;

  assert(
      Sto.insertFilm("C, 10, George Cukor, Holiday, Katherine Hepburn 9 1938"));
  Movie *C =
      Fac.buildMovie("C, 10, George Cukor, Holiday, Katherine Hepburn 9 1938");
  assert(Sto.findFilm(C));
  delete C;

  assert(!Sto.insertFilm(
      "Z, 10, George Cukor, Holiday, Katherine Hepburn 9 1938"));
  std::cout << "End storeTest" << std::endl;
}

// Tests that the hashtable works as expected
void hashTest() {
  std::cout << "=====================================" << std::endl;
  std::cout << "Start hashTest" << std::endl;
  HashTable H;
  Factory Fact;
  Movie *D = Fact.buildMovie("D, 10, Steven Spielberg, Schindler's List, 1993");
  Movie *F = Fact.buildMovie("F, 10, Nora Ephron, You've Got Mail, 1998");
  Movie *C =
      Fact.buildMovie("C, 10, George Cukor, Holiday, Katherine Hepburn 9 1938");

  assert(H.insert(D));
  assert(H.insert(F));
  assert(H.insert(C));

  assert(H.find(D));
  assert(H.find(F));
  assert(H.find(C));

  Movie *D2 =
      Fact.buildMovie("D, 10, Phillippe De Broca, King of Hearts, 1967");
  assert(!H.find(D2));
  delete D2;
  std::cout << "End hashTest" << std::endl;
}

// Chackes that file reading works as expected
void fileTest() {
  std::cout << "=====================================" << std::endl;
  std::cout << "Start fileTest" << std::endl;
  Store S("testMovies.txt", "null", "null");
  Factory Fact;
  Movie *M1 = Fact.buildMovie("F, 1, A, A, 1");
  Movie *M2 = Fact.buildMovie("D, 1, B, B, B, 1");
  Movie *M3 = Fact.buildMovie("C, 1, C, C, C 1 1111");
  Movie *M4 = Fact.buildMovie("C, 1, D, D, D 1 1111");
  Movie *M5 = Fact.buildMovie("Z, 1, E, E, E 1 1111");
  Movie *M6 = Fact.buildMovie("D, 1, F, F, 1");
  Movie *M7 = Fact.buildMovie("D, 1, G, G, 1");
  assert(S.findFilm(M1));
  assert(S.findFilm(M2));
  assert(S.findFilm(M3));
  assert(S.findFilm(M4));
  assert(!S.findFilm(M5));
  assert(S.findFilm(M6));
  assert(!S.findFilm(M7));

  delete M1;
  delete M2;
  delete M3;
  delete M4;
  delete M5;
  delete M6;
  delete M7;
  std::cout << "End fileTest" << std::endl;
}

// Checks that inventoryDisplay works as expected
void inventoryDisplayTest() {
  std::cout << "=====================================" << std::endl;
  std::cout << "Start inventoryDisplayTest" << std::endl;
  Store S("testMovies.txt", "null", "null");
  S.inventoryDisplay();
  std::cout << "End inventoryDisplayTest" << std::endl;
}

// Tests that transaction class works as expected
void transactionTest() {
  std::cout << "=====================================" << std::endl;
  std::cout << "Start transactionTest" << std::endl;
  Transaction T1("B 1234 D C 9 1938 Katherine Hepburn");
  assert(T1.reformString() == "B 1234 D C 9 1938 Katherine Hepburn");
  Transaction T2("R 1234 D C 9 1938 Katherine Hepburn");
  assert(T2.reformString() == "R 1234 D C 9 1938 Katherine Hepburn");
  std::cout << "End transactionTest" << std::endl;
}

// Tests that customer class works as expected
void customerTest() {
  std::cout << "=====================================" << std::endl;
  std::cout << "Start customerTest" << std::endl;
  Customer C1("1111 Mouse Mickey");
  C1.addTransaction("B 1111 D C 9 1938 Katherine Hepburn");
  C1.addTransaction("R 1111 D C 9 1938 Katherine Hepburn");
  C1.addTransaction("B 1111 D F Pirates of the Caribbean, 2003");
  std::cout << std::endl;
  C1.printHistory();

  Store S;
  S.insertCustomer("1111 Mouse Mickey");
  S.addTransaction("B 1111 D C 9 1938 Katherine Hepburn");
  S.addTransaction("R 1111 D C 9 1938 Katherine Hepburn");
  S.addTransaction("B 1111 D F Pirates of the Caribbean, 2003");
  std::cout << std::endl;
  S.historyDisplay(1111);
  std::cout << "End customerTest" << std::endl;
}

// Tests that the actions work as expected
void actionTest() {
  std::cout << "=====================================" << std::endl;
  std::cout << "Start actionTest" << std::endl;
  Store S;
  S.insertCustomer("1111 Lucas Bradley");
  S.insertFilm("F, 10, Nora Ephron, You've Got Mail, 1998");
  S.insertFilm("D, 1, Steven Spielberg, Schindler's List, 1993");
  S.insertFilm("C, 10, George Cukor, Holiday, Katherine Hepburn 9 1938");
  assert(S.borrowFilm("B 1111 D C 9 1938 Katherine Hepburn"));
  assert(S.returnFilm("R 1111 D C 9 1938 Katherine Hepburn"));
  assert(!S.returnFilm("R 1111 D C 9 1938 Katherine Hepburn"));
  assert(S.borrowFilm("B 1111 D C 9 1938 Katherine Hepburn"));
  assert(!S.borrowFilm("B 1111 D F Pirates of the caribbean, 2003"));
  S.inventoryDisplay();
  S.historyDisplay(1111);
  std::cout << "End actionTest" << std::endl;
}

// Test with the given files
void testStoreFinal() {
  std::cout << "=====================================" << std::endl;
  std::cout << "Start testStoreFinal" << std::endl;
  Store S("data4movies.txt", "data4customers.txt", "data4commands.txt");
  std::cout << "End testStoreFinal" << std::endl;
  std::cout << "=====================================" << std::endl;
}

// Runs all tests
void testAll() {
  std::ofstream OutFile;
  OutFile.open("testMovies.txt");
  if (OutFile) {
    std::string FileInit =
        "F, 1, A, A, 1\nD, 1, B, B, 1\nC, 1, C, C, C 1 1111\nC, 1, D, D, D 1 "
        "1111\nZ, 1, E, E, E 1 1111\nD, 1, F, F, 1";
    OutFile << FileInit;
    OutFile.close();
  }

  testStore1();
  factoryTest();
  storeTest();
  hashTest();
  fileTest();
  inventoryDisplayTest();
  transactionTest();
  customerTest();
  actionTest();
  testStoreFinal();
}
