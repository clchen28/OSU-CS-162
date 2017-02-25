# Lab5 makefile
# Author: Charles Chen
# Date: 02/05/2017

CXX = g++
CXXFLAGS = -std=c++0x
OBJS = ListNode.o LoserStack.o testLoserStack.o Barbarian.o BlueMen.o Creature.o HarryPotter.o Medusa.o Vampire.o Die.o
SRCS = ListNode.cpp LoserStack.cpp testLoserStack.cpp Barbarian.cpp BlueMen.cpp Creature.cpp HarryPotter.cpp Medusa.cpp Vampire.cpp Die.cpp

all: ${OBJS}
	${CXX} ${OBJS} -o Project4

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -f a.out ${OBJS} Project4
