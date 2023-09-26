/*
 * @Author: LiTang litang0617@outlook.com
 * @Date: 2023-09-25 16:59:45
 * @LastEditTime: 2023-09-26 22:59:01
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
    class NodeData{
        public:
            string name = "";
            string title = "";
            int idnum = 0;
            bool operator==(const NodeData& other) const;
            NodeData(string *_nodeName, string *_nodeTitle, int idnum);
            NodeData(string *_nodeName);
            // NodeData(string& nodeName, string& nodeTitle, int ID);
            // NodeData(const string& nodeName);
            // NodeData(string& nodeName);
            NodeData() {}
    };
    NodeStruct* _previousNode;
    NodeStruct* _nextNode;
    NodeData Data;
    bool isVisited;
    // NodeStruct(NodeStruct* _preNode,NodeStruct* _nexNode);
    NodeStruct(NodeData data);


private:
};


#endif