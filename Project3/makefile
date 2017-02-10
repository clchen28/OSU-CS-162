# Lab5 makefile
# Author: Charles Chen
# Date: 02/05/2017

CXX = g++
CXXFLAGS = -std=c++0x
OBJS = Barbarian.o BlueMen.o Creature.o Die.o Game.o HarryPotter.o inputValidator.o Medusa.o menu.o Project3.o Vampire.o
SRCS = Barbarian.cpp BlueMen.cpp Creature.cpp Die.cpp Game.cpp HarryPotter.cpp inputValidator.cpp Medusa.cpp menu.cpp Project3.cpp Vampire.cpp
TESTOBJS = Barbarian.o BlueMen.o Creature.o Die.o Game.o HarryPotter.o Medusa.o testRolls.o Vampire.o
TESTSRCS = Barbarian.cpp BlueMen.cpp Creature.cpp Die.cpp Game.cpp HarryPotter.cpp Medusa.cpp testRolls.cpp Vampire.cpp

all: ${OBJS}
	${CXX} ${OBJS} -o Project3

${TESTOBJS}: ${TESTSRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

testRolls: $(TESTOBJS)
	${CXX} ${CXXFLAGS} $(TESTOBJS) -o testRolls

clean:
	rm -f a.out ${TESTOBJS} Project3 testRolls
