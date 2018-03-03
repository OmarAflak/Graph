#include <iostream>
#include <fstream>
#include "../include/Graph.h"

using namespace std;

Graph createGraph(){
	Graph graph;
	
	// Nodes are created implicitly when using connect()
	graph.connect("Emmanuel M", "François B");
	graph.connect("Manuel V", "Christiane T");
	graph.connect("Manuel V", "Alain J");
	graph.connect("François B", "Emmanuel M");
	graph.connect("Marine L", "Manuel V");
	return graph;
}

void saveGraph(const Graph &graph, const char* filename){
	ofstream out(filename);
	out << graph;
	out.close();
}

Graph loadGraph(const char* filename){
	Graph graph;
	ifstream in(filename);
	in >> graph;
	return graph;
}

int main(){
	// Create graph
	Graph graph = createGraph();

	// Save it
	saveGraph(graph, "graph.txt");

	// Load it
	// You can edit graph.txt manually and comment the lines above
	Graph _graph = loadGraph("graph.txt");
	_graph.print();
}
