#include "../include/edge.h"

Edge::Edge(){
	mUid = genUid();
	mStart = nullptr;
	mEnd = nullptr;
	mData = nullptr;
}

Edge::Edge(const Edge& edge){
	mUid = edge.mUid;
	mStart = edge.mStart;
	mEnd = edge.mEnd;
	mInterface = edge.mInterface;
	if(edge.mData!=nullptr && edge.mInterface.mCopy){
		mData = edge.mInterface.mCopy(edge.mData);
	}
}

Edge::Edge(Node* start, Node* end){
	mUid = genUid();
	mStart = start;
	mEnd = end;
	mData = nullptr;
}

Edge::~Edge(){
	if(mData!=nullptr && mInterface.mDestroy){
		mInterface.mDestroy(mData);
	}
}

std::string Edge::getUid() const{
	return mUid;
}

Node* Edge::getStart() const{
	return mStart;
}

Node* Edge::getEnd() const{
	return mEnd;
}

void* Edge::getData() const{
	return mData;
}

void Edge::setStart(Node* start){
	mStart = start;
}

void Edge::setEnd(Node* end){
	mEnd = end;
}

void Edge::setData(void* data, DataInterface interface){
	mData = data;
	mInterface = interface;
}
