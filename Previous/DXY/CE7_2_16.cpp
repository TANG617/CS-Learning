/*
 * @Author: LiTang litang0617@outlook.com
 * @Date: 2023-06-11 15:47:35
 * @LastEditors: LiTang litang0617@outlook.com
 * @LastEditTime: 2023-06-11 16:30:54
 * @FilePath: /DXY/CE7_2_16.cpp
 * @Description: 
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
#include<iostream>
#include <stdio.h>
#include "zylib.h"

void Increasing(int* p, int n);
void Decreasing(int* p, int n);//这种实现方式不属于动态数组库

int* CreateSet(int n)
{
	int *p = (int*)malloc(sizeof(int)*n);

	for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]); // 读取用户输入的整数
    }

	getchar();
	return p;
}

int main()
{
	int n, i;
	char ch;
	n = GetIntegerFromKeyboard();
	// int* p = (int*)malloc(n*sizeof(int));
	// for(i=0; i<n; i++)
	// {
	// 	scanf("%d", &*(p+i));
	// 	ch = getchar();
	// 	if(ch=='\n')
	// 		break;
	// }
	int *p = CreateSet(n);
	STRING s = GetStringFromKeyboard();
	if(CompareString(s, "TRUE")==0)
		Increasing(p, n);
	else
		Decreasing(p, n);
	return 0;
}

void Increasing(int* p, int n)
{
	int j, k, l;
	for(j=0; j<(n-1); j++)
	{
		int t = *(p+j);
		int index = j;
		for(k=j+1; k<n; k++)
		{
			if(t > *(p+k))
			{
				t = *(p+k);
				index = k;
			}
		}
		*(p+index)=*(p+j);
		*(p+j) = t;//把最小数和第j个数的指针交换;
	}
	for(l=0; l<n; l++)
		printf("%d ", *(p+l));
	printf("\n");
}

void Decreasing(int* p, int n)
{
	int j, k, l;
	for(j=0; j<(n-1); j++)
	{
		int t = *(p+j);
		int index = j;
		for(k=j+1; k<n; k++)
		{
			if(t < *(p+k))
			{
				t = *(p+k);
				index = k;
			}
		}
		*(p+index)=*(p+j);
		*(p+j) = t;//把最大数和第j个数的指针交换;
	}
	for(l=0; l<n; l++)
		printf("%d ", *(p+l));
	printf("\n");
}