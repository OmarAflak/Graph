#ifndef EDGE
#define EDGE

#include "node.h"

class Edge{
	private:
		Node *mStart;
		Node *mEnd;

	public:
		Edge();
		Edge(Node* start, Node* end);

		Node* getStart() const;
		Node* getEnd() const;
		void setStart(Node* start);
		void setEnd(Node* end);
};

#endif
