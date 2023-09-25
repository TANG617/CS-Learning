/*
 * @Author: LiTang litang0617@outlook.com
 * @Date: 2023-09-25 18:13:39
 * @LastEditTime: 2023-09-25 20:03:45
 * @FilePath: /CS-Learning/DataStruct-2023/NodeList.cpp
 * @Description: 
 */
#include "NodeList.h"

NodeList::NodeList(NodeStruct* _headNode){
    this->_headNode = _headNode;
    this->_currentNode = _headNode;
    this->_tailNode = _headNode;
    size = 1;
}

void NodeList::insertNode(NodeStruct* _insertedNode){ //insert to 'current.next'
        // _currentNode->_nextNode = _insertedNode;
        _insertedNode->_previousNode = _currentNode;
        _currentNode->_nextNode->_previousNode = _insertedNode;
        _insertedNode->_nextNode = _currentNode->_nextNode;
        size++;
        _currentNode = _currentNode->_nextNode; //move the pointer to the new node
        if (_currentNode->_nextNode == nullptr){
            _tailNode = _currentNode;
        }
    }

void NodeList::insertNode_pre(NodeStruct* _insertedNode){
    if (_currentNode->_previousNode == nullptr){
        _currentNode->_previousNode = _insertedNode;
        _insertedNode->_nextNode = _currentNode;
        return;
    }
    _currentNode = _currentNode->_previousNode;
    insertNode(_insertedNode);
}
void NodeList::insertNode_nex(NodeStruct* _insertedNode){
    insertNode(_insertedNode);
}
void NodeList::insertNode_hed(NodeStruct* _insertedNode){
    _currentNode = _headNode;
    insertNode(_insertedNode);
}
void NodeList::insertNode_tal(NodeStruct* _insertedNode){
    _currentNode = _tailNode;
    insertNode(_insertedNode);
}

void NodeList::removeNode(NodeStruct* _deletedNode){ //default remove 'current' node
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
NodeStruct* NodeList::NodeList::_getNode(int rank){ //modify 'current'
    this->_currentNode = this->_headNode;
    for (int i = 0; i < rank; i++)
    {
        this->_currentNode = this->_currentNode->_nextNode;
    }
    return _currentNode; 
}

NodeStruct* NodeList::_findNode(NodeStruct targetNode) //modify 'current'
{
    this->_currentNode = this->_headNode;
    while(this->_currentNode != nullptr){
        this->_currentNode->isVisited = 1;
        if(this->_currentNode->NodeData == targetNode.NodeData)
        {
            return _currentNode;
        }
        this->_currentNode = this->_currentNode->_nextNode;
    }
    return nullptr;
   
}


   