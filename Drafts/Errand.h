/*
 * Errand.h
 *
 *  Created on: Feb 10, 2015
 *      Authors: James Chin, Janice Yip
 */

#ifndef ERRAND_H_
#define ERRAND_H_

#include <iostream>
#include <stdio.h>
#include <stdarg.h>

#define GROCERIES 1
#define SHOPPING 2
#define RESTAURANT_EATING 3
#define LAUNDRY 4
#define DRY_CLEANING 5
#define LIBRARY 6
#define POST_OFFICE 7

using namespace std; 

class Errand {
	int priority_; 
	int hours_;
	int minutes_;  
	int type_; 

public:
	Errand(); 
	Errand(int priority, int type);
	~Errand(); 
};

#endif /* ERRAND_H_ */
