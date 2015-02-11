/*
 * Errnad.h
 *
 *  Created on: Feb 10, 2015
 *      Authors: James Chin, Janice Yip
 */

#ifndef ERRAND_H_
#define ERRAND_H_

#include <iostream>
#include <stdio.h>
#include <stdarg.h>

class Errand {
	int priority_; 

public:
	Errand(); 
	Errand(int priority);
	~Errand(); 
};

#endif /* ERRAND_H_ */
