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

#define GROCERIES 1
#define SHOPPING 2
#define RESTAURANT_EATING 3
#define LAUNDRY 4
#define DRY_CLEANING 5
#define LIBRARY 6
#define POST_OFFICE 7

using namespace std; 

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
