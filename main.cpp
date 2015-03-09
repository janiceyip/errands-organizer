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
	int max_time = 100;
	int time_spent = 0;

	//create the priority queue 
	priority_queue<errand_node, vector<errand_node>, CompareErrands> pq;
	Graph g = Graph(); 
	Time t = Time();

	//add errands to the queue 
    errand_node groceries = {_errands_pl_coop, 3, 20}; 
    // errand_node po = {_errands_pl_post_office, 4, 30}; 
    errand_node eat = {_errands_pl_boloco, 17, 50};
    errand_node	shop = {_errands_pl_walmart, 2, 10}; 
    errand_node read = {_errands_pl_baker, 1, 30};

    // pq.push(groceries); 
    // pq.push(po); 
    pq.push(eat); 
    pq.push(shop); 
    pq.push(read);
    
    while (! pq.empty() && (time_spent < max_time)) {
        errand_node errand = pq.top();
        // cout << setw(3) << errand.errandPlace << " " << setw(3) << errand.priority << endl;

       	g.add_vertex(t, t.toString(errand.errandPlace), errand.time_to_complete);

        pq.pop();
    }



	//from priority queue, create the graph 



	// cout << "here" << endl;


	// Graph g = Graph(); 
	// Time t = Time();

	// g.add_vertex(t, "Post Office"); 

	// g.add_vertex(t, "Baker");

	// g.add_vertex(t, "Coop");  

	// g.add_vertex(t, "Walmart");  

	// g.add_vertex(t, "Boloco"); 


	// g.getOrder(); 

	// g.remove_vertex("UPS"); 
	// cout << "remove 2" << endl;
	// g.remove_vertex("Marshalls"); 
	// g.remove_vertex("CVS"); 

	cout << "\nPRINT GRAPH NOW" << endl;
	g.printGraph(); 

	g.getOrder(max_time, t);
}