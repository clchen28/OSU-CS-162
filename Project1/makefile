# Project1 makefile
# Author: Charles Chen
# Date: 01/15/2017

all: Ant.o Project1.o inputValidator.o menu.o
	g++ -std=c++0x Ant.o Project1.o inputValidator.o menu.o -o Project1

Ant.o: Ant.cpp
	g++ -std=c++0x -c Ant.cpp

Project1.o: Project1.cpp
	g++ -std=c++0x -c Project1.cpp

inputValidator.o: inputValidator.cpp
	g++ -std=c++0x -c inputValidator.cpp

menu.o: menu.cpp
	g++ -std=c++0x -c menu.cpp

clean:
	rm -f *.o a.out Project1
