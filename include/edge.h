#ifndef EDGE
#define EDGE

#include "node.h"

class Edge{
	private:
		std::string mUid;
		Node* mStart;
		Node* mEnd;
		void* mData;
		DataInterface mInterface;

	public:
		Edge();
		Edge(const Edge& edge);
		Edge(Node* start, Node* end);
		~Edge();

		std::string getUid() const;
		Node* getStart() const;
		Node* getEnd() const;
		void* getData() const;

		void setStart(Node* start);
		void setEnd(Node* end);
		void setData(void* data, DataInterface interface);
};

#endif
