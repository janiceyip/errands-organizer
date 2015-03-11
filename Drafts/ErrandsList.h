/*
 * ErrandsList.h
 *
 *  Created on: Feb 10, 2015
 *      Authors: James Chin, Janice Yip
 */

#ifndef ERRANDSLIST_H_
#define ERRANDSLIST_H_

#include <iostream>
#include <stdio.h>
#include <stdarg.h>
#include "errands_org_globals.h"

using namespace std; 


struct errand_node {
	string errandName;
	struct errand_node* next;
	struct errand_node* prev;
};

class ErrandsList {
	errand_node * start; 

public:
	ErrandsList(); 
	~ErrandsList();
	void add(string);
	void remove(string); 
	void printErrands(); 
};

#endif /* ERRANDSLIST_H_ */
