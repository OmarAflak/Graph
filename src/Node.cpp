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
