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
