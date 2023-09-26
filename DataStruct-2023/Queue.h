/*
 * @Author: LiTang litang0617@outlook.com
 * @Date: 2023-09-26 16:34:51
 * @LastEditTime: 2023-09-26 20:08:29
 * @FilePath: /CS-Learning/DataStruct-2023/Queue.h
 * @Description: 
 */
#ifndef Queue_H
#define Queue_H
#include "NodeList.h"
class Queue : public NodeList{
    private:
    public:
        Queue();
        Queue(NodeStruct* Head);
        NodeStruct* _getFront();
        void deQueue(); 
        void enQueue(NodeStruct* _enqueuedNode);
};



#endif