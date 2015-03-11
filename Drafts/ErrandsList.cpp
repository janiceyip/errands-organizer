/*
 * ErrandsList.cpp
 *
 *  Created on: Feb 11, 2015
 *      Author: James Chin, Janice Yip
 */

#include "ErrandsList.h"

ErrandsList::ErrandsList() {
	start = NULL;
}

ErrandsList::~ErrandsList() {
	delete start->next;
	delete start->prev;
}

void ErrandsList::add(string x) {

}

void ErrandsList::remove(string x) {
	
}

void ErrandsList::printErrands() {

}

int main() {
	// Cards c = Cards(); 
	// cout << "made cards" << endl; 
	// // c.add("CVS"); 
	// c.printCards(); 	

	// cout << "after CVS" << endl; 
	// c.add("Visa"); 
	// c.printCards(); 
	// c.add("Mastercard"); 
	// c.printCards(); 
	// cout << "after mastercard" << endl;
	// c.add("Visa"); 
	// c.printCards(); 
	// c.remove("Visa"); 

	// c.add("Mastercard"); 
	// c.printCards();
	// c.add("Visa"); 
	// c.printCards();
	// c.add("Mastercard"); 
	// c.printCards();
	// c.remove("Visa"); 
	// c.printCards(); 
	// c.remove("Visa"); 
	// c.printCards(); 
	// c.remove("CVS"); 
	// c.add("CVS"); 
	// c.printCards(); 
	// c.remove("Mastercard"); 
	// c.printCards();

}