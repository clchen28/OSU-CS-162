# Lab5 makefile
# Author: Charles Chen
# Date: 02/05/2017

CXX = g++
CXXFLAGS = -std=c++0x
OBJS = Barbarian.o BlueMen.o Creature.o Die.o HarryPotter.o Medusa.o Project3.o Vampire.o
SRCS = Barbarian.cpp BlueMen.cpp Creature.cpp Die.cpp HarryPotter.cpp Medusa.cpp Project3.cpp Vampire.cpp

all: ${OBJS}
	${CXX} ${LDFLAGS} ${OBJS} -o Project3

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -f a.out ${OBJS} Project3
