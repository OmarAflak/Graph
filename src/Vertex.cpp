#include "../include/Vertex.h"

Vertex::Vertex(){
	m_start = nullptr;
	m_end = nullptr;
}

Vertex::Vertex(Node* start, Node* end){
	m_start = start;
	m_end = end;
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
