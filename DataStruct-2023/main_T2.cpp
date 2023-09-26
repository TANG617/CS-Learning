/*
 * @Author: LiTang litang0617@outlook.com
 * @Date: 2023-09-25 19:50:44
 * @LastEditTime: 2023-09-27 00:07:08
 * @FilePath: /CS-Learning/DataStruct-2023/main_T2.cpp
 * @Description: 
 */
#include "Queue.h"
#include "Stack.h"
using namespace std;
void traverseOperation(NodeStruct* _cursorNode){
cout<<"NodeData: "<<_cursorNode->Data.name<<endl;
}

class Parking{
    public:
        class ParkingStack : public Stack {
            public:
                int maxCapacity;
                ParkingStack(NodeStruct* _root):Stack(_root){}
        };
        class WaitingQueue : public Queue{
            public:
                int maxCapacity;
                WaitingQueue(NodeStruct* _root):Queue(_root){}
        };
        ParkingStack PStack;
        WaitingQueue WQueue;

        Parking(int parkingCap, NodeStruct* _parkingRoot, int waitingCap, NodeStruct* _waitingRoot)
        : PStack(_parkingRoot),WQueue(_waitingRoot){
            PStack.maxCapacity = parkingCap;
            WQueue.maxCapacity = waitingCap;
        }
        
        void enterPark(NodeStruct* _enteredCar){
            if(PStack.size < PStack.maxCapacity){
                PStack.pushStack(_enteredCar);
            }
            else if(WQueue.size < WQueue.maxCapacity){
                WQueue.enQueue(_enteredCar);
            }
            else{
                runtime_error("FULL PARK");
            }

        }
        NodeStruct* _exitPark(){
            // PStack.popStack();
            // WQueue.deQueue();
            // cout<<WQueue._getFront()<<endl;
            // cout<<PStack._topStack()<<endl;
            PStack.pushStack(WQueue._getFront());
            // WQueue.removeNode(WQueue._getFront());
            
            // cout<<WQueue._getFront()<<endl;
            // cout<<PStack._topStack()<<endl;
            
            
            

        }
        NodeStruct* _findCar(string* _targetCarID){
            NodeStruct targetCar(_targetCarID);
            NodeStruct* _result = PStack._findNode(targetCar);
            if(_result==nullptr){
                runtime_error("NO TARGET CAR");
            }
            return _result;

        }
        void traversePark(){
            PStack.traverseNodeList(traverseOperation);
            WQueue.traverseNodeList(traverseOperation);
        }
        
};

int main()
{
    freopen("in.txt","r",stdin);
    int maxParking, maxWaiting;
    string rootParkDataStr = "===rootPark===";
    string rootWaitDataStr = "===rootWait===";
    cin>>maxParking>>maxWaiting;
    
    NodeStruct::NodeData rootParkData(&rootParkDataStr);
    // return 0;
    NodeStruct rootPark(rootParkData);
    NodeStruct::NodeData rootWaitData(&rootWaitDataStr);
    NodeStruct rootWait(rootWaitData);
    
    Parking ParkingLot(maxParking,&rootPark,maxWaiting,&rootWait);
    
    while(1){
        string op;
        cin>>op;
        if(op == "enter"){
            string CarID;
            cin>>CarID;
            NodeStruct::NodeData* _tempNodeData = new NodeStruct::NodeData(&CarID);
            NodeStruct* _tempNode = new NodeStruct(*_tempNodeData);
            ParkingLot.enterPark(_tempNode);
        }
        else if(op == "exit"){
            cout<<ParkingLot._exitPark()->Data.name;
        }
        else if(op == "find"){
            string CarID;
            cin>>CarID;
            NodeStruct* targetCar = ParkingLot._findCar(&CarID);
        }
        else if(op == "traverse"){
            ParkingLot.traversePark();
        }
        
        
    }
}