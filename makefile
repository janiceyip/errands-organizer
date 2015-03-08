# Makefile
# Created on: Mar 4, 2015
CC = g++
CFLAGS  = -g -Wall

# typing 'make' will invoke the first target entry in the file 
# (in this case the default target entry)
# you can name this target entry anything, but "default" or "all"
# are the most commonly used names by convention
#
all: main

# To create the executable file count we need the object files
#
main: main.o CompareErrands.o Graph.o Time.o Person.o
	g++ main.o CompareErrands.o Graph.o Time.o Person.o -o main

main.o: main.cpp
	g++ -c main.cpp

CompareErrands.o: CompareErrands.cpp
	g++ -c CompareErrands.cpp

Graph.o: Graph.cpp 
	g++ -c Graph.cpp

Time.o: Time.cpp
	g++ -c Time.cpp 

Person.o: Person.cpp
	g++ -c Person.cpp

clean: 
	rm main Graph Time place Errand Cards person *.o 