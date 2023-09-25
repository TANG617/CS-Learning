/*
 * @Author: LiTang litang0617@outlook.com
 * @Date: 2023-09-25 19:50:44
 * @LastEditTime: 2023-09-25 20:13:53
 * @FilePath: /CS-Learning/DataStruct-2023/main.cpp
 * @Description: 
 */
#include "NodeList.h"
using namespace std;
void traverseOperation(NodeStruct* _currentNode){
cout<<"NodeData"<<_currentNode->NodeData;
}

int main()
{
    NodeStruct Head("A");
    NodeStruct node("B");
    NodeList List(&Head);
    List.insertNode(&node);
    List.traverseNodeList(traverseOperation);
}