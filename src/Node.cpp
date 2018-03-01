#include "../include/Node.h"

Node::Node(std::string name){
	m_name = name;
}

Node::Node(){
	m_name = "";
}

std::string Node::getName() const{
	return m_name;
}

int Node::getConnections() const{
	return m_connections;
}

void Node::setConnections(int connections){
	m_connections = connection;
}
