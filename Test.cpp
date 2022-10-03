#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 4
void UpdateCycleCursor(int *cursor,int operation)
{
    
    if((*cursor+operation)>0)
    {
        *cursor=(*cursor+operation)%MAXSIZE;
        if (*cursor==0)
        {
            *cursor=MAXSIZE;
        }
        //When it's just can be divided, we use the last number of element nor the 0
        
    }
    else
    {
        *cursor=(*cursor+operation+MAXSIZE);
    }
    // Queue.front=(Queue.front+1)%MAXSIZE;
    // Queue.rear=(Queue.rear+1)%MAXSIZE;
    //Update the cursor status after every operation
}
int main()
{
    printf("%d %d %d %d %d %d",'(',')','[',']','{','}');
    
}
    