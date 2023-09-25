/*
 * @Author: LiTang litang0617@outlook.com
 * @Date: 2023-09-25 16:59:35
 * @LastEditTime: 2023-09-25 19:56:24
 * @FilePath: /CS-Learning/DataStruct-2023/Node.cpp
 * @Description: 
 */
#include "Node.h"
using namespace std;
    // Node(NodeStruct* _preNode,NodeStruct* _nexNode);
NodeStruct::NodeStruct(string data)
{
    this->NodeData = data;
    this->_previousNode = nullptr;
    this->_nextNode = nullptr;
    this->isVisited = 0;
}
