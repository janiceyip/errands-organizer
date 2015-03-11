/*
 * Cards.cpp
 *
 *  Created on: Feb 11, 2015
 *      Author: James Chin, Janice Yip
 */

#include "Cards.h"

Cards::Cards() {
	start = NULL;
}

Cards::~Cards() {
	delete start->next;
	delete start->prev;
}

void Cards::add(string x) {

	if (start == NULL) { //if the list is empty
		card_node *n = new card_node; 
		n->place = x;
		n->next = NULL; 
		n->prev = NULL;
		start = n; //add the item to the list after start
		return; 
	}

	// if the list is not empty, traverse list to make sure card doesn't already exist in list 
	card_node *temp = start; 
	while (temp->next != NULL) { 
		
		cout << "x: " << temp->place << endl; 

		//if the new card already exists in the list 
		if (!temp->place.compare(x)) 
			break;

		temp = temp->next;
	}

	if (!temp->place.compare(x)) {
		cout << x << " is already in the list, not added." << endl;
		return; 
	}

	//card is not in the list, so create a node for the card, then add to the list  
	card_node *n = new card_node; 
	n->place = x;
	n->next = NULL; 
	n->prev = temp; 
	temp->next = n; 
	return; 
}

void Cards::remove(string x) {
	
	if (start == NULL) {
		cerr << "You have no cards to remove." << endl;
		exit(-1);
	} else {
		//look for the card in the list 
		card_node *temp = start; 
		while (temp->next != NULL) {

			//if found, return 
			if (!temp->place.compare(x)) 
				break;

			temp = temp->next; 
		}

		if (!temp->place.compare(x)) {
			if (temp == start) {
				temp->next->prev = NULL; 
				start = temp->next; 
				free(temp); 
			} else {
				temp->prev->next = temp->next; 
				if (temp->next != NULL) 
					temp->next->prev = temp->prev; 
				free(temp); 				 	
			}
			cout << x << " removed from the list." << endl;
			return; 
		}

	} 

	cout << "Card not found, nothing removed." << endl; 
	return; 
}

void Cards::printCards() {
	card_node * curr = start;
	if (start == NULL) {
		cout << "There is nothing in the list." << endl; 
		return; 
	}

	while (curr->next != NULL) {
		cout << curr->place << " <-> ";
		curr = curr->next;
	}
	cout << curr->place << endl;
}

int main() {
	Cards c = Cards(); 
	cout << "made cards" << endl; 
	// c.add("CVS"); 
	c.printCards(); 	

	cout << "after CVS" << endl; 
	c.add("Visa"); 
	c.printCards(); 
	c.add("Mastercard"); 
	c.printCards(); 
	cout << "after mastercard" << endl;
	c.add("Visa"); 
	c.printCards(); 
	c.remove("Visa"); 

	c.add("Mastercard"); 
	c.printCards();
	c.add("Visa"); 
	c.printCards();
	c.add("Mastercard"); 
	c.printCards();
	c.remove("Visa"); 
	c.printCards(); 
	c.remove("Visa"); 
	c.printCards(); 
	c.remove("CVS"); 
	c.add("CVS"); 
	c.printCards(); 
	c.remove("Mastercard"); 
	c.printCards();

}