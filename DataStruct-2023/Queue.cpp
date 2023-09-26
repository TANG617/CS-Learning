/*
 * @Author: LiTang litang0617@outlook.com
 * @Date: 2023-09-26 16:34:39
 * @LastEditTime: 2023-09-26 19:32:05
 * @FilePath: /CS-Learning/DataStruct-2023/Queue.cpp
 * @Description: 
 */
#include "Queue.h"
Queue::Queue(NodeStruct* _Head) : NodeList(_Head){

}
NodeStruct* Queue::_getFront(){
    return _getHeadNode();
}
void Queue::deQueue(){
    if(size==0) runtime_error("Not enough item");
    removeNode(_getHeadNode());
}
void Queue::enQueue(NodeStruct* _enqueuedNode){
    insertNode_tal(_enqueuedNode);
}