# Lab5 makefile
# Author: Charles Chen
# Date: 02/05/2017

CXX = g++
CXXFLAGS = -std=c++0x
OBJS = Barbarian.o Creature.o Die.o Medusa.o Project3.o
SRCS = Barbarian.cpp Creature.cpp Die.cpp Medusa.cpp Project3.cpp

all: ${OBJS}
	${CXX} ${LDFLAGS} ${OBJS} -o Project3

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -f a.out ${OBJS} Project3
