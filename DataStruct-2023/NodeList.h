/*
 * @Author: LiTang litang0617@outlook.com
 * @Date: 2023-09-25 18:13:50
 * @LastEditTime: 2023-09-25 20:09:43
 * @FilePath: /CS-Learning/DataStruct-2023/NodeList.h
 * @Description: 
 */
#ifndef NodeList_H
#define NodeList_H
#include <iostream>
#include <functional>
#include "Node.h"
using namespace std;
class NodeList
{
private:
    NodeStruct* _headNode;
    NodeStruct* _currentNode;
    NodeStruct* _tailNode;
    int size;
    // void traverseOperation(NodeStruct* _currentNode);
    // NodeStruct* _matchNode(NodeStruct targetNode);
public:
    NodeList(NodeStruct* _headNode);
    void insertNode(NodeStruct* _insertedNode);
    void insertNode_pre(NodeStruct* _insertedNode);
    void insertNode_nex(NodeStruct* _insertedNode);
    void insertNode_hed(NodeStruct* _insertedNode);
    void insertNode_tal(NodeStruct* _insertedNode);
    void removeNode(NodeStruct* _deletedNode);
    void traverseNodeList(function<void(NodeStruct*)>traverseOperation);
    NodeStruct* _getNode(int rank);
    NodeStruct* _findNode(NodeStruct targetNode);
    
};


#endif