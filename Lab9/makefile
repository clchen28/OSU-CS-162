# Project4 makefile
# Author: Charles Chen
# Date: 03/07/2017

CXX = g++
CXXFLAGS = -std=c++0x
OBJS = inputValidator.o Lab9.o Queue.o StringStack.o
SRCS = inputValidator.cpp Lab9.cpp Queue.cpp StringStack.cpp

all: ${OBJS}
	${CXX} ${OBJS} -o Lab9

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -f a.out ${OBJS} Lab9
