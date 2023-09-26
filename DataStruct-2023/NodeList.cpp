/*
 * @Author: LiTang litang0617@outlook.com
 * @Date: 2023-09-25 18:13:39
 * @LastEditTime: 2023-09-27 00:06:31
 * @FilePath: /CS-Learning/DataStruct-2023/NodeList.cpp
 * @Description: 
 */
#include "NodeList.h"

NodeList::NodeList(NodeStruct* _headNode){
    this->_headNode = _headNode;
    this->_currentNode = _headNode;
    this->_tailNode = _headNode;
    size = 0;
}
void NodeList::insertNode(NodeStruct* _desNode, NodeStruct* _insertedNode){ //insert to 'current.next'
        // _desNode->_nextNode = _insertedNode;
        // printf("_currentADDR:  ");
        // cout<<_desNode<<endl;
        size++;
        _insertedNode->_previousNode = _desNode;
        _insertedNode->_nextNode = _desNode->_nextNode;
        // return;

        if (_desNode->_nextNode == nullptr){
            _desNode->_nextNode = _insertedNode;
            _tailNode = _desNode->_nextNode;
            // _desNode = _desNode->_nextNode;
            // printf("YYYYY");
            return;
        }
        
        _desNode->_nextNode = _insertedNode;
        _desNode->_nextNode->_previousNode = _insertedNode;
        // _desNode = _desNode->_nextNode; //move the pointer to the new node
    }
void NodeList::insertNode_hed(NodeStruct* _insertedNode){
    if(_headNode->_nextNode != nullptr){
        insertNode(_headNode->_nextNode,_insertedNode);
    }
    else{
        insertNode(_headNode,_insertedNode);
    }
    
}
void NodeList::insertNode_tal(NodeStruct* _insertedNode){
    insertNode(_tailNode,_insertedNode);
    _tailNode = _insertedNode;
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
void NodeList::removeNode(NodeStruct* _removedNode){ //default remove '_removedNode' node
        if(_removedNode->_nextNode != nullptr){ //current is the last
            _removedNode->_nextNode->_previousNode = _removedNode->_previousNode;
        }
        else{
            _tailNode = _removedNode->_previousNode;
            _removedNode->_previousNode->_nextNode = nullptr;
        }
        
        if(_removedNode->_previousNode != _headNode ){
            _removedNode->_previousNode->_nextNode = _removedNode->_nextNode;
        }
        else{
            _headNode->_nextNode = _removedNode->_nextNode;
            _removedNode->_nextNode->_previousNode = _headNode;
        }
        // free(_currentNode); //清空内存->内存溢出:)
        // _removedNode = _headNode;
        size--;
}
void NodeList::traverseNodeList(function<void(NodeStruct*)>traverseOperation){
    NodeStruct* iter_currentNode = this->_headNode;
    do{
        iter_currentNode->isVisited = 1;
        traverseOperation(iter_currentNode);
        iter_currentNode = iter_currentNode->_nextNode;
    }while(iter_currentNode != _tailNode);
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
    NodeStruct* _cursorNode = _headNode;
    while(_cursorNode != nullptr){
        _cursorNode->isVisited = 1;
        if(_cursorNode->Data == targetNode.Data)
        {
            return _cursorNode;
        }
        _cursorNode = _cursorNode->_nextNode;
    }
    return nullptr;
   
}
NodeStruct* NodeList::_getHeadNode(){
    return _headNode;
}
NodeStruct* NodeList::_getTailNode(){
    return _tailNode;
}
   