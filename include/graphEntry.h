#ifndef GRAPH_DATA
#define GRAPH_DATA

#include "edge.h"
#include <vector>

struct GraphEntry {
    Node* mNode;
    std::vector<Edge*> mIn;
    std::vector<Edge*> mOut;

    GraphEntry(Node* node=nullptr){
        mNode = node;
    }
};

#endif
