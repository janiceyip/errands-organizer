/*
 * Cards.cpp
 *
 *  Created on: Feb 11, 2015
 *      Author: James Chin, Janice Yip
 */

#include "Cards.h"

Cards::Cards() {
	// TODO Auto-generated constructor stub
	start = NULL;
	end = start;
}

Cards::~Cards() {
	// TODO Auto-generated destructor stub
	delete start->next;
	delete start->prev;
}

void Cards::add(string x) {
	card_node *n = new card_node;
	// n->num = x;
	// n->next = NULL;
	// if (start == NULL) { //if the list is empty
	// 	n->prev = NULL;
	// 	start = n; //add the item to the list after start
	// } else { //otherwise, traverse list till end
	// 	Node *temp = start;
	// 	while (temp->next != NULL) {
	// 		temp = temp->next;
	// 	}
	// 	n->prev = temp;
	// 	temp->next = n;
	// }
	// end = n;
}

// float Postfix_DLL::pop() {
// 	float x;
// 	if (start == NULL) {
// 		cerr << "Your stack was not big enough for that operation. Program ended." << endl;
// 		exit(-1);
// 	} else {
// 		x = end->num;
// 		end = end->prev;
// 		if (end != NULL) {
// 			free(end->next);
// 			end->next = NULL;
// 		} else {
// 			start = end;
// 		}
// 	}
// 	return x;
// }

void Cards::printCards() {
	card_node * curr = start;
	while (curr->next != NULL) {
		cout << curr->place << " <-> ";
		curr = curr->next;
	}
	cout << curr->place << endl;
}

int main() {}