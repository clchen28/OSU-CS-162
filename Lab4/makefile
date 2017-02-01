# Lab3 makefile
# Author: Charles Chen
# Date: 01/30/2017

all: Building.o Faculty.o Lab4.o People.o Student.o
	g++ -std=c++0x Building.o Faculty.o Lab4.o People.o Student.o -o Lab4

Building.o: Building.cpp
	g++ -std=c++0x -c Building.cpp

Faculty.o: Faculty.cpp
	g++ -std=c++0x -c Faculty.cpp

Lab4.o: Lab4.cpp
	g++ -std=c++0x -c Lab4.cpp

People.o: People.cpp
	g++ -std=c++0x -c People.cpp

Student.o: Student.cpp
	g++ -std=c++0x -c Student.cpp
	
clean:
	rm -f *.o a.out Lab4
