/*
 * main.cpp
 *
 *  Created on: Feb 24, 2015
 *      Author: James Chin, Janice Yip
 */

#include <stdio.h>
#include <climits>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include "Cards.h" 
#include "CompareErrands.h"
#include "Errand.h" 
#include "Graph.h"
#include "Person.h"
#include "place.h"
#include "Time.h"
#include "RunErrands.h"

void Tokenize(const string& str,
                      vector<string>& tokens,
                      const string& delimiters = " ")
{
    // Skip delimiters at beginning.
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
    string::size_type pos     = str.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos)
    {   
        // Found a token, add it to the vector.
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
}

// void print( vector <string> & v )
// {
//   for (size_t n = 0; n < v.size(); n++)
//     cout << "\"" << v[ n ] << "\"\n";
//   cout << endl;
// }

int main () {
	//create the person 
	// Person p = Person("Heidi Baker", "Mozambique"); 
	int max_time = 160;
    string input = "";
    string input_errand = ""; 

	//create the time/distance matrix
	Time t = Time();

    do {
        //take user input
        cout << "1 for example, 2 for self-entering, Q to exit: ";
        getline (cin,input);
        priority_queue<errand_node, vector<errand_node>, CompareErrands> pq1;


        //if the input is 1, run the test case. 
        //  else, grab their info 
        if (!input.compare("1")) {
    
            //create errands 
            errand_node home = {"Home", 1, 0}; 
            errand_node groceries = {"Coop", 8, 20}; 
            errand_node eat = {"Boloco", 3, 50};
            errand_node shop = {"Walmart", 20, 10}; 
            errand_node read = {"Baker", 5, 30};
            errand_node po = {"Post Office", 2, 30}; 

            //add errands to the queue
            pq1.push(home); 
            pq1.push(groceries); 
            pq1.push(eat); 
            pq1.push(shop); 
            pq1.push(read);
            pq1.push(po); 

            //run the algorithm 
            cout << "Your max time: " << max_time << endl; 
            int num_can_run = enoughTime(pq1, t, max_time); 

            runWithPriority(pq1, t, max_time, num_can_run);
            cout << "" << endl;

        } else if (!input.compare("2")) {

            string input_time; 
            string again = ""; 

            //take time input 
            cout << "How much time do you have? "; 
            getline(cin, input_time); 
            try {
                max_time = stoi(input_time); 
            } catch (const exception& e) {
                cerr << "Invalid time." << endl;
            }

            //start at home 
            errand_node home = {"Home", 1, 0}; 
            pq1.push(home); 

            do {
                //grab the input, and parse it into a vector 
                cout << "Enter place, priority, and time to complete that errand: " << endl;
                getline (cin,input_errand);
                vector<string> tokens;
                Tokenize(input_errand, tokens, ", ");

                //try to push the input into the priority queue
                try {
                    int pri = stoi(tokens[1]);
                    int errTime = stoi(tokens[2]);
                    errand_node err1 = {tokens[0], pri, errTime}; 
                    pq1.push(err1);
                } catch(const exception& e) {
                    cerr << "Invalid input." << endl;
                }

                //ask for more input 
                cout << "More? Y or N: "; 
                getline (cin, again); 

            } while(!((!again.compare("N"))||(!again.compare("n"))));

            
            //run the algorithm
            cout << "Your max time: " << max_time << endl; 
            int num_can_run = enoughTime(pq1, t, max_time); 

            runWithPriority(pq1, t, max_time, num_can_run);
            cout << "" << endl;
            
        } else {
            try { } catch(const exception& e) {
                cerr << "Invalid input." << endl;
            }
        }

    //repeat until user quits the program 
    } while(!((!input.compare("Q"))||(!input.compare("q"))));
    
}