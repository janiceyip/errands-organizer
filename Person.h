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
#include "Cards.h"

using namespace std; 

#define GROCERIES 1
#define SHOPPING 2
#define RESTAURANT_EATING 3
#define LAUNDRY 4
#define DRY_CLEANING 5
#define LIBRARY 6
#define POST_OFFICE 7


class Person {
	string name_; 
	string address_; 
	Cards * loyalty_cards; 
	Cards * credit_cards; 

public:
	Person(string, string); 
	~Person(); 
};

#endif /* PERSON_H_ */
