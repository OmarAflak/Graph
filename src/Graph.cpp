#include "../include/Graph.h"

Graph::Graph(){
}

Graph::~Graph(){
	for(int i=0 ; i<m_vertices.size() ; i++){
		delete m_vertices[i];
	}
	
	for(int i=0 ; i<m_nodes.size() ; i++){
		delete m_nodes[i];
	}
}

void Graph::addNode(Node* node){
	m_nodes.push_back(node);
}

void Graph::connect(Node* node1, Node* node2){
	if(!hasNode(node1)){
		addNode(node1);
	}
	if(!hasNode(node2)){
		addNode(node2);
	}
	Vertex* vertex = new Vertex();
	vertex->setStart(node1);
	vertex->setEnd(node2);
	m_vertices.push_back(vertex);
}

bool Graph::hasNode(Node* node){
	for(int i=0 ; i<m_nodes.size() ; i++){
		if(m_nodes[i]==node){
			return true;
		}
	}
	return false;
}

int Graph::getNodesCount(){
	return m_nodes.size();
}

void Graph::print(){
	for(int i=0 ; i<m_vertices.size() ; i++){
		std::cout << m_vertices[i]->getStart()->getName() << " -> ";
		std::cout << m_vertices[i]->getEnd()->getName() << std::endl;
	}
	std::cout << std::endl;
}

int Graph::getNodeIndex(Node* node){
	for(int i=0 ; i<m_nodes.size() ; i++){
		if(m_nodes[i]==node){
			return i;
		}
	}
	return -1;
}

void Graph::toStream(std::ostream& os){
	int length = m_nodes.size();
	std::vector<std::vector<bool> > connections(length, std::vector<bool>(length, false));
	for(int i=0 ; i<m_vertices.size() ; i++){
		int index1 = getNodeIndex(m_vertices[i]->getStart());
		int index2 = getNodeIndex(m_vertices[i]->getEnd());
		if(index1!=-1 && index2!=-1){
			connections[index1][index2] = true;
		}
		else{
			std::cout << "oups";
		}
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
	int length;
	is >> length;
	std::vector<std::vector<bool> > connections(length, std::vector<bool>(length, false));
	
	std::vector<std::string> names;
	std::string name;
	char c = ' ';
	for(int i=0 ; i<length ; i++){
		while((c=is.get())!='_'){
			name += c;
		}
		names.push_back(name);
		for(int j=0 ; j<length ; j++){
			c = is.get();
			if(c=='1'){
				connections[i][j] = true;
			}
		}
	}
	
	m_nodes.resize(length);
	for(int i=0 ; i<length ; i++){
		m_nodes[i] = new Node(names[i]);
	}
		
	for(int i=0 ; i<length ; i++){
		for(int j=0 ; j<length ; j++){
			if(connections[i][j]){
				Vertex* vertex = new Vertex();
				vertex->setStart(m_nodes[i]);
				vertex->setEnd(m_nodes[j]);
				m_vertices.push_back(vertex);
			}
		}
	}
}
