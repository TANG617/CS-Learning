/*
 * @Author: LiTang litang0617@outlook.com
 * @Date: 2023-09-25 18:13:39
 * @LastEditTime: 2023-09-26 09:55:18
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
        // printf("_currentADDR:  ");
        cout<<_currentNode<<endl;
        size++;
        _insertedNode->_previousNode = _currentNode;
        _insertedNode->_nextNode = _currentNode->_nextNode;
        // return;

        if (_currentNode->_nextNode == nullptr){
            _currentNode->_nextNode = _insertedNode;
            _tailNode = _currentNode->_nextNode;
            // _currentNode = _currentNode->_nextNode;
            // printf("YYYYY");
            return;
        }
        
        _currentNode->_nextNode = _insertedNode;
        _currentNode->_nextNode->_previousNode = _insertedNode;
        // _currentNode = _currentNode->_nextNode; //move the pointer to the new node
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

void NodeList::removeNode(){ //default remove 'current' node
        if(_currentNode->_nextNode != nullptr){ //current is the last
            _currentNode->_nextNode->_previousNode = _currentNode->_previousNode;
        }
        else{
            _tailNode = _currentNode->_previousNode;
        }
        
        if(_currentNode->_previousNode != nullptr){
            _currentNode->_previousNode->_nextNode = _currentNode->_nextNode;
        }
        else{
            _headNode = _currentNode->_nextNode;
        }
        // free(_currentNode); //清空内存->内存溢出:)
        _currentNode = _headNode;
        size--;
    }
void NodeList::traverseNodeList(function<void(NodeStruct*)>traverseOperation){
    NodeStruct* iter_currentNode = this->_headNode;
    while(iter_currentNode != nullptr){
        iter_currentNode->isVisited = 1;
        traverseOperation(iter_currentNode);
        iter_currentNode = iter_currentNode->_nextNode;
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
        if(this->_currentNode->Data == targetNode.Data)
        {
            return _currentNode;
        }
        this->_currentNode = this->_currentNode->_nextNode;
    }
    return nullptr;
   
}


   