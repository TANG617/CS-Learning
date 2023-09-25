/*
 * @Author: LiTang litang0617@outlook.com
 * @Date: 2023-06-06 13:57:53
 * @LastEditors: LiTang litang0617@outlook.com
 * @LastEditTime: 2023-06-11 16:39:14
 * @FilePath: /DXY/Q1.cpp
 * @Description: 
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */

#include <stdio.h>
#include <stdlib.h>

int *input_ints(int n) {
    int *arr = (int *) malloc(n * sizeof(int)); // 动态分配内存
    if (arr == NULL) { // 内存分配失败
        printf("内存分配失败！\n");
        exit(1);
    }
    printf("请输入 %d 个整数：\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); // 读取用户输入的整数
    }
    return arr; // 返回数组的基地址
}

int main() {
    int n;
    printf("请输入整数的个数：");
    scanf("%d", &n);
    int *arr = input_ints(n); // 调用函数 input_ints()
    printf("输入的整数为：");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); // 输出数组中保存的整数
    }
    free(arr); // 释放动态分配的内存
    return 0;
}
