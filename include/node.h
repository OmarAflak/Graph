#ifndef NODE
#define NODE

#include <string>
#include "dataInterface.h"
#include "utils.h"

class Node{
	private:
		std::string mUid;
		void* mData;
		DataInterface mInterface;

	public:
		Node();
		Node(const Node& node);
		Node(std::string uid);
		~Node();

		std::string getUid() const;
		void* getData() const;
		void setData(void* data, DataInterface interface);
};

#endif
