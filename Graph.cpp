/*
 * Graph.cpp
 *
 *  Created on: Feb 24, 2015
 *      Author: James Chin, Janice Yip
 */

#include "Graph.h"
#include "Time.h"
#include "Time.cpp"

Graph::Graph() {

}


Graph::~Graph() {

}

void Graph::add_vertex(Time t, string location, int visited, int time_to){
	pair< set<place_vertex>::iterator,bool> ret;
	set<place_vertex> s; 
	placeNames location_name_1 = t.setPlace(location); 
	int time_between; 
		

	//iterate over graph, adding the vertex to each of the adjacency lists 
	for(auto iter = graph_container.begin(); iter != graph_container.end(); iter++) {
		
		//look up the time/distance between the places 
		placeNames location_name_2 = t.setPlace(iter->first._location); 
		time_between = t.getTime(location_name_1, location_name_2); 

		cout << "time between " << location << " and " << iter->first._location << " is " << time_between << endl;

		place_vertex v = new_vertex(location, visited, time_between); 

		ret = iter->second.insert(v); 
		// if (ret.second == false) 
		// 	cout << "false" << endl;
		// else 
		// 	cout << "true: " << v._location << endl; 

		//insert the key vertices into a set 
		s.insert(iter->first); 
	}
	
	//home to new place

	placeNames location_name_2 = t.setPlace("Home"); 
	time_between = t.getTime(location_name_1, location_name_2); 

	place_vertex v = new_vertex(location, visited, time_between); 
	
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



place_vertex Graph::new_vertex(string location, int visited, int time_to) {
	place_vertex v = place_vertex(); 
	v._location = location; 
	v._visited = visited; 
	v._time_to = time_to; 
	return v; 
}

void Graph::printGraph() {

	// typedef map<place_vertex, set<place_vertex>, vertexComp>::const_iterator MapIterator;
	for (map<place_vertex, set<place_vertex> >::const_iterator iter = graph_container.begin(); 
		iter != graph_container.end(); iter++) {
	    cout << "Key: " << iter->first._location << endl << "Values:" << endl;

	    typedef set<place_vertex>::const_iterator ListIterator;
	    for (ListIterator list_iter = iter->second.begin(); list_iter != iter->second.end(); list_iter++)
	        cout << " " << list_iter->_location << "timeto: " << list_iter->_time_to << endl;
	}
}


void Graph::getOrder() {
	float time_to = FLT_MAX; 
	string closest; 
	int num_locations = 0; 
	int size = graph_container.size(); 
	int total_time = 0; 

	while (num_locations < size) { 
		//iterate to find the closest 
		for (map<place_vertex, set<place_vertex> >::const_iterator iter = graph_container.begin(); 
			iter != graph_container.end(); iter++) {

			//if the time to that vertex is less than current stored value, update
			if (iter->first._time_to < time_to) {
				time_to = iter->first._time_to; 
				closest = iter->first._location; 
			}

		}

		//remove that vertex 
		remove_vertex(closest); 
		total_time += time_to; 
		cout << "closest: " << closest << " time_to: " << time_to << endl;		


		//reset for next vertex
		time_to = FLT_MAX; 
		num_locations++; 
	}

	cout << "Total time to complete these tasks: " << total_time << endl;
}

int main () {
	Graph g = Graph(); 
	Time t = Time();

	cout << "add vertex1" << endl;
	g.add_vertex(t, "Post Office", 0, 1); 
	cout << "add vertex2" << endl;
	g.add_vertex(t, "Baker", 0, 2);
	cout << "add vertex3" << endl;
	g.add_vertex(t, "Coop", 0, 3);  

	g.add_vertex(t, "Walmart", 0, 4);  
	g.getOrder(); 

	// g.remove_vertex("UPS"); 
	// cout << "remove 2" << endl;
	// g.remove_vertex("Marshalls"); 
	// g.remove_vertex("CVS"); 

	cout << "\nPRINT GRAPH NOW" << endl;
	g.printGraph(); 
	// cout << g << endl; 
	cout << "Started writing Graph program" << endl; 
}