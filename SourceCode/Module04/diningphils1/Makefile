#
# File:    Makefile
# Author:  Adam.Lewis@athens.edu
# Purpose:
# Makefile for constructing the CS415 Dining Philosopher's
# Simulation.
#
EXECUTABLES = diningphil

# Note that building on Linux or other POSIX-compliant
# OS requires that we link with the Pthreads library.
# Note also that are building with GDB debug support.
CFLAGS = -pthread -I. -g -std=c++14 

all: $(EXECUTABLES)

clean:
	rm -rf core *.o $(EXECUTABLES) a.out *.dSYM

.SUFFIXES: .cpp .o

diningphil: diningphil.cpp
	$(CXX) $(CFLAGS) -o diningphil diningphil.cpp
