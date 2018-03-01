#include "../include/Node.h"

Node::Node(std::string name){
	m_name = name;
	m_inConnections = 0;
	m_outConnections = 0;
}

Node::Node(){
	m_name = "";
	m_inConnections = 0;
	m_outConnections = 0;
}

std::string Node::getName() const{
	return m_name;
}

int Node::getInConnections() const{
	return m_inConnections;
}

int Node::getOutConnections() const{
	return m_outConnections;
}

void Node::setInConnections(int connections){
	m_inConnections = connections;
}

void Node::setOutConnections(int connections){
	m_outConnections = connections;
}
