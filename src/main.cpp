#include <iostream>
#include <fstream>
#include "../include/Graph.h"

using namespace std;

void createGraph(const char* filename){
	Graph graph;

	// Nodes are created implicitly when connecting them together
	graph.connect("Emmanuel M", "François B");
	graph.connect("Manuel V", "Christiane T");
	graph.connect("Manuel V", "Alain J");
	graph.connect("François B", "Emmanuel M");
	graph.connect("Marine L", "Manuel V");

	ofstream out(filename);
	out << graph;
	out.close();
}

void loadGraph(const char* filename){
	Graph graph;
	ifstream in(filename);
	in >> graph;
	graph.print();
}

int main(){
	createGraph("graph");
	loadGraph("graph");
}
