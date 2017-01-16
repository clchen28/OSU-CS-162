# Lab1 makefile
# Author: Charles Chen
# Date: 01/10/2017

all: Lab1.o determinant.o readMatrix.o
	g++ Lab1.o determinant.o readMatrix.o -o Lab1

Lab1.o: Lab1.cpp
	g++ -c Lab1.cpp

determinant.o: determinant.cpp
	g++ -c determinant.cpp

readMatrix.o: readMatrix.cpp
	g++ -c readMatrix.cpp

clean:
	rm *.o a.out
