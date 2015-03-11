# Makefile
# Created on: Mar 4, 2015
CC = g++
CFLAGS  = -g -Wall


all: main

# To create the executable file count we need the object files
main: main.o CompareErrands.o Time.o Person.o RunErrands.o
	g++ main.o CompareErrands.o Time.o Person.o RunErrands.o -o main

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

RunErrands.o: RunErrands.cpp
	g++ -c RunErrands.cpp

clean: 
	rm main Graph Time place Errand Cards person ErrandsList *.o 