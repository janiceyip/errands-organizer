/*
 * Person.cpp
 *
 *  Created on: Feb 10, 2015
 *      Author: James Chin, Janice Yip
 */

#include "Person.h"

Person::Person(string name, string address) {
	name_ = name; 
	address_ = address; 
	loyalty_cards = NULL; 
	credit_cards = NULL; 
}


Person::~Person() {

}
