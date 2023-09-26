/*
 * @Author: LiTang litang0617@outlook.com
 * @Date: 2023-09-25 19:50:44
 * @LastEditTime: 2023-09-26 19:39:06
 * @FilePath: /CS-Learning/DataStruct-2023/main_Stack.cpp
 * @Description: 
 */
#include "Stack.h"
using namespace std;
void traverseOperation(NodeStruct* _currentNode){
cout<<"NodeData: "<<_currentNode->Data.name<<endl;
}

int main()
{
    NodeStruct::NodeData HeadData("root", "null",0);
    NodeStruct Head(HeadData);
    Stack parkStack(&Head);

    while(1){
        string op;
        cin>>op;
        if(op == "push"){
            string tempName;
            string tempTitle;
            int tempID;
            cin>>tempName>>tempTitle>>tempID;
            NodeStruct::NodeData* _tempNodeData = new NodeStruct::NodeData(&tempName,&tempTitle,tempID);
            NodeStruct* _tempNode = new NodeStruct(*_tempNodeData);
            cout<<_tempNode->Data.name<<endl<<_tempNode<<endl;
            parkStack.pushStack(_tempNode);
            parkStack.traverseNodeList(traverseOperation);
        }
        else if (op == "pop")
        {
            try
            {
                parkStack.popStack();
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            parkStack.traverseNodeList(traverseOperation);
        }
        else if (op == "top")
        {
            cout<<parkStack._topStack()->Data.name<<endl;
            parkStack.traverseNodeList(traverseOperation);
        }
        
        
    }
    // parkStack._getNode(0);
    // NodeStruct node3("D");
    // parkStack.insertNode(&node3);
    // parkStack.removeNode();
    // traverseOperation(&node);
    // return 0;
    parkStack.traverseNodeList(traverseOperation);
}