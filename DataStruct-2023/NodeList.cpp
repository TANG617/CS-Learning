#include "NodeList.h"

NodeList::NodeList(NodeStruct* _headNode)
{
    this->_headNode = _headNode;
    this->_currentNode = _headNode;
    this->_tailNode = _headNode;
    size = 1;
}

void NodeList::insertNode(NodeStruct* _insertedNode){ //default to the next of current
        _currentNode->_nextNode = _insertedNode;
        _insertedNode->_previousNode = _currentNode;
        _currentNode->_nextNode->_previousNode = _insertedNode;
        _insertedNode->_nextNode = _currentNode->_nextNode;
        size++;
    }
void NodeList::removeNode(NodeStruct* _deletedNode){ //default remove current node
        _currentNode->_nextNode->_previousNode = _currentNode->_previousNode;
        _currentNode->_previousNode->_nextNode = _currentNode->_nextNode;
        size--;
    }

void NodeList::traverseNodeList(function<void(NodeStruct*)>traverseOperation){
    this->_currentNode = this->_headNode;
    while(this->_currentNode != nullptr){
        this->_currentNode->isVisited = 1;
        traverseOperation(_currentNode);
        this->_currentNode = this->_currentNode->_nextNode;
    }
}
void NodeList::findNode(NodeStruct* _targetNode){}
   