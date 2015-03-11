/*
 * Graph.h
 *
 *  Created on: Feb 24, 2015
 *      Authors: James Chin, Janice Yip
 */

#ifndef GRAPH2_H_
#define GRAPH2_H_

#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <stdarg.h>
#include <cfloat>
#include <map>
#include <set>
#include <string>

#include "errands_org_globals.h"
#include "Time.h"

using namespace std; 

struct graph_container {
	string locations[20]; 
	struct place_vertex * vertices[20]; 
}; 

struct place_vertex {
	string _location;
	float _time_to;
	int _time_to_complete_errand; 
	struct place_vertex * next; 
	struct place_vertex * prev; 
};

class Graph2 {
	

public:
	string locations[20] = { "", "", "", "", "", 
				"", "", "", "", "", 
				"", "", "", "", "", 
				"", "", "", "", "" }; 
	place_vertex * vertices[20]; 
	place_vertex * start; 
	
	Graph2(); 
	~Graph2();
	void add_vertex(Time, string, int);
	void remove_vertex(string); 
	place_vertex* new_vertex(string, int, int); 
	place_vertex* new_vertex2(string , int ); 
	void getOrder(int, Time); 
	void printGraph(); 
	// void remove(string); 
	// void printErrands(); 
};

#endif /* GRAPH2_H_ */