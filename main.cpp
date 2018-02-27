#include <iostream>
#include <fstream>
#include "Graph.h"

using namespace std;

int main(){
	Graph graph;
	Node* node1 = new Node("Omar");
	Node* node2 = new Node("Joss");
	Node* node3 = new Node("Alex");
	
	graph.connect(node1, node2);
	graph.connect(node2, node1);
	graph.connect(node1, node3);
	graph.connect(node2, node3);
	
	ofstream out("bckp.txt");
	if(out){
		graph.toStream(out);
		out.close();
	}
	
	ifstream in("bckp.txt");
	if(in){
		graph.fromStream(in);
	}
	
	graph.toStream(cout);
}
