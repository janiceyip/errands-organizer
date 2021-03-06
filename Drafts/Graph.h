/*
 * Graph.h
 *
 *  Created on: Feb 24, 2015
 *      Authors: James Chin, Janice Yip
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <stdarg.h>
#include <cfloat>
#include <map>
#include <set>

#include "errands_org_globals.h"
#include "Time.h"

using namespace std; 


struct place_vertex {
	string _location;
	float _time_to;
	int _time_to_complete_errand; 
	bool operator<(const place_vertex &a) const
    	{ return _location.compare(a._location); }
    	// { return _time_to < a._time_to;
    
};

// struct vertexComp {
//   bool operator() (const place_vertex& first, const place_vertex& second) const
//   {return first._time_to < second._time_to;}
// };

class Graph {
	map< place_vertex, set<place_vertex> > graph_container; 

public:
	Graph(); 
	~Graph();
	void add_vertex(Time, string, int);
	void remove_vertex(string); 
	place_vertex new_vertex(string, int, int); 
	void getOrder(int, Time); 
	void printGraph(); 
	// void remove(string); 
	// void printErrands(); 
};

#endif /* GRAPH_H_ */
