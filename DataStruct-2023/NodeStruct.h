/*
 * @Author: LiTang litang0617@outlook.com
 * @Date: 2023-09-25 16:59:45
 * @LastEditTime: 2023-09-25 19:56:07
 * @FilePath: /CS-Learning/DataStruct-2023/NodeStruct.h
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
    string NodeData;
    bool isVisited;

    // NodeStruct(NodeStruct* _preNode,NodeStruct* _nexNode);
    NodeStruct(string data);


private:
};


#endif