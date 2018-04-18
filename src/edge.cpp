#include "../include/edge.h"

Edge::Edge(){
	mStart = nullptr;
	mEnd = nullptr;
}

Edge::Edge(Node* start, Node* end){
	mStart = start;
	mEnd = end;
}

Node* Edge::getStart() const{
	return mStart;
}

Node* Edge::getEnd() const{
	return mEnd;
}

void Edge::setStart(Node* start){
	mStart = start;
}

void Edge::setEnd(Node* end){
	mEnd = end;
}
