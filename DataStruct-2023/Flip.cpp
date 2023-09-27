/*
 * @Author: LiTang litang0617@outlook.com
 * @Date: 2023-09-25 19:50:44
 * @LastEditTime: 2023-09-27 16:45:06
 * @FilePath: /CS-Learning/DataStruct-2023/Flip.cpp
 * @Description: 
 */
#include "NodeList.h"
using namespace std;
void traverseOperation(NodeStruct* _currentNode){
cout<<"NodeData: "<<_currentNode->Data.name<<endl;
}
class flipNodeList : public NodeList{
    public:
        flipNodeList(NodeStruct *HEAD) : NodeList::NodeList(HEAD){}
        void traverseNodeList(function<void(NodeStruct*)>traverseOperation){
            NodeStruct* iter_currentNode;
            for(iter_currentNode = _getTailNode(); size>0 && iter_currentNode!=_getFrontNode(); iter_currentNode = iter_currentNode->_previousNode ){
                iter_currentNode->isVisited = 1;
                traverseOperation(iter_currentNode);
                // cout<<"tail: "<<_tailNode->Data.name<<endl;
            }
            if(size>0) traverseOperation(iter_currentNode);
            
        }

};
int main()
{
    freopen("in.txt","r",stdin);
    string rootDataStr = "root";
    NodeStruct::NodeData HeadData(&rootDataStr);
    NodeStruct Head(HeadData);
    flipNodeList List(&Head);

    for(int i=0;i<3;i++){
        string tempName;
        cin>>tempName;
        NodeStruct::NodeData* _tempNodeData = new NodeStruct::NodeData(&tempName);
        NodeStruct* _tempNode = new NodeStruct(*_tempNodeData);
        List.insertNode_tal(_tempNode);
        // List.traverseNodeList(traverseOperation);
        // cout<<endl;
    }
    List.traverseNodeList(traverseOperation);
    return 0;
    cout<<"REMOVE"<<endl;
    List._getNode(0);
    // NodeStruct node3("D");
    // List.insertNode(&node3);
    for(int i=0;i<3;i++){
        // cout<<"TAIL: "<<List._getTailNode()->Data.name<<endl;
        List.removeNode(List._getTailNode());
        List.traverseNodeList(traverseOperation);
        // cout<<"head"<<List._getHeadNode()->Data.name<<endl;
    }

    cout<<"ADD"<<endl;
    for(int i=0;i<3;i++){
        string tempName;
        string tempTitle;
        int tempID;
        cin>>tempName>>tempTitle>>tempID;

        // NodeStruct::NodeData tempNodeData(tempName,tempTitle,tempID);
        NodeStruct::NodeData* _tempNodeData = new NodeStruct::NodeData(&tempName,&tempTitle,tempID);
        NodeStruct* _tempNode = new NodeStruct(*_tempNodeData);
        

        // cout<<_tempNode->Data.name<<endl<<_tempNode<<endl;
        // continue;
        // NodeStruct* _tempNode = (NodeStruct *)malloc(1 * sizeof(NodeStruct));
        // NodeStruct::NodeData* _tempNodeData = (NodeStruct::NodeData *)malloc(1 * sizeof(NodeStruct::NodeData));

        // NodeStruct tempNode(tempNodeData);
        // &_tempNode(tempNodeData);
        // _tempNode->Data = tempNodeData;
        List.insertNode_tal(_tempNode);
        List.traverseNodeList(traverseOperation);
        cout<<endl;
        // cout<<List._getHeadNode()->Data.name<<endl;
    }
    
    // traverseOperation(&node);
    // return 0;
    
}