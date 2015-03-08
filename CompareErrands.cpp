/*
 * ErrandsList.cpp
 *
 *  Created on: Feb 11, 2015
 *      Author: James Chin, Janice Yip
 */

#include "CompareErrands.h"


bool CompareErrands::operator()(errand_node& e1, errand_node& e2)
{
	if (e1.priority > e2.priority) return true;
	else return false;
}


