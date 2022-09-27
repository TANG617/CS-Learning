#include<iostream>
using namespace std;
#define PARK_SIZE 1001
int numCar=0;
Car * LastCar=nullptr;
Car * FirstCar=nullptr;
Car * cursorPark=nullptr;
//Make sure first and last is global
struct  Car
{
    string carID;
    Car * prior;
    Car * next;
    bool inPark=1;
    int position;
};

void InitCar()
{
    Car CAR;
    CAR.carID="\0";
    CAR.prior=nullptr;
    CAR.next=nullptr;
    numCar=1;
    LastCar=&CAR;
    FirstCar=&CAR;
}

void updateStatus()
{
    Car *cursorCar=FirstCar;
    int positionCar=0;
    while((*cursorCar).next!=nullptr)
    {
        (*cursorCar).position=positionCar;
        if(positionCar<PARK_SIZE)
        {
            (*cursorCar).inPark=1;
        }
        else if(positionCar==PARK_SIZE)
        {
            cursorPark=cursorCar;
            (*cursorCar).inPark=1;
        }
        else
        {
            (*cursorCar).inPark=0;
        }
        cursorCar=(*cursorCar).next;
        positionCar++;
    }
        
}

void ShowAllCar()
{
    Car *cursorCar=FirstCar;
    int positionCar=0;
    while((*cursorCar).next!=nullptr)
    {
        (*cursorCar).position=positionCar;
        
        printf("在停车场%s第%d位的汽车车牌为%s",cursorCar->inPark?"在":"不在",cursorCar->position-PARK_SIZE*(!cursorCar->inPark),cursorCar->carID);
        cursorCar=(*cursorCar).next;
        positionCar++;
    }
        
}


bool PushBackCar(string ID)// add a new car at the last
{
    Car * temp=(Car*)malloc(sizeof(Car));
    temp->carID=ID;
    temp->prior=LastCar;
    temp->next=nullptr;
    LastCar=temp;
    numCar++;
    updateStatus();
}

bool PushFrontCar(string ID)
{
    Car * temp=(Car*)malloc(sizeof(Car));
    temp->carID=ID;
    temp->prior=nullptr;
    temp->next=FirstCar;
    FirstCar=temp;
    numCar++;
    updateStatus();
}

void PopParkedCar()
{
    Car *priorCar=(*cursorPark).prior;
    (*priorCar).next=nullptr;
    free(*LastCar);
    LastCar=priorCar;
    numCar--;
    updateStatus();
}



bool SearchCar(string targetID,Car  *targetPosition)
{
    Car *cursorCar=FirstCar;
    int positionCar=0;
    while((*cursorCar).next!=nullptr)
    {
        if((*cursorCar).carID==targetID)
        {
            targetPosition=cursorCar;
            return 1;
        }
        cursorCar=(*cursorCar).next;
        positionCar++;
    }
        targetPosition=nullptr;
        return 0;
    
    
}

int main()
{
// 进入停车场
PushBackCar("BJTU0001");
// 离开停车场
PopParkedCar();
//按车牌号查找车辆位置
Car SearchResult;
if(SearchCar("BJTU0001",&SearchResult))
{
    printf("车辆%s停车场\n",SearchResult.inPark?"在":"不在");
    printf("车辆的位置为:%d",SearchResult.position-PARK_SIZE*(!SearchResult.inPark));
}
//显示出停车场及等待队列中的全部车辆信息
ShowAllCar();
}