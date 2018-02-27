#ifndef GRAPH
#define GRAPH

#include <iostream>
#include <vector>

#include "Node.h"
#include "Vertex.h"

class Graph{
	private:
		std::vector<Vertex*> m_vertices;
		std::vector<Node*> m_nodes;
		
	public:
		Graph();
		~Graph();
		
		void addNode(Node* node);
		void connect(Node* node1, Node* node2);
		bool hasNode(Node* node);
		int getNodesCount();
		
		void print();
};

#endif
