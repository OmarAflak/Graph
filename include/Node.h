#ifndef NODE
#define NODE

#include <string>

class Node{
	private:
		std::string m_name;
		int m_inConnections;
		int m_outConnections;

	public:
		Node();
		Node(std::string name);

		std::string getName() const;
		int getInConnections() const;
		int getOutConnections() const;

		void setInConnections(int connections);
		void setOutConnections(int connections);
};

#endif
