/*
 * CompareErrands.h
 *
 *  Created on: Feb 24, 2015
 *      Authors: James Chin, Janice Yip
 */

#ifndef COMPAREERRANDS_H_
#define COMPAREERRANDS_H_

#include <iostream>
#include <stdio.h>
#include <stdarg.h>
#include <queue>
#include <iomanip>
#include "errands_org_globals.h"

using namespace std; 

struct errand_node {
	string _location; 
	int _priority; 
	int _time_to_complete;
};

class CompareErrands {
public:
	// ErrandsList(); 
	// ~ErrandsList();
	bool operator()(errand_node& e1, errand_node& e2); 
	errand_node getNext(); 
};

#endif /* COMPAREERRANDS_H_ */
