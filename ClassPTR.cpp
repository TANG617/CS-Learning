/*
 * @Author: LiTang litang0617@outlook.com
 * @Date: 2023-09-25 19:00:34
 * @LastEditTime: 2023-09-25 19:07:27
 * @FilePath: /CS-Learning/ClassPTR.cpp
 * @Description: 
 */
#include<iostream>
using namespace std;
class Node{
    private:
        
    public:
        int data = 10;
        Node(int Data){this->data = Data;}
        int getData(){return this->data;}
        
};

int Op(Node* aNode){
    return aNode->getData();
}

int main()
{
Node newNode(100);
// Node *newNode();
cout<<Op(&newNode)<<endl;
}