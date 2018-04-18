#include "../include/Edge.h"

Edge::Edge(){
	m_start = nullptr;
	m_end = nullptr;
}

Edge::Edge(Node* start, Node* end){
	m_start = start;
	m_end = end;
}

Node* Edge::getStart() const{
	return m_start;
}

Node* Edge::getEnd() const{
	return m_end;
}

void Edge::setStart(Node* start){
	m_start = start;
}

void Edge::setEnd(Node* end){
	m_end = end;
}
