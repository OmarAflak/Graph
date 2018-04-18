#include "../include/node.h"

Node::Node(){
	mUid = genUid();
	mData = nullptr;
}

Node::Node(const Node& node){
	mUid = node.mUid;
	mInterface = node.mInterface;
	if(node.mData!=nullptr && node.mInterface.mCopy){
		mData = node.mInterface.mCopy(node.mData);
	}
}

Node::Node(std::string uid){
	mUid = uid;
	mData = nullptr;
}

Node::~Node(){
	if(mData!=nullptr && mInterface.mDestroy){
		mInterface.mDestroy(mData);
	}
}

std::string Node::getUid() const{
	return mUid;
}

void* Node::getData() const{
	return mData;
}

void Node::setData(void* data, DataInterface interface){
	mData = data;
	mInterface = interface;
}
