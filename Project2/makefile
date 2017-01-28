# Project2 makefile
# Author: Charles Chen
# Date: 01/27/2017

all: Item.o List.o Project2.o inputValidator.o menu.o
	g++ -std=c++0x inputValidator.o Item.o List.o menu.o Project2.o -o Project2

itemTest: itemTest.o Item.o
	g++ -std=c++0x itemTest.o Item.o -o itemTest

inputValidator.o: inputValidator.cpp
	g++ -std=c++0x -c inputValidator.cpp

Item.o: Item.cpp
	g++ -std=c++0x -c Item.cpp

List.o: List.cpp
	g++ -std=c++0x -c List.cpp

menu.o: menu.cpp
	g++ -std=c++0x -c menu.cpp

Project2.o: Project2.cpp
	g++ -std=c++0x -c Project2.cpp

itemTest.o: itemTest.cpp
	g++ -std=c++0x -c itemTest.cpp
	
clean:
	rm -f *.o a.out Project2 itemTest
