#include "../include/node.h"

Node::Node(std::string name){
	mName = name;
	mInConnections = 0;
	mOutConnections = 0;
}

Node::Node(){
	mName = "";
	mInConnections = 0;
	mOutConnections = 0;
}

std::string Node::getName() const{
	return mName;
}

int Node::getInConnections() const{
	return mInConnections;
}

int Node::getOutConnections() const{
	return mOutConnections;
}

void Node::setInConnections(int connections){
	mInConnections = connections;
}

void Node::setOutConnections(int connections){
	mOutConnections = connections;
}
