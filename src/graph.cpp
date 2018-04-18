#include "../include/graph.h"

Graph::Graph(){
}

Graph::Graph(const Graph& graph){
	for(const auto& entry : graph.mData){
		Node* copy = new Node(*entry.second.mNode);
		mData[copy->getUid()] = GraphEntry(copy);
	}

	for(auto& entry : graph.mData){
		for(auto& edge : entry.second.mIn){
			Edge* copy = new Edge(*edge);
			copy->setStart(mData[copy->getStart()->getUid()].mNode);
			copy->setEnd(mData[copy->getEnd()->getUid()].mNode);
			mData[copy->getStart()->getUid()].mOut.push_back(copy);
			mData[copy->getEnd()->getUid()].mIn.push_back(copy);
		}
	}
}

Graph::~Graph(){
	for(auto& entry : mData){
		delete entry.second.mNode;
		for(auto& edge : entry.second.mIn){
			delete edge;
		}
	}
}

std::map<std::string, GraphEntry> Graph::getAllData() const{
	return mData;
}

GraphEntry Graph::getNodeData(const std::string& uid) const{
	return mData.at(uid);
}

bool Graph::hasNode(const std::string& uid) const{
	return (mData.find(uid)!=mData.end());
}

Node* Graph::addNode(const std::string& uid){
	Node node(uid);
	return addNode(&node);
}

Node* Graph::addNode(Node* const node){
	Node* copy = new Node(*node);
	mData[copy->getUid()] = GraphEntry(copy);
	return copy;
}

void Graph::connect(const std::string& uid1, const std::string& uid2){
	Node node1(uid1), node2(uid2);
	connect(&node1, &node2);
}

void Graph::connect(Node* const node1, Node* const node2){
	Node* n1 = hasNode(node1->getUid())?mData[node1->getUid()].mNode:addNode(node1);
	Node* n2 = hasNode(node2->getUid())?mData[node2->getUid()].mNode:addNode(node2);
	Edge* edge = new Edge(n1, n2);
	mData[n1->getUid()].mOut.push_back(edge);
	mData[n2->getUid()].mIn.push_back(edge);
}

void Graph::print() const{
    for(const auto& entry : mData){
        std::cout << entry.second.mNode->getUid() << std::endl;
        for(const auto& e : entry.second.mIn){
            std::cout << "\t<- " << e->getStart()->getUid() << std::endl;
        }
        for(const auto& e : entry.second.mOut){
            std::cout << "\t-> " << e->getEnd()->getUid() << std::endl;
        }
    }
}
