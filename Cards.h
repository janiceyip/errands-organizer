/*
 * Cards.h
 *
 *  Created on: Feb 10, 2015
 *      Authors: James Chin, Janice Yip
 */

#ifndef CARDS_H_
#define CARDS_H_

#include <iostream>
#include <stdio.h>
#include <stdarg.h>
#include "errands_org_globals.h" 


struct card_node {
	string place;
	struct card_node* next;
	struct card_node* prev;
};

class Cards {
	card_node * start; 

public:
	Cards(); 
	~Cards();
	void add(string);
	void remove(string); 
	void printCards(); 
};

#endif /* CARDS_H_ */
