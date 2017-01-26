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

dieTest.o: dieTest.cpp
	g++ -std=c++0x -c dieTest.cpp

inputValidator.o: inputValidator.cpp
	g++ -std=c++0x -c inputValidator.cpp

dietest: dieTest.o LoadedDie.o Die.o inputValidator.o
	g++ -std=c++0x dieTest.o LoadedDie.o Die.o inputValidator.o -o dieTest

clean:
	rm -f *.o a.out Lab3 dieTest
