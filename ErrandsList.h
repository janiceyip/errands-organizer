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

using namespace std; 

#define GROCERIES 1
#define SHOPPING 2
#define RESTAURANT_EATING 3
#define LAUNDRY 4
#define DRY_CLEANING 5
#define LIBRARY 6
#define POST_OFFICE 7

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
