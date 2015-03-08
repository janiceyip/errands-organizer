//
//  main.cpp
//  
//
//  Created by James Chin on 2/14/15.
//
//

#include <stdio.h>
#include "Cards.h" 
#include "CompareErrands.h"
#include "Errand.h" 
#include "Graph.h"
#include "Person.h"
#include "place.h"
#include "Time.h"

int main () {
	//create the person 
	Person p = Person("Heidi Baker", "Mozambique"); 

	//create the priority queue 
	priority_queue<errand_node, vector<errand_node>, CompareErrands> pq;

	//add errands to the queue 
    // errand_node e1 = {_errands_org_groceries, 3}; 
    // errand_node e2 = {_errands_org_post_office, 1}; 
    // errand_node e3 = {_errands_org_shopping, 2};

    // pq.push(e1); 
    // pq.push(e2); 
    // pq.push(e3); 
    
    // while (! pq.empty()) {
    //    errand_node t2 = pq.top();
    //    cout << setw(3) << t2.errandType << " " << setw(3) << t2.priority << endl;
    //    pq.pop();
    // }



	//from priority queue, create the graph 






	Graph g = Graph(); 
	Time t = Time();
	t.printTime(); 

	g.add_vertex(t, "Post Office"); 

	g.add_vertex(t, "Baker");

	g.add_vertex(t, "Coop");  

	g.add_vertex(t, "Walmart");  

	g.add_vertex(t, "Boloco"); 

	placeNames one = t.setPlace("Post Office"); 
	placeNames two = t.setPlace("Baker"); 
	cout << one << ": " << two << endl;

	int asdf = t.getTime(one, two); 
	cout << "time: " << asdf << endl; 

	// g.getOrder(); 

	// g.remove_vertex("UPS"); 
	// cout << "remove 2" << endl;
	// g.remove_vertex("Marshalls"); 
	// g.remove_vertex("CVS"); 

	cout << "\nPRINT GRAPH NOW" << endl;
	g.printGraph(); 
	// cout << g << endl; 
	cout << "Started writing Graph program" << endl; 
}