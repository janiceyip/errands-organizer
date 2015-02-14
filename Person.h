/*
 * Person.h
 *
 *  Created on: Feb 10, 2015
 *      Authors: James Chin, Janice Yip
 */

#ifndef PERSON_H_
#define PERSON_H_

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

struct card_node {
	string place;
	struct card_node* next;
	struct card_node* prev;
};

using namespace std; 

class Person {
	string name_; 
	string address_; 
	card_node * loyalty_cards_start; 
	card_node * credit_cards_start; 

public:
	Person(); 
	~Person(); 
};

#endif /* PERSON_H_ */
