/*
 * Graph.cpp
 *
 *  Created on: Feb 24, 2015
 *      Author: James Chin, Janice Yip
 */

#include "Graph.h"
#include "Time.h"
// #include "Time.cpp"

Graph::Graph() {

}


Graph::~Graph() {

}

void Graph::add_vertex(Time t, string location, int time_to_complete_errand){
	pair< set<place_vertex>::iterator,bool> ret;
	set<place_vertex> s; 
	placeNames location_name_2 = t.setPlace(location); 
	int time_between; 

	//iterate over graph, adding the vertex to each of the adjacency lists 
	for(auto iter = graph_container.begin(); iter != graph_container.end(); iter++) {
	
		//look up the time/distance between the places 
		placeNames location_name_1 = t.setPlace(iter->first._location); 

		time_between = t.getTime(location_name_1, location_name_2); 
		// cout << "time between " << iter->first._location << " and " << location << " is " << time_between << endl;

		//create a new vertex and put it into the adjacency list 
		place_vertex v = new_vertex(location, time_between, time_to_complete_errand); 
		ret = iter->second.insert(v); 

		//insert the key vertices into a set 
		place_vertex v_new = new_vertex(iter->first._location, time_between, iter->first._time_to_complete_errand); 
		s.insert(v_new); 
	}
	
	//home to new place
	placeNames location_name_1 = t.setPlace("Home"); 
	int time_from_home = t.getTime(location_name_1, location_name_2); 

	place_vertex v = new_vertex(location, time_from_home, time_to_complete_errand); 
	
	pair<map <place_vertex, set<place_vertex> >::iterator,bool> ret2; 
	ret2 = graph_container.insert(pair <place_vertex, set<place_vertex> >(v, s)); 

	// if (ret2.second == false) 
	// 	cout << "waoewija;divja;oiefjaeijf" << endl; 

	// for(auto iter = graph_container.begin(); iter != graph_container.end(); iter++) {
	// 	cout << "second time: " << iter->first._location << endl; 
	// }

}


void Graph::remove_vertex(string location) {
	//go through the graph 
	for(auto iter = graph_container.begin(); iter != graph_container.end(); ) {
		//remove the vertex from the sets
		typedef set<place_vertex>::const_iterator ListIterator;
	    for (ListIterator list_iter = iter->second.begin(); list_iter != iter->second.end(); ){
	    	//if the strings match, remove that vertex
	    	if (!location.compare(list_iter->_location)) 
	    		list_iter = iter->second.erase(list_iter); 
	    	else
	    		list_iter++; 
	    }

	    //remove the vertex from the map's keys 
	    if (!location.compare(iter->first._location))
		    iter = graph_container.erase(iter); 
		else 
			iter++; 
	}
}



place_vertex Graph::new_vertex(string location, int time_to, int time_to_complete_errand) {
	place_vertex v = place_vertex(); 
	v._location = location; 
	v._time_to = time_to; 
	v._time_to_complete_errand = time_to_complete_errand; 
	return v; 
}

void Graph::printGraph() {

	// typedef map<place_vertex, set<place_vertex>, vertexComp>::const_iterator MapIterator;
	for (map<place_vertex, set<place_vertex> >::const_iterator iter = graph_container.begin(); 
		iter != graph_container.end(); iter++) {
		cout << endl;
	    cout << "Key: " << iter->first._location << endl << "Values:" << endl;

	    typedef set<place_vertex>::const_iterator ListIterator;
	    for (ListIterator list_iter = iter->second.begin(); list_iter != iter->second.end(); list_iter++)
	        cout << " " << list_iter->_location << " timeto: " << list_iter->_time_to << endl;
	}
}


void Graph::getOrder(int max_time, Time t) {
	float time_to = FLT_MAX; 
	string closest_loc_from_home, closest_loc; 
	int closest_loc_time_complete; 
	int num_locations = 0; 
	int size = graph_container.size(); 
	int total_time = 0; 
	place_vertex closest_vertex; 

	//iterate to find the closest 
	for (map<place_vertex, set<place_vertex> >::const_iterator iter = graph_container.begin(); 
		iter != graph_container.end(); iter++) {

		//if the time to that vertex is less than current stored value, update
		if (iter->first._time_to < time_to) {
			time_to = iter->first._time_to; 
			closest_loc_from_home = iter->first._location; 
			closest_vertex = iter->first; 
		}

	}

	total_time += time_to; //get from home to first 
	total_time += closest_vertex._time_to_complete_errand; //time to complete first errand 

	//from that vertex, find next closest vertex 
	set<place_vertex> s = graph_container[closest_vertex]; 

	//reset time_to 
	time_to = FLT_MAX; 
	num_locations++; 


	while ((num_locations < size) && (total_time < max_time)) { 

		//go through list and find next place to go 
	    for (set<place_vertex>::const_iterator list_iter = s.begin(); list_iter != s.end(); list_iter++){
	    	if (list_iter->_time_to < time_to) {
	    		time_to = list_iter->_time_to; 
	    		closest_loc = list_iter->_location; 
	    		closest_loc_time_complete = list_iter->_time_to_complete_errand; 
	    	}
	    }
	        // cout << " " << list_iter->_location << " timeto: " << list_iter->_time_to << endl;

	    if (num_locations == 1) {
	    	remove_vertex(closest_loc_from_home); 
	    }

	    placeNames location_name_1 = t.setPlace("Home"); 
	    placeNames location_name_2 = t.setPlace(closest_vertex._location); 
		int time_from_home = t.getTime(location_name_1, location_name_2); 

	    place_vertex next_place = new_vertex(closest_loc, time_from_home, closest_loc_time_complete); 

	    s = graph_container[closest_vertex]; 

		//remove that vertex 
		remove_vertex(closest_loc); 
		total_time += time_to; 
		total_time += closest_loc_time_complete; 
		cout << time_to << " " << closest_loc_time_complete << endl; 
		cout << "closest: " << closest_loc << " time to: " << time_to << endl;		


		//reset for next vertex
		time_to = FLT_MAX; 
		num_locations++; 

	}

	cout << "Total time to complete these tasks: " << total_time << endl;
}

// int main() {}