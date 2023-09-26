/*
 * @Author: LiTang litang0617@outlook.com
 * @Date: 2023-09-25 18:13:50
 * @LastEditTime: 2023-09-26 19:00:45
 * @FilePath: /CS-Learning/DataStruct-2023/NodeList.h
 * @Description: 
 */
#ifndef NodeList_H
#define NodeList_H
#include <iostream>
#include <functional>
#include "NodeStruct.h"
using namespace std;
class NodeList
{
private:
    
    // void traverseOperation(NodeStruct* _currentNode);
    // NodeStruct* _matchNode(NodeStruct targetNode);
public:
    NodeStruct* _headNode;
    NodeStruct* _currentNode;
    NodeStruct* _tailNode;
    int size;   
    NodeList(NodeStruct* _headNode);
    NodeList();
    void insertNode(NodeStruct* _insertedNode);
    void insertNode_pre(NodeStruct* _insertedNode);
    void insertNode_nex(NodeStruct* _insertedNode);
    void insertNode_hed(NodeStruct* _insertedNode);
    void insertNode_tal(NodeStruct* _insertedNode);
    void removeNode();
    void removeNode(NodeStruct* _removedNode);
    void traverseNodeList(function<void(NodeStruct*)>traverseOperation);
    NodeStruct* _getNode(int rank);
    NodeStruct* _getHeadNode();
    NodeStruct* _getTailNode();
    NodeStruct* _findNode(NodeStruct targetNode);
    
};


#endif