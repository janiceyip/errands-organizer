/*
 * Graph.cpp
 *
 *  Created on: Feb 24, 2015
 *      Author: James Chin, Janice Yip
 */

#include "Graph2.h"
#include "Time.h"
#include "Time.cpp"

Graph2::Graph2() {
	// locations = { "", "", "", "", "", 
	// 			"", "", "", "", "", 
	// 			"", "", "", "", "", 
	// 			"", "", "", "", "" }; 
	start = NULL; 
}


Graph2::~Graph2() {}

// void Graph2::add_vertex(Time t, string location, int time_to_complete_errand) {
// 	placeNames loc1, loc2; 
// 	place_vertex * start; 
// 	place_vertex * curr; 

// 	start = curr = NULL; 

// 	//for every list in the array, add an edge to that vertex 
// 	for (int i = 0; i < 20; i++) {

// 		//if nothing in that locations array 
// 		if (!locations[i].compare("")) {

// 			//create a vertex for the location, then add to the array  
// 			locations[i] = location; 

// 			loc1 = t.setPlace("Home"); 
// 			loc2 = t.setPlace(location); 
// 			int time_from_home = t.getTime(loc1, loc2); 

// 			vertices[i] = new_vertex(location, time_from_home, time_to_complete_errand); 

// 			//add the list of vertices here 
// 			vertices[i]->next = start; 
// 			return ;
// 		} 

// 		//otherwise, add the vertex to each of the other lists 
// 		loc1 = t.setPlace(locations[i]); 
// 		loc2 = t.setPlace(location); 
// 		int time_to = t.getTime(loc1, loc2); 

// 		//create the vertex
// 		place_vertex *v = new_vertex(location, time_to, time_to_complete_errand); 

// 		//push vertex to end of list  
// 		place_vertex * temp = vertices[i]; 

// 		while (temp->next != NULL) {
// 			temp = temp->next; 
// 			// cout << "i: " << i <<  "temp: " << temp->_location << endl; 
// 		}

// 		v->prev = temp; 
// 		temp->next = v; 


// 		cout << "new" << endl; 
// 		//also grab ptr to the first vertex to append to list later 
// 		curr = new_vertex(locations[i], time_to, vertices[i]->_time_to_complete_errand); 
		
// 		if (start == NULL) {
// 			start = curr; 
// 			cout << start << " " << curr << endl; 
// 		} if (i == 1) {
// 			// start->next = curr; 
// 		}
// 		// cout << "\n" << i << " : " << start->_location << "\n"; 
		

// 		place_vertex * before = start; 

// 		while (before->next != NULL) {
// 			cout << "next" << endl;
// 			before = before->next; 
// 		}
// 		curr->prev = before; 

// 		curr = curr->next; 

// 		cout << curr << endl;
// 	}

// 	//also have to add to the newest vertex 

// }


void Graph2::add_vertex(Time t, string location, int time_to_complete_errand) {
	placeNames loc1, loc2; 

	// if (start == NULL) {
	// 	start = new_vertex2("Home", 0); 
	// 	new_vertex2(location, time_to_complete_errand); 
	// } 

	place_vertex * curr = start; 

	if (curr == NULL) {
		curr = new_vertex2(location, time_to_complete_errand); 
		start = curr; 
	} else {
		while (curr->next != NULL) {
			curr = curr->next; 
		} 

		//add the vertex 
		curr->next = new_vertex2(location, time_to_complete_errand); 
		curr->next->prev = curr; 
	}
	

	//for every list in the array, add an edge to that vertex 
	for (int i = 0; i < 20; i++) {

		//if nothing in that locations array 
		if (!locations[i].compare("")) {

			locations[i] = location; //add location
			vertices[i] = start; //add the list of vertices 

			return;
		} 
	}
}


void Graph2::printGraph() {
	place_vertex* temp; 
	//for every list in the array, add an edge to that vertex 
	for (int i = 0; i < 20; i++) {

		//if string in that locations array 
		if (locations[i].compare("")) {
			cout << "Key: " << locations[i] << endl; 

			temp = vertices[i]; 
			
			cout << "Values: " << endl; 
			while (temp->next != NULL) {
				cout << "  " << temp->_location << endl; 
				temp = temp->next; 
			}

			cout << "  " << temp->_location << endl; 
		}
	}

	place_vertex * curr = start; 
	if (curr == NULL) 
		return; 

	cout << "Locations:"; 
	while (curr->next != NULL) {
		cout << " " << curr->_location; 
		curr = curr->next; 
	}

	cout << " " << curr->_location << endl; 

	return; 
}

