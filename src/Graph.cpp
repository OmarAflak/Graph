#include "../include/Graph.h"

Graph::Graph(){
}

Graph::~Graph(){
	for(int i=0 ; i<m_vertices.size() ; i++){
		delete m_vertices[i];
	}
}

void Graph::addNode(Node* node){
	m_nodes.push_back(node);
}

void Graph::connect(Node* node1, Node* node2){
	if(!hasNode(node1)){
		addNode(node1);
	}
	if(!hasNode(node2)){
		addNode(node2);
	}
	Vertex* vertex = new Vertex();
	vertex->setStart(node1);
	vertex->setEnd(node2);
	m_vertices.push_back(vertex);
}

bool Graph::hasNode(Node* node){
	for(int i=0 ; i<m_nodes.size() ; i++){
		if(m_nodes[i]==node){
			return true;
		}
	}
	return false;
}

int Graph::getNodesCount(){
	return m_nodes.size();
}

void Graph::print(){
	for(int i=0 ; i<m_vertices.size() ; i++){
		std::cout << m_vertices[i]->getStart()->getName() << " -> ";
		std::cout << m_vertices[i]->getEnd()->getName() << std::endl;
	}
	std::cout << std::endl;
}
