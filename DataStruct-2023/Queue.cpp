/*
 * @Author: LiTang litang0617@outlook.com
 * @Date: 2023-09-26 16:34:39
 * @LastEditTime: 2023-09-26 23:18:29
 * @FilePath: /CS-Learning/DataStruct-2023/Queue.cpp
 * @Description: 
 */
#include "Queue.h"
Queue::Queue(NodeStruct* _Head) : NodeList(_Head){

}
NodeStruct* Queue::_getFront(){
    if(size == 0){
        runtime_error("EMPTY QUEUE");
        return nullptr;
    }
    return _getHeadNode()->_nextNode;
}
void Queue::deQueue(){
    if(size==0) runtime_error("EMPTY QUEUE");
    removeNode(_getHeadNode()->_nextNode);
}
void Queue::enQueue(NodeStruct* _enqueuedNode){
    insertNode_tal(_enqueuedNode);
}