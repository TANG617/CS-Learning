/*
 * @Author: LiTang litang0617@outlook.com
 * @Date: 2023-09-25 18:13:39
 * @LastEditTime: 2023-09-27 09:18:56
 * @FilePath: /CS-Learning/DataStruct-2023/NodeList.cpp
 * @Description: 
 */
#include "NodeList.h"

NodeList::NodeList(NodeStruct* _headNode){
    this->_headNode = _headNode;
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
void NodeList::removeNode(NodeStruct* _removedNode){ //default remove '_removedNode' node
    if(_removedNode == _getFrontNode() && _removedNode == _getTailNode()){
        emptyNodeList();
    }
    else{
        if (_removedNode == _getTailNode())
        {
           _removedNode->_previousNode->_nextNode = nullptr;
           _tailNode = _removedNode->_previousNode;
        }
        else{
            _removedNode->_nextNode->_previousNode = _removedNode->_previousNode;
            _removedNode->_previousNode->_nextNode = _removedNode->_nextNode;
        }
        
    }
}
void NodeList::traverseNodeList(function<void(NodeStruct*)>traverseOperation){
    NodeStruct* iter_currentNode;
    for(iter_currentNode = _getFrontNode(); size>1 && iter_currentNode!=_tailNode; iter_currentNode = iter_currentNode->_nextNode ){
        iter_currentNode->isVisited = 1;
        traverseOperation(iter_currentNode);
    }
    if(size>1) traverseOperation(iter_currentNode);
    
}
NodeStruct* NodeList::NodeList::_getNode(int rank){ //modify 'current'
    NodeStruct * _cursorNode;
    _cursorNode = this->_headNode;
    for (int i = 0; i < rank; i++)
    {
        _cursorNode = _cursorNode->_nextNode;
    }
    return _cursorNode; 
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
NodeStruct* NodeList::_getFrontNode(){
    return _headNode->_nextNode;
}
NodeStruct* NodeList::_getTailNode(){
    return _tailNode;
}
void NodeList::emptyNodeList(){
    _headNode->_previousNode = nullptr;
    _headNode->_nextNode = nullptr;
    _tailNode = _headNode;
    size = 0;
}