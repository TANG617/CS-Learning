/*
 * @Author: LiTang litang0617@outlook.com
 * @Date: 2023-09-25 19:50:44
 * @LastEditTime: 2023-09-25 20:48:17
 * @FilePath: /CS-Learning/DataStruct-2023/main.cpp
 * @Description: 
 */
#include "NodeList.h"
using namespace std;
void traverseOperation(NodeStruct* _currentNode){
cout<<"NodeData: "<<_currentNode->NodeData<<endl;
}

int main()
{
    
    NodeStruct Head("A");
    NodeList List(&Head);
    NodeStruct node1("B");
    List.insertNode(&node1);
    NodeStruct node2("C");
    List.insertNode(&node2);
    List._getNode(0);
    // NodeStruct node3("D");
    // List.insertNode(&node3);
    List.removeNode();
    // traverseOperation(&node);
    // return 0;
    List.traverseNodeList(traverseOperation);
}