# Lab5 makefile
# Author: Charles Chen
# Date: 02/05/2017

CXX = g++
CXXFLAGS = -std=c++0x
OBJS = inputValidator.o Lab5.o revStr.o sumArr.o triNum.o
SRCS = inputValidator.cpp Lab5.cpp revStr.cpp sumArr.cpp triNum.cpp

all: ${OBJS}
	${CXX} ${LDFLAGS} ${OBJS} -o Lab5

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -f a.out *.o Lab5