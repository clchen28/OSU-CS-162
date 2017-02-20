# Lab7 makefile
# Author: Charles Chen
# Date: 02/19/2017

CXX = g++
CXXFLAGS = -std=c++0x
OBJS = Queue.o inputValidator.o Lab7.o
SRCS = Queue.cpp inputValidator.cpp Lab7.cpp

all: ${OBJS}
	${CXX} ${OBJS} -o Lab7

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -f a.out ${OBJS} Lab7
