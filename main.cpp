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

int main () {
	//create the person 
	Person p = Person("Heidi Baker", "Mozambique"); 
	int max_time = 230;
	int time_spent = 0;
	int priority, errand_time; 
	string locations[2]; 
	errand_node errand1 = {"", 0, INT_MAX};  
	errand_node errand2, closest_errand; 

	//create the priority queue 
	priority_queue<errand_node, vector<errand_node>, CompareErrands> pq1;
	priority_queue<errand_node, vector<errand_node>, CompareErrands> pq2; 
	// Graph g = Graph(); 
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

    while (! pq1.empty() && (time_spent < max_time)) {
    	int time_to = INT_MAX; 
    	string closest; 

        //grab the first errand 
        if (errand1._time_to_complete == INT_MAX) {
        	errand1 = pq1.top();
        	pq1.pop();
        }
	        
        // cout << "1: " << errand1._location << endl; 
        priority = errand1._priority; 
        // cout << setw(3) << errand1.errandPlace << " " << setw(3) << errand1.priority << endl;
         

        if (!pq1.empty()) {
        	while (!pq1.empty()) {
	        	errand2 = pq1.top(); 
        		// cout << "2: " << errand2._location << endl; 

	        	pq1.pop(); 
	        	pq2.push(errand2); 

	        	locations[0] = errand1._location; 
	        	locations[1] = errand2._location; 
	        	int time_between = t[locations]; 

	        	//get distance between 
	        	if (time_between < time_to) {
	        		time_to = time_between; 
	        		closest = errand2._location; 
	        		// priority = errand2._priority; 
	        		errand_time = errand2._time_to_complete; 
	        		closest_errand = errand2; 
	        	}

	        }
        } else {
        	time_to = time_spent; 
        	errand_time = 0; 
        }

        time_spent += time_to; 
        time_spent += errand_time; 

        if (time_spent < max_time) {
	        // cout << "priority: " << priority << endl; 
	        cout << "Go from " << errand1._location << " to " << closest << endl; 
	        cout << "  " << time_to << " to get there + " << errand_time << " to do the errand = " << time_spent << endl;         	
        } else {
        	// cout << "Sorry, you don't have time to do any more tasks" << endl; 
        }


		errand1 = closest_errand; 
        // cout << "out: " << errand1._location << endl;

        
        while (!pq2.empty()) {

        	if (closest.compare(pq2.top()._location)) {
        		// cout << "found" << endl; 
        		pq1.push(pq2.top()); 
        		pq2.pop(); 
        	} else {
        		pq2.pop(); 
        	}
        }

    }

    if (time_spent < max_time) {
    	locations[0] = errand1._location; 
    	locations[1] = "Home"; 
    	int time_between = t[locations]; 

    	time_spent += time_between; 
    	if (time_spent < max_time) {
    		cout << "You can even go home, which will take you " << time_between << ", for a total of " << time_spent << endl;
    	}
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