#include<stdio.h>
#include<stdlib.h>
int testFunc(int a)
{
    if (a>=100)
    {
        return 1;
    }
    printf("Yes\n");
    return testFunc(a+1);
}
int main()
{
    printf("%d",testFunc(0));
}