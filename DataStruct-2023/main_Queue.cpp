/*
 * @Author: LiTang litang0617@outlook.com
 * @Date: 2023-09-25 19:50:44
 * @LastEditTime: 2023-09-27 09:27:26
 * @FilePath: /CS-Learning/DataStruct-2023/main_Queue.cpp
 * @Description: 
 */
#include "Queue.h"
using namespace std;
void traverseOperation(NodeStruct* _currentNode){
cout<<"NodeData: "<<_currentNode->Data.name<<endl;
}

int main()
{
    freopen("in.txt","r",stdin);
    string rootDataStr = "root";
    NodeStruct::NodeData HeadData(&rootDataStr);
    NodeStruct Head(HeadData);
    Queue waitingQueue(&Head);

    while(1){
        string op;
        cin>>op;
        if(op == "enqueue"){
            string tempName;
            string tempTitle;
            int tempID;
            cin>>tempName>>tempTitle>>tempID;
            NodeStruct::NodeData* _tempNodeData = new NodeStruct::NodeData(&tempName,&tempTitle,tempID);
            NodeStruct* _tempNode = new NodeStruct(*_tempNodeData);
            // cout<<_tempNode->Data.name<<endl<<_tempNode<<endl;
            cout<<waitingQueue.size<<endl;
            waitingQueue.enQueue(_tempNode);
            waitingQueue.traverseNodeList(traverseOperation);
        }
        else if (op == "dequeue")
        {
            try
            {
                waitingQueue.deQueue();
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            waitingQueue.traverseNodeList(traverseOperation);
        }
        
        
        
    }
    // waitingQueue._getNode(0);
    // NodeStruct node3("D");
    // waitingQueue.insertNode(&node3);
    // waitingQueue.removeNode();
    // traverseOperation(&node);
    // return 0;
    waitingQueue.traverseNodeList(traverseOperation);
}