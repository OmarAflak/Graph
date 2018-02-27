#include <iostream>
#include <fstream>
#include "Graph.h"

using namespace std;

void createGraph(){
	Graph graph;

	// Nodes are created implicitly
	graph.connect("Emmanuel M", "François B");
	graph.connect("Manuel V", "Christiane T");
	graph.connect("Manuel V", "Alain J");
	graph.connect("François B", "Emmanuel M");
	graph.connect("Marine L", "Manuel V");

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
