/*
 * @Author: LiTang litang0617@outlook.com
 * @Date: 2023-06-06 15:25:23
 * @LastEditors: LiTang litang0617@outlook.com
 * @LastEditTime: 2023-06-11 16:57:56
 * @FilePath: /DXY/Q2.cpp
 * @Description: 
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
#include <stdio.h>
#include <stdlib.h>

int *sum_all(int *src, int n) {
    int size = n * (n + 1) / 2; // 计算和数组的大小
    int *sum = (int *) malloc(size * sizeof(int)); // 动态分配内存
    if (sum == NULL) { // 内存分配失败
        printf("内存分配失败！\n");
        exit(1);
    }
    int index = 0;
    for (int i = 0; i < n; i++) { // 计算和数组的值
        int s = 0;
        for (int j = i; j < n; j++) {
            s += src[j];
            sum[index++] = s;
        }
    }
    for (int i = 0; i < size - 1; i++) { // 对和数组进行排序
        for (int j = 0; j < size - 1 - i; j++) {
            if (sum[j] > sum[j + 1]) {
                int temp = sum[j];
                sum[j] = sum[j + 1];
                sum[j + 1] = temp;
            }
        }
    }
    return sum; // 返回排序后的和数组的基地址
}

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
    int *arr = input_ints(n);
    int *sum = sum_all(arr, n); // 调用函数 sum_all()
    printf("排序后的和数组为：");
    for (int i = 0; i < n * (n + 1) / 2; i++) {
        printf("%d ", sum[i]); // 输出排序后的和数组
    }
    free(sum); // 释放动态分配的内存
    return 0;
}
