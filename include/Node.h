#ifndef NODE
#define NODE

#include <string>

class Node{
	private:
		std::string m_name;
		
	public:
		Node();
		Node(std::string name);
		
		std::string getName();
};

#endif
