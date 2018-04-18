#ifndef EDGE
#define EDGE

#include "Node.h"

class Edge{
	private:
		Node *m_start;
		Node *m_end;

	public:
		Edge();
		Edge(Node* start, Node* end);

		Node* getStart() const;
		Node* getEnd() const;
		void setStart(Node* start);
		void setEnd(Node* end);
};

#endif
