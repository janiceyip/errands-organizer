/*
 * RunErrands.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: James Chin, Janice Yip
 */


#include "RunErrands.h"

RunErrands::RunErrands() {}
RunErrands::~RunErrands() {}

int enoughTime(priority_queue<errand_node, vector<errand_node>, CompareErrands> pq1, Time t, int max_time) {
	int time_spent = 0;
	int priority, errand_time; 
	int errands_can_run = 0; 
	string locations[2]; 
	errand_node errand1 = {"", 0, INT_MAX}; 
	errand_node errand2, closest_errand; 
	priority_queue<errand_node, vector<errand_node>, CompareErrands> pq2; 
	bool run_all; 

	//try to run all the errands
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

        //if it's too much time, get out 
        if (time_spent > max_time) break; 
        //otherwise, set highest priority 
	    errands_can_run = errand2._priority;         	

		errand1 = closest_errand; 
        
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

    return errands_can_run; 
} 


void runWithPriority(priority_queue<errand_node, vector<errand_node>, CompareErrands> pq1, Time t, int max_time, int can_run) {
	int time_spent = 0;
	int priority, errand_time; 
	int run = 0; 
	string locations[2]; 
	errand_node errand1 = {"", 0, INT_MAX}; 
	errand_node errand2, closest_errand; 
	priority_queue<errand_node, vector<errand_node>, CompareErrands> pq2; 
	int size = pq1.size(); 

	while (! pq1.empty() && (time_spent < max_time) && (run < can_run)) {
		// cout << "run: " << run << " " << can_run << endl;
    	int time_to = INT_MAX; 
    	string closest; 

        //grab the first errand 
        if (errand1._time_to_complete == INT_MAX) {
        	errand1 = pq1.top();
        	pq1.pop();
        }

        // cout << "1: " << errand1._location << endl; 
        priority = errand1._priority; 

        if (!pq1.empty()) {
        	while (!pq1.empty()) {
	        	errand2 = pq1.top(); 
        		// cout << "2: " << errand2._location << endl; 

	        	pq1.pop(); 
	        	pq2.push(errand2); 

	        	locations[0] = errand1._location; 
	        	locations[1] = errand2._location; 
	        	int time_between = t[locations]; 

	        	// cout << "location: " << errand2._location << " : " << errand2._priority << endl; 

	        	//get distance between 
	        	if ((time_between < time_to) && (errand2._priority <= can_run)) {
	        		// cout << "IN" << endl;
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

        if (time_spent < 0) 
        	break;
        // cout << "spent: " << time_spent << endl;
        if (time_spent < max_time) {
	        cout << "Go from " << errand1._location << " to " << closest << endl; 
	        cout << "  " << time_to << " to get there + " << errand_time << " to do the errand = " << time_spent << endl;         	
        } 
        run++; 


		errand1 = closest_errand; 

        //move the pq2 list back to the pq1 list 
        while (!pq2.empty()) {
        	//if it's not the next errand, push it 
        	if (closest.compare(pq2.top()._location)) {
        		// cout << "found" << endl; 
        		pq1.push(pq2.top()); 
        		pq2.pop(); 
        	} else {
        		pq2.pop(); 
        	}
        }

    }


    //if you have time left, and you have completed all your errands 
    if ((time_spent < max_time) && (run == size-1)) {
    	locations[0] = errand1._location; 
    	locations[1] = "Home"; 
    	int time_between = t[locations]; 

    	time_spent += time_between; 
    	if (time_spent < max_time) {
    		cout << "You can even go home, which will take you " << time_between << ", for a total of " << time_spent << endl;
    	}
    } else {
        cout << "Sorry you can't complete all your errands!" << endl;
    }
}

