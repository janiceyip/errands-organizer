/*
 * Graph.cpp
 *
 *  Created on: Feb 24, 2015
 *      Author: James Chin, Janice Yip
 */

#include "Graph.h"

Graph::Graph() {

}


Graph::~Graph() {

}

void Graph::add_vertex(string location){
	place_vertex v = new_vertex(location); 
	pair< set<place_vertex>::iterator,bool> ret;

	for(auto iter = graph_container.begin(); iter != graph_container.end(); iter++) {
		cout << "hard" << endl; 
		cout << "key: " << iter->first._location << endl;

		ret = iter->second.insert(v); 
		if (ret.second == false) 
			cout << "false" << endl;
		else 
			cout << "true" << endl; 
	}
	cout << "vertex is: " << v._location << endl;
	set<place_vertex> s;

	pair<map <place_vertex, set<place_vertex> >::iterator,bool> ret2; 
	// ::iterator, bool>ret2; 
	ret2 = graph_container.insert(pair <place_vertex, set<place_vertex> >(v, s)); 
	// [v] = s; 
	if (ret2.second == false) 
		cout << "waoewija;divja;oiefjaeijf" << endl; 

}

place_vertex Graph::new_vertex(string location) {
	place_vertex v = place_vertex(); 
	v._location = location; 
	v._visited = 0; 
	v._time_to = 0; 
	return v; 
}

void Graph::printGraph() {

	// typedef map<place_vertex, set<place_vertex>, vertexComp>::const_iterator MapIterator;
	for (map<place_vertex, set<place_vertex> >::const_iterator iter = graph_container.begin(); 
		iter != graph_container.end(); iter++)
	{
	    cout << "Key: " << iter->first._location << endl << "Values:" << endl;
	    typedef set<place_vertex>::const_iterator ListIterator;
	    for (ListIterator list_iter = iter->second.begin(); list_iter != iter->second.end(); list_iter++)
	        cout << " " << list_iter->_location << endl;
	}

}

int main () {
	Graph g = Graph(); 
	cout << "add vertex" << endl;
	g.add_vertex("CVS"); 
	cout << "add vertex" << endl;
	g.add_vertex("Marshalls");
	cout << "add vertex" << endl;
	g.add_vertex("UPS");  
	g.printGraph(); 
	// cout << g << endl; 
	cout << "Started writing Graph program" << endl; 
}