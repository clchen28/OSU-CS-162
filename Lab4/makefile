# Lab3 makefile
# Author: Charles Chen
# Date: 01/30/2017

all: Building.o Faculty.o inputValidator.o Lab4.o menu.o Person.o Student.o University.o
	g++ -std=c++0x Building.o Faculty.o inputValidator.o Lab4.o menu.o Person.o Student.o University.o -o Lab4

Building.o: Building.cpp
	g++ -std=c++0x -c Building.cpp

Faculty.o: Faculty.cpp
	g++ -std=c++0x -c Faculty.cpp

inputValidator.o: inputValidator.cpp
	g++ -std=c++0x -c inputValidator.cpp

Lab4.o: Lab4.cpp
	g++ -std=c++0x -c Lab4.cpp

menu.o: menu.cpp
	g++ -std=c++0x -c menu.cpp

Person.o: Person.cpp
	g++ -std=c++0x -c Person.cpp

Student.o: Student.cpp
	g++ -std=c++0x -c Student.cpp

University.o: University.cpp
	g++ -std=c++0x -c University.cpp
	
clean:
	rm -f *.o a.out Lab4
