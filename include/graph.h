#ifndef GRAPH
#define GRAPH

#include <iostream>
#include <utility>
#include <map>

#include "graphEntry.h"

class Graph{
	private:
		std::map<std::string, GraphEntry> mData;

	public:
		Graph();
		Graph(const Graph& graph);
		~Graph();

		std::map<std::string, GraphEntry> getAllData() const;
		GraphEntry getNodeData(const std::string& uid) const;
		bool hasNode(const std::string& uid) const;

		Node* addNode(const std::string& uid="");
		Node* addNode(Node* const node);
		void connect(const std::string& uid1, const std::string& uid2);
		void connect(Node* const node1, Node* const node2);

		void print() const;
};

#endif
