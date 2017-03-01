# Lab8 makefile
# Author: Charles Chen
# Date: 02/28/2017

CXX = g++
CXXFLAGS = -std=c++0x

linearSearch: linearSearch.o
	${CXX} linearSearch.o -o linearSearch

linearSearch.o: linearSearch.cpp
	${CXX} ${CXXFLAGS} -c linearSearch.cpp

selectionSort: selectionSort.o inputValidator.o
	${CXX} selectionSort.o inputValidator.o -o selectionSort

selectionSort.o: selectionSort.cpp
	${CXX} ${CXXFLAGS} -c selectionSort.cpp

binarySearch: binarySearch.o
	${CXX} binarySearch.o -o binarySearch

binarySearch.o: binarySearch.cpp
	${CXX} ${CXXFLAGS} -c binarySearch.cpp

inputValidator.o: inputValidator.cpp
	${CXX} ${CXXFLAGS} -c inputValidator.cpp

clean:
	rm -f a.out linearSearch.o selectionSort.o binarySearch.o inputValidator.o linearSearch selectionSort binarySearch
