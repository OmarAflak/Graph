#ifndef VERTEX
#define VERTEX

#include "Node.h"

class Vertex{
	private:
		Node *m_start;
		Node *m_end;

	public:
		Vertex();
		Vertex(Node* start, Node* end);

		Node* getStart() const;
		Node* getEnd() const;
		void setStart(Node* start);
		void setEnd(Node* end);
};

#endif