void Graph2::remove_vertex(string location) {
	place_vertex * curr; 

	curr = start; 
	if (curr == NULL) 
		return; 

	while (curr->next != NULL) {
		// cout << "in remove: " << curr->_location << endl; 
		if (!curr->_location.compare(location)) {
			cout << "break " << curr->_location << endl; 
			break;			
		}

		curr = curr->next; 
	} 

	cout << "remove " << curr->_location << endl; 
	if (!curr->_location.compare(location)) {
		cout << "loc" << endl; 

		if (curr == start) {

			if (curr->next != NULL) 
				curr->next->prev = NULL; 
			start = curr->next; 
			// cout << "start " << start->_location << endl; 
		} else {
			curr->prev->next = curr->next; 
			if (curr->next != NULL) 
				curr->next->prev = curr->prev; 
			free(curr); 
		}
	}

	for (int i = 0; i < 20; i++) {
		if (!locations[i].compare(location)) {
			// cout << "entered" << endl;
			locations[i] = ""; 
			vertices[i] = NULL; 
		} 
		// else if (!locations[i].compare("")) {
		// 	vertices[i] = start; 
		// }
	}
}

// void Graph2::printGraph() {
// 	place_vertex* temp; 
// 	//for every list in the array, add an edge to that vertex 
// 	for (int i = 0; i < 20; i++) {

// 		//if nothing in that locations array 
// 		if (locations[i].compare("")) {
// 			cout << "Key: " << locations[i] << endl; 

// 			temp = vertices[i]; 
			
// 			cout << "Values: " << endl; 
// 			while (temp->next != NULL) {
// 				temp = temp->next; 
// 				cout << "  " << temp->_location << " time to: " << temp->_time_to << endl; 
// 			}

// 			// cout << "  " << temp->_location << " time to: " << temp->_time_to << endl; 
// 		}
// 	}

// 	return; 
// }


place_vertex* Graph2::new_vertex(string location, int time_to, int time_to_complete_errand) {
	place_vertex* v = new place_vertex; 
	v->_location = location; 
	v->_time_to = time_to; 
	v->_time_to_complete_errand = time_to_complete_errand; 
	v->next = NULL; 
	v->prev = NULL; 
	return v; 
}

place_vertex* Graph2::new_vertex2(string location, int time_to_complete_errand) {
	place_vertex* v = new place_vertex; 
	v->_location = location; 
	v->_time_to_complete_errand = time_to_complete_errand; 
	v->next = NULL; 
	v->prev = NULL; 
	return v; 
}

int main() {
	Graph2 g = Graph2(); 
	Time t = Time(); 

	g.add_vertex(t, "Home", 0); 
	cout << "1" << endl;

	g.add_vertex(t, "Coop", 30); 
	cout << "2" << endl;

	g.add_vertex(t, "Baker", 20); 
	cout << "3" << endl; 

	g.add_vertex(t, "Boloco", 50); 
	cout << "4" << endl; 

	g.add_vertex(t, "Walmart", 40);
	cout << "5" << endl; 

	g.remove_vertex("Home"); 
	// g.remove_vertex("Coop"); 
	// g.remove_vertex("Baker"); 
	// g.remove_vertex("Boloco"); 
	// g.remove_vertex("Walmart"); 

	// g.remove_vertex("Walmart"); 
	// g.remove_vertex("Boloco"); 
	// g.remove_vertex("Baker"); 
	// g.remove_vertex("Coop"); 
	// g.remove_vertex("Home"); 


	// g.add_vertex(t, "Post Office", 40);
	// cout << "5" << endl; 

	// cout << "0: " << g.vertices[0]->_location << endl;;
	// cout << "1: " << g.vertices[1]->_location << endl;;
	// cout << "2: " << g.vertices[2]->_location << endl;;
	// cout << "3: " << g.vertices[3]->_location << endl;;

	g.printGraph(); 

}