#include "Node.h"
using namespace std;
    // Node(NodeStruct* _preNode,NodeStruct* _nexNode);
NodeStruct::NodeStruct(NodeStruct* _preNode, NodeStruct* _nexNode, string& data)
{
    this->currentNodeData = data;
    this->_previousNode = _preNode;
    this->_nextNode = _nexNode;
    this->isVisited = 0;
}
