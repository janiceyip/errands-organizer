/*
 * ErrandsList.cpp
 *
 *  Created on: Feb 11, 2015
 *      Author: James Chin, Janice Yip
 */

#include "CompareErrands.h"


bool CompareErrands::operator()(errand_node& e1, errand_node& e2)
    {
    	if (e1.priority > e2.priority) return true;
		else return false;
    }

int main() {

    priority_queue<errand_node, vector<errand_node>, CompareErrands> pq;

    errand_node e1 = {_errands_org_groceries, 3}; 
    errand_node e2 = {_errands_org_post_office, 1}; 
    errand_node e3 = {_errands_org_shopping, 2};

    pq.push(e1); 
    pq.push(e2); 
    pq.push(e3); 
    
    while (! pq.empty()) {
       errand_node t2 = pq.top();
       cout << setw(3) << t2.errandType << " " << setw(3) << t2.priority << endl;
       pq.pop();
    }

    return 0;
}

