#include <iostream>
#include "Graph.h"

using namespace std;

int main(){
	Graph graph;
	Node* node1 = new Node("Omar");
	Node* node2 = new Node("Jo$$");
	Node* node3 = new Node("Alex");
	
	graph.connect(node1, node2);
	graph.connect(node2, node1);
	graph.connect(node1, node3);
	graph.connect(node2, node3);
	
	graph.toStream(cout);
	
	delete node1;
	delete node2;
	delete node3;
}
