# Graph
## Download & Compile

```
git clone https://github.com/OmarAflak/Graph.git
cd Graph
make
```

## Example

```c++
#include <iostream>
#include <fstream>
#include "../include/graph.h"

int main(){
	Graph graph;
	graph.connect("Emmanuel M", "François B");
	graph.connect("Manuel V", "Christiane T");
	graph.connect("Manuel V", "Alain J");
	graph.connect("François B", "Emmanuel M");
	graph.connect("Marine L", "Manuel V");

	GraphEntry entry = graph.getNodeData("Emmanuel M");
	entry.mNode->setData(new std::string("Hello World!"), DataInterface(
		[](void* data){
			delete (std::string*) data;
		},
		[](void* data){
			std::string* str = (std::string*) data;
			std::string* p = new std::string();
			*p = *str;
			return p;
		})
	);

	graph.print();
}
```
