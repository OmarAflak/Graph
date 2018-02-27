#include <iostream>
#include <fstream>
#include "Graph.h"

using namespace std;

void createGraph(){
	Graph graph;

	// Nodes are created implicitly
	graph.connect("Omar", "Joss");
	graph.connect("Joss", "Omar");
	graph.connect("Omar", "Alex");
	graph.connect("Joss", "Alex");

	ofstream out("graph");
	graph.toStream(out);
	out.close();
}

void loadGraph(){
	Graph graph;
	ifstream in("graph");
	graph.fromStream(in);
	graph.print();
}

int main(){
	createGraph();
	loadGraph();
}
