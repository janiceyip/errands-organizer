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
	int max_time = 160;

	//create the priority queue 
	priority_queue<errand_node, vector<errand_node>, CompareErrands> pq1;

	Time t = Time();

	//add errands to the queue 
	errand_node home = {"Home", 1, 0}; 
    errand_node groceries = {"Coop", 8, 20}; 
    errand_node eat = {"Boloco", 3, 50};
    errand_node	shop = {"Walmart", 20, 10}; 
    errand_node read = {"Baker", 50, 30};
    errand_node po = {"Post Office", 2, 30}; 

    pq1.push(home); 
    pq1.push(groceries); 
    pq1.push(eat); 
    pq1.push(shop); 
    pq1.push(read);
    pq1.push(po); 

    cout << "Your max time: " << max_time << endl; 
    int num_can_run = enoughTime(pq1, t, max_time); 

    // if (num_can_run < pq1.size()-1) 
    // 	cout << "Sorry, you don't have time to run all your errands, but here is what you can do:" << endl; 
    // cout << "Can run: " << num_can_run << endl; 
    
    runWithPriority(pq1, t, max_time, num_can_run);
    
}