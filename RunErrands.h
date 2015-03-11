/*
 * RunErrands.h
 *
 *  Created on: Mar 9, 2015
 *      Authors: James Chin, Janice Yip
 */

#ifndef RUNERRANDS_H_
#define RUNERRANDS_H_

#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <stdarg.h>
#include <cfloat>
#include <map>
#include <set>

#include "errands_org_globals.h"
#include "Time.h"
#include "CompareErrands.h"

using namespace std; 



class RunErrands {
	
public:
	RunErrands(); 
	~RunErrands();
};

int enoughTime(priority_queue<errand_node, vector<errand_node>, CompareErrands>, Time, int); 
void runWithPriority(priority_queue<errand_node, vector<errand_node>, CompareErrands>, Time, int, int); 
// void runPriority(priority_queue<errand_node, vector<errand_node>, CompareErrands>, Time, int); 

#endif /* RUNERRANDS_H_ */
