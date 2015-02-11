/*
 * Errand.cpp
 *
 *  Created on: Feb 10, 2015
 *      Author: James Chin, Janice Yip
 */

#include "Errand.h"
using namespace std;

Errand::Errand() {
	priority_ = -1; 
}

Errand::Errand(int priority) {
	priority_ = priority; 
}

Errand::~Errand() {

}

int main () {
	cout << "Started writing program" << endl; 
}