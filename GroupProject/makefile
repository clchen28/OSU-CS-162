# Group Project makefile
# Author: Charles Chen
# Date: 02/19/2017

CXX = g++
CXXFLAGS = -std=c++0x
OBJS = Paper.o Rock.o Scissors.o Tool.o testTools.o
SRCS = Paper.cpp Rock.cpp Scissors.cpp Tool.cpp testTools.cpp

all: ${OBJS}
	${CXX} ${OBJS} -o GroupProject

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -f a.out ${OBJS} GroupProject
