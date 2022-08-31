#include<stdio.h>
#include<stdlib.h>
#define initSize 100
typedef struct{
    int *data;
    int maxSize,currentLength;
}SeqList;
SeqList L;
//Operations
bool listInsert(SeqList &L,int insertPosition,int insertData);
bool listDelete(SeqList &L,int deletePosition);
int listLocate(SeqList &L,int targetData);


int main()
{
// Init SequenceList
L.data=(int*)malloc(sizeof(int)*initSize);




}
bool listInsert(SeqList &L,int insertPosition,int insertData)
{
    // Check whether legal
    if(insertPosition<1 ||insertPosition>L.currentLength+1)
    {
        return false;
    }
    // Move element
    for(int i=L.currentLength;i>=insertPosition;i--)
    {
        L.data[i]=L.data[i-1];
    }
    L.data[insertPosition-1]=insertData;
    L.currentLength++;
    return true;
}