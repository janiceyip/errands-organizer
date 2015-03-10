//
//  main.cpp
//  
//
//  Created by James Chin on 2/14/15.
//
//

#include <stdio.h>
#include <climits>
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
	int priority, errand_time; 

	//create the priority queue 
	priority_queue<errand_node, vector<errand_node>, CompareErrands> pq1;
	priority_queue<errand_node, vector<errand_node>, CompareErrands> pq2; 
	// Graph g = Graph(); 
	// Time t = Time();

	//add errands to the queue 
	errand_node home = {"Home", 1, 0}; 
    errand_node groceries = {"Coop", 3, 20}; 
    errand_node po = {"Post Office", 4, 30}; 
    errand_node eat = {"Boloco", 10, 50};
    errand_node	shop = {"Walmart", 8, 10}; 
    errand_node read = {"Baker", 6, 30};

    pq1.push(home); 
    pq1.push(groceries); 
    pq1.push(po); 
    pq1.push(eat); 
    pq1.push(shop); 
    pq1.push(read);

    while (! pq1.empty() && (time_spent < max_time)) {
    	int time_to = INT_MAX; 
    	string closest; 

        //grab the first errand 
        errand_node errand1 = pq1.top();
        // cout << setw(3) << errand1.errandPlace << " " << setw(3) << errand1.priority << endl;
        pq1.pop(); 

        if (!pq1.empty()) {
        	while (!pq1.empty()) {
	        	errand_node errand2 = pq1.top(); 
	        	pq1.pop(); 
	        	pq2.push(errand2); 

	        	// int time_between = matrix[errand1._location, errand2._location]; 

	        	int time_between = 5; 

	        	//get distance between 
	        	if (time_between < time_to) {
	        		time_to = time_between; 
	        		closest = errand2._location; 
	        		priority = errand2._priority; 
	        		errand_time = errand2._time_to_complete; 
	        	}

	        }
        } else {
        	time_to = time_spent; 
        	errand_time = 0; 
        }

        time_spent += time_to; 
        time_spent += errand_time; 
        cout << "priority: " << priority << endl; 
        cout << "Time to: " << time_to << " + errand time: " << errand_time << " = " << time_spent << endl; 

        while (!pq2.empty()) {
        	pq1.push(pq2.top()); 
        	pq2.pop(); 
        }

        cout << pq1.size() << endl; 
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