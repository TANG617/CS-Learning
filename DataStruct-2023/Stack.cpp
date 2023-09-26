/*
 * @Author: LiTang litang0617@outlook.com
 * @Date: 2023-09-26 16:34:39
 * @LastEditTime: 2023-09-26 19:35:08
 * @FilePath: /CS-Learning/DataStruct-2023/Stack.cpp
 * @Description: 
 */
#include "Stack.h"
Stack::Stack(NodeStruct* _Head) : NodeList(_Head){

}
NodeStruct* Stack::_topStack(){
    return _getTailNode();
}
void Stack::popStack(){
    if(size==0) runtime_error("Not enough item");
    removeNode(_getTailNode());
}
void Stack::pushStack(NodeStruct* _enqueuedNode){
    insertNode_tal(_enqueuedNode);
}