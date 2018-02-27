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

int Graph::getNodeIndex(Node* node){
	for(int i=0 ; i<m_nodes.size() ; i++){
		if(m_nodes[i]==node){
			return i;
		}
	}
	return -1;
}

void Graph::toStream(std::ostream& os){
	int length = m_nodes.size();
	std::vector<std::vector<bool> > connections(length, std::vector<bool>(length, false));
	for(int i=0 ; i<m_vertices.size() ; i++){
		int index1 = getNodeIndex(m_vertices[i]->getStart());
		int index2 = getNodeIndex(m_vertices[i]->getEnd());
		connections[index1][index2] = true;
	}
	
	for(int i=0 ; i<length ; i++){
		for(int j=0 ; j<length ; j++){
			os << connections[i][j] << " ";
		}
		os << std::endl;
	}
}
