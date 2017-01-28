# Project3 makefile
# Author: Charles Chen
# Date: 01/27/2017

all: Item.o List.o Project2.o
	g++ -std=c++0x Item.o List.o Project2.o -o Project2

Item.o: Item.cpp
	g++ -std=c++0x -c Item.cpp

List.o: List.cpp
	g++ -std=c++0x -c List.cpp

Project2.o: Project2.cpp
	g++ -std=c++0x -c Project2.cpp

clean:
	rm -f *.o a.out Project2
