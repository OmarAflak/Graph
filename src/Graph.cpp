#include "../include/Graph.h"

Graph::Graph(){
}

Graph::~Graph(){
	for(int i=0 ; i<m_edges.size() ; i++){
		delete m_edges[i];
	}

	for(int i=0 ; i<m_nodes.size() ; i++){
		delete m_nodes[i];
	}
}

std::vector<Node*> Graph::getNodes() const{
	return m_nodes;
}

std::vector<Edge*> Graph::getEdges() const{
	return m_edges;
}

std::vector<Node*> Graph::getInConnections(std::string name) const{
	Node* node = getNode(name);
	std::vector<Node*> nodes;
	if(node!=nullptr){
		for(int i=0 ; i<m_edges.size() ; i++){
			if(m_edges[i]->getEnd()==node){
				nodes.push_back(m_edges[i]->getStart());
			}
		}
	}
	return nodes;
}

std::vector<Node*> Graph::getOutConnections(std::string name) const{
	Node* node = getNode(name);
	std::vector<Node*> nodes;
	if(node!=nullptr){
		for(int i=0 ; i<m_edges.size() ; i++){
			if(m_edges[i]->getStart()==node){
				nodes.push_back(m_edges[i]->getEnd());
			}
		}
	}
	return nodes;
}

Node* Graph::addNode(std::string name){
	Node* node = new Node(name);
	m_nodes.push_back(node);
	return node;
}

Node* Graph::getNode(std::string name) const{
	for(int i=0 ; i<m_nodes.size() ; i++){
		if(m_nodes[i]->getName()==name){
			return m_nodes[i];
		}
	}
	return nullptr;
}

void Graph::connect(std::string name1, std::string name2){
	Node* node1 = hasNode(name1)?getNode(name1):addNode(name1);
	Node* node2 = hasNode(name2)?getNode(name2):addNode(name2);
	node1->setOutConnections(node1->getOutConnections()+1);
	node2->setInConnections(node2->getInConnections()+1);
	Edge* edge = new Edge(node1, node2);
	m_edges.push_back(edge);
}

bool Graph::hasNode(std::string name) const{
	for(int i=0 ; i<m_nodes.size() ; i++){
		if(m_nodes[i]->getName()==name){
			return true;
		}
	}
	return false;
}

void Graph::print(){
	for(int i=0 ; i<m_edges.size() ; i++){
		std::cout << m_edges[i]->getStart()->getName() << " -> ";
		std::cout << m_edges[i]->getEnd()->getName() << std::endl;
	}
}

int Graph::getNodeIndex(Node* node) const{
	for(int i=0 ; i<m_nodes.size() ; i++){
		if(m_nodes[i]==node){
			return i;
		}
	}
	return -1;
}

void Graph::toStream(std::ostream& os) const{
	int length = m_nodes.size();
	std::vector<std::vector<bool> > connections(length, std::vector<bool>(length, false));

	for(int i=0 ; i<m_edges.size() ; i++){
		int index1 = getNodeIndex(m_edges[i]->getStart());
		int index2 = getNodeIndex(m_edges[i]->getEnd());
		connections[index1][index2] = true;
	}

	os << length << std::endl;
	for(int i=0 ; i<length ; i++){
		os << m_nodes[i]->getName() << "_";
		for(int j=0 ; j<length ; j++){
			os << connections[i][j];
		}
		os << std::endl;
	}
}

void Graph::fromStream(std::istream& is){
	std::string line;
	getline(is, line);
	int length = toInt(line);

	std::vector<std::vector<bool> > connections(length, std::vector<bool>(length, false));
	std::vector<std::string> names;

	for(int i=0 ; i<length ; i++){
		getline(is, line);
		int separator = line.find("_");
		names.push_back(line.substr(0, separator));
		for(int j=0 ; j<length; j++){
			if(line[separator+1+j]=='1'){
				connections[i][j] = true;
			}
		}
	}

	m_nodes.resize(length);
	for(int i=0 ; i<length ; i++){
		m_nodes[i] = new Node(names[i]);
	}

	m_edges.resize(0);
	for(int i=0 ; i<length ; i++){
		for(int j=0 ; j<length ; j++){
			if(connections[i][j]){
				m_nodes[i]->setOutConnections(m_nodes[i]->getOutConnections()+1);
				m_nodes[j]->setInConnections(m_nodes[j]->getInConnections()+1);
				Edge* edge = new Edge(m_nodes[i], m_nodes[j]);
				m_edges.push_back(edge);
			}
		}
	}
}

std::ostream& operator<<(std::ostream& os, const Graph& graph){
	graph.toStream(os);
	return os;
}

std::istream& operator>>(std::istream& is, Graph& graph){
	graph.fromStream(is);
	return is;
}
