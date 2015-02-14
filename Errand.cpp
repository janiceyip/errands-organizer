/*
 * Errand.cpp
 *
 *  Created on: Feb 10, 2015
 *      Author: James Chin, Janice Yip
 */

#include "Errand.h"

Errand::Errand() {
	priority_ = -1; 
	hours_ = 0; 
	minutes_ = 0; 
}

Errand::Errand(int priority, int type) {
	priority_ = priority; 
	type_ = type; 
}

Errand::~Errand() {

}

int main () {
	cout << "Started writing program" << endl; 
}