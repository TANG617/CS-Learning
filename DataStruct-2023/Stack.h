/*
 * @Author: LiTang litang0617@outlook.com
 * @Date: 2023-09-26 16:34:51
 * @LastEditTime: 2023-09-26 20:07:08
 * @FilePath: /CS-Learning/DataStruct-2023/Stack.h
 * @Description: 
 */
#ifndef Stack_H
#define Stack_H
#include "NodeList.h"
class Stack : public NodeList{
    private:
    public:
        Stack(NodeStruct* Head);
        Stack();
        NodeStruct* _topStack();
        void pushStack(NodeStruct* _enqueuedNode); 
        void popStack();
};



#endif