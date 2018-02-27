#ifndef GRAPH
#define GRAPH

#include <iostream>
#include <vector>

#include "Node.h"
#include "Vertex.h"
#include "Utils.h"

class Graph{
	private:
		std::vector<Vertex*> m_vertices;
		std::vector<Node*> m_nodes;

		int getNodeIndex(Node* node);

	public:
		Graph();
		~Graph();

		Node* addNode(std::string name);
		Node* getNode(std::string name);
		void connect(std::string name1, std::string name2);
		bool hasNode(std::string name);

		void print();
		void toStream(std::ostream& os);
		void fromStream(std::istream& is);
};

#endif
