CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -Werror
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.hpp)
OBJECTS = $(wildcard *.o)
OUTPUT = war

${OUTPUT}: ${SOURCES} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SOURCES} -o ${OUTPUT}

clean:
	rm *.o ${OUTPUT}

#target: dependencies
	#action

#${OBJECTS}: ${SOURCES}
	#${CXX} ${CXXFLAGS} -c ${@:.o=.cpp}

#LDFLAGS