/*
 * @Author: LiTang litang0617@outlook.com
 * @Date: 2023-09-25 19:50:44
 * @LastEditTime: 2023-09-26 09:48:49
 * @FilePath: /CS-Learning/DataStruct-2023/main.cpp
 * @Description: 
 */
#include "NodeList.h"
using namespace std;
void traverseOperation(NodeStruct* _currentNode){
cout<<"NodeData: "<<_currentNode->Data.name<<endl;
}

int main()
{
    NodeStruct::NodeData HeadData("root", "null",0);
    NodeStruct Head(HeadData);
    NodeList List(&Head);

    while(1){
        string tempName;
        string tempTitle;
        int tempID;
        cin>>tempName>>tempTitle>>tempID;

        // NodeStruct::NodeData tempNodeData(tempName,tempTitle,tempID);
        NodeStruct::NodeData* _tempNodeData = new NodeStruct::NodeData(&tempName,&tempTitle,tempID);
        NodeStruct* _tempNode = new NodeStruct(*_tempNodeData);
        

        cout<<_tempNode->Data.name<<endl<<_tempNode<<endl;
        // continue;
        // NodeStruct* _tempNode = (NodeStruct *)malloc(1 * sizeof(NodeStruct));
        // NodeStruct::NodeData* _tempNodeData = (NodeStruct::NodeData *)malloc(1 * sizeof(NodeStruct::NodeData));

        // NodeStruct tempNode(tempNodeData);
        // &_tempNode(tempNodeData);
        // _tempNode->Data = tempNodeData;
        List.insertNode(_tempNode);
        List.traverseNodeList(traverseOperation);
    }
    List._getNode(0);
    // NodeStruct node3("D");
    // List.insertNode(&node3);
    List.removeNode();
    // traverseOperation(&node);
    // return 0;
    List.traverseNodeList(traverseOperation);
}