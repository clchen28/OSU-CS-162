# Lab5 makefile
# Author: Charles Chen
# Date: 02/05/2017

CXX = g++
CXXFLAGS = -std=c++0x
OBJS = inputValidator.o Lab6.o Node.o
SRCS = inputValidator.cpp Lab6.cpp Node.cpp

all: ${OBJS}
	${CXX} ${OBJS} -o Lab6

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -f a.out ${OBJS} Lab6
