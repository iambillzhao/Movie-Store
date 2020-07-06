#!/bin/bash

# To more easily compile and run this program on CSS Linux Lab
# Lines starting with '$' indicate what is typed on command line

# if you get the following error:
# -bash: ./simplecompile.sh: /bin/bash^M: bad interpreter: No such file or directory
# run dos2unix to fix it
# $ dos2unix simplecompile.sh

# make this file executable
# $ chmod 700 simplecompile.sh
# redirect the output and stderr from this file to output.txt
# $ ./simplecompile.sh > output.txt 2>&1


date

# Display machine name
if hash uname 2>/dev/null; then
  uname -a
fi

# Display user name
if hash id 2>/dev/null; then
  id
fi


echo "*** compiling with clang++ to create an executable called myprogram"
clang++ --version
clang++ -std=c++14 -Wall -Wextra -Wno-sign-compare *.cpp -g -o myprogram

if [ -f myprogram ]; then
  echo "*** running myprogram"
  ./myprogram
else
    echo "*** ERROR could not produce myprogram"
fi


if hash clang-tidy 2>/dev/null; then
  echo "*** running clang-tidy using options from .clang-tidy"
  clang-tidy --version
  clang-tidy *.cpp -- -std=c++14
else
  echo "*** ERROR clang-tidy is not available on this system "
fi


if hash clang-format 2>/dev/null; then
  echo "*** running clang-format format formatting suggestions"
  clang-format -style=llvm -dump-config > .clang-format
  for i in *.cpp; do
    echo "*** formatting suggestions for $i"
    clang-format $i | diff $i -
  done
else
  echo "*** ERROR clang-format is not available on this system"
fi

if hash valgrind 2>/dev/null; then
  if [ -f myprogram ]; then
    echo "*** running valgrind to detect memory leaks"
    valgrind ./myprogram
  else
    echo "*** ERROR could not find executable to test with valgrind"
  fi
else
  echo "*** ERROR valgrind is not available on this system"
fi


echo "*** cleaning up, deleting myprogram"
rm myprogram

date