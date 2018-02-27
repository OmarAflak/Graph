#include "../include/Vertex.h"

Vertex::Vertex(){
	m_start = NULL;
	m_end = NULL;
}

Node* Vertex::getStart() const{
	return m_start;
}

Node* Vertex::getEnd() const{
	return m_end;
}

void Vertex::setStart(Node* start){
	m_start = start;
}

void Vertex::setEnd(Node* end){
	m_end = end;
}
