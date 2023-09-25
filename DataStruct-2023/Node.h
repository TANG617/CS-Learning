/*
 * @Author: LiTang litang0617@outlook.com
 * @Date: 2023-09-25 16:59:45
 * @LastEditTime: 2023-09-25 19:08:12
 * @FilePath: /CS-Learning/DataStruct-2023/Node.h
 * @Description: 
 */
#ifndef  Node_H
#define Node_H

#include <string>
#include <iostream>
using namespace std;

class NodeStruct{
public:
    NodeStruct* _previousNode;
    NodeStruct* _nextNode;
    string currentNodeData;
    bool isVisited;

    // Node(NodeStruct* _preNode,NodeStruct* _nexNode);
    NodeStruct(NodeStruct* _preNode, NodeStruct* _nexNode, string& data);


private:
};


#endif