# Project3 makefile
# Author: Charles Chen
# Date: 01/23/2017

all: Die.o Lab3.o LoadedDie.o Game.o
	g++ -std=c++0x Die.o Lab3.o LoadedDie.o Game.o -o Lab3

Die.o: Die.cpp
	g++ -std=c++0x -c Die.cpp

Lab3.o: Lab3.cpp
	g++ -std=c++0x -c Lab3.cpp

LoadedDie.o: LoadedDie.cpp
	g++ -std=c++0x -c LoadedDie.cpp

Game.o: Game.cpp
	g++ -std=c++0x -c Game.cpp

menutest: menu.cpp menu.hpp menuTest.cpp inputValidator.cpp
	g++ -std=c++0x menu.cpp menuTest.cpp inputValidator.cpp -o menuTest

clean:
	rm -f *.o a.out Lab3 menutest
