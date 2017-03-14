# Final Project makefile
# Author: Charles Chen
# Date: 3/11/2017

CXX = g++
CXXFLAGS = -std=c++0x
OBJS = Backpack.o Game.o inputValidator.o ItemRoom.o Player.o Room.o test.o
SRCS = Backpack.cpp Game.cpp inputValidator.cpp ItemRoom.cpp Player.cpp Room.cpp test.cpp

all: ${OBJS}
	${CXX} ${OBJS} -o FinalProject

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -f a.out ${OBJS} FinalProject
