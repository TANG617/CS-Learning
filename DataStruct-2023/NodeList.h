/*
 * @Author: LiTang litang0617@outlook.com
 * @Date: 2023-09-25 18:13:50
 * @LastEditTime: 2023-09-25 19:20:03
 * @FilePath: /CS-Learning/DataStruct-2023/NodeList.h
 * @Description: 
 */
#ifndef NodeList_H
#define NodeList_H
#include <iostream>
#include "Node.h"
using namespace std;
class NodeList
{
private:
    NodeStruct* _headNode;
    NodeStruct* _currentNode;
    NodeStruct* _tailNode;
    int size;
    void traverseNodeList(function<void(NodeStruct*)>traverseOperation);
    void traverseOperation(NodeStruct* _currentNode);
public:
    NodeList(NodeStruct* _headNode);
    void insertNode(NodeStruct* _insertedNode);
    void removeNode(NodeStruct* _deletedNode);
    void findNode(NodeStruct* _targetNode);
    
};


#endif