#include <stdio.h>
#include "zylib.h"

void InputDi(int* a, int n);
void Disort(BOOL ascending, int* a, int n);
void Swap(int a, int b);

int main()
{
	int n,* a;
	n = GetIntegerFromKeyboard();
	a = (int*)malloc(n*sizeof(n));
	InputDi(a, n);
	STRING s=GetStringFromKeyboard();
	BOOL ascending=TRUE;
	if(CompareString(s, "TRUE")==0)
		ascending=TRUE;
	else
		ascending=FALSE;
	Disort(ascending, a, n);
	return 0;
}

void InputDi(int* a, int n)
{
	int i;
	char ch;
	for(i=0; i<n; i++)
	{
		scanf("%d", &*(a+i));
		ch = getchar();
		if(ch=='\n')
			break;
	}
}

void Disort(BOOL ascending, int* a, int n)
{
	int i, j;
	if(ascending)
	{
		for(i=0; i<n-1; i++)
		{
			for(j=i; j<n; j++)
			{
				if(*(a+i)>*(a+j))
					Swap(*(a+i), *(a+j));
			}
		}
	}
	else
	{
		for(i=0; i<n-1; i++)
		{
			for(j=i; j<n; j++)
			{
				if(*(a+i)<*(a+j))
					Swap(*(a+i), *(a+j));
			}
		}
	}
	for(i=0; i<n; i++)
		printf("%d ", *(a+i));
	printf("\n");
}

void Swap(int a, int b)
{
	int t;
	t=a;
	a=b;
	b=t;
}