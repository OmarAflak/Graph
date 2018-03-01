#ifndef NODE
#define NODE

#include <string>

class Node{
	private:
		std::string m_name;
		int m_connections;

	public:
		Node();
		Node(std::string name);

		std::string getName() const;
		int getConnections() const;

		void setConnections(int connection);
};

#endif
