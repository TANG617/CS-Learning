/*
 * @Author: LiTang litang0617@outlook.com
 * @Date: 2023-09-25 16:59:35
 * @LastEditTime: 2023-09-26 09:32:04
 * @FilePath: /CS-Learning/DataStruct-2023/NodeStruct.cpp
 * @Description: 
 */
#include "NodeStruct.h"
using namespace std;
    // NodeStruct(NodeStruct* _preNode,NodeStruct* _nexNode);
NodeStruct::NodeStruct(NodeData data)
{
    this->Data = data;
    this->_previousNode = nullptr;
    this->_nextNode = nullptr;
    this->isVisited = 0;
}

NodeStruct::NodeData::NodeData(string *_nodeName, string *_nodeTitle, int ID){
    name = *_nodeName;
    title = *_nodeTitle;
    idnum = ID;
}
NodeStruct::NodeData::NodeData(const string& nodeName, const string& nodeTitle, int ID) :
    name(nodeName), title(nodeTitle), idnum(ID) {}

bool NodeStruct::NodeData::operator==(const NodeData& other) const{
    return (name == other.name) && (title == other.title) && (idnum == other.idnum);
}
