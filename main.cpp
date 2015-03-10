/*
 * main.cpp
 *
 *  Created on: Feb 24, 2015
 *      Author: James Chin, Janice Yip
 */

#include <stdio.h>
#include <climits>
#include "Cards.h" 
#include "CompareErrands.h"
#include "Errand.h" 
#include "Graph.h"
#include "Person.h"
#include "place.h"
#include "Time.h"
#include "RunErrands.h"

int main () {
	//create the person 
	Person p = Person("Heidi Baker", "Mozambique"); 
	int max_time = 130;

	//create the priority queue 
	priority_queue<errand_node, vector<errand_node>, CompareErrands> pq1;

	Time t = Time();

	//add errands to the queue 
	errand_node home = {"Home", 1, 0}; 
    errand_node groceries = {"Coop", 2, 20}; 
    errand_node eat = {"Boloco", 3, 50};
    errand_node	shop = {"Walmart", 4, 10}; 
    errand_node read = {"Baker", 5, 30};
    errand_node po = {"Post Office", 6, 30}; 

    pq1.push(home); 
    pq1.push(groceries); 
    pq1.push(eat); 
    pq1.push(shop); 
    pq1.push(read);
    pq1.push(po); 

    cout << "Your max time: " << max_time << endl; 
    bool enough = enoughTime(pq1, t, max_time); 

    if (enough) {
    	runAll(pq1, t, max_time);
    } else {
    	runPriority(pq1, t, max_time); 
    }

	

    // while (! pq.empty() && (time_spent < max_time)) {
    //     errand_node errand = pq.top();
    //     cout << setw(3) << errand.errandPlace << " " << setw(3) << errand.priority << endl;

    //    	g.add_vertex(t, t.toString(errand.errandPlace), errand.time_to_complete);

    //     pq.pop();
    // }

	//from priority queue, create the graph 

	
	// g.add_vertex(t, "Walmart", 10);  

	// g.add_vertex(t, "Post Office", 30); 

	// g.add_vertex(t, "Baker", 30);

	// g.add_vertex(t, "Coop", 20);  

	// g.add_vertex(t, "Boloco", 50); 


	// g.getOrder(); 

	// g.remove_vertex("UPS"); 
	// cout << "remove 2" << endl;
	// g.remove_vertex("Marshalls"); 
	// g.remove_vertex("CVS"); 

	// cout << "\nPRINT GRAPH NOW" << endl;
	// g.printGraph(); 

	// g.getOrder(max_time, t);
}