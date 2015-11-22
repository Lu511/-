//
//  main.c
//  point_1
//
//  Created by 911 on 15/10/6.
//  Copyright (c) 2015年 911. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
struct Arr {
    int *pBase; // 储存的是数组第一个元素的地址
    int len; // 数组所能容纳的最大元素的个数
    int cnt; // 当前数组有效元素的个数
};

void init_arr(struct Arr *pArr,int length);
bool append_arr(struct Arr *pArr,int val); // 追加
bool insert_arr(struct Arr *pArr,int pos,int val); // 插入
bool delete_arr(struct Arr *pArr,int pos,int *pVal);
int get();
bool is_empty(struct Arr *pArr);
bool is_full(struct Arr *pArr);
void sort_arr(struct Arr *pArr);
void show_arr(struct Arr *pArr);
void inversion_arr(struct Arr *pArr);

int main(void)
{
    struct Arr arr;
    //int val;
    int length;
    printf("输入所需个数:");
    scanf("%d",&length);
    init_arr(&arr,length);
    append_arr(&arr, 1);
    append_arr(&arr, 7);
    append_arr(&arr, 6);
    append_arr(&arr, 4);
    append_arr(&arr, 2);
    sort_arr(&arr);

//    if (delete_arr(&arr, 1, &val)) {
//        printf("删除成功\n");
//        printf("你删除的是：%d\n",val);
//    } else {
//        printf("删除失败\n");
//    }
    inversion_arr(&arr);
    
    show_arr(&arr);
    return 0;
}

void init_arr(struct Arr *pArr,int length)
{
    pArr->pBase = (int *)malloc(sizeof(int) * length);
    if (NULL == pArr->pBase) {
        printf("动态分布内存失败！\n");
        exit(-1);
    } else {
        pArr->len = length;
        pArr->cnt = 0;
    }
    return;
}

bool is_empty(struct Arr *pArr)
{
    if (0 == pArr->cnt) {
        return true;
    } else {
        return false;
    }
}

bool is_full(struct Arr *pArr)
{
    if (pArr->cnt == pArr->len) {
        return true;
    } else {
        return false;
    }
}

void show_arr(struct Arr *pArr)
{
    if (is_empty(pArr)) {
        printf("数组为空!\n");
    } else {
        for (int i = 0; i < pArr->cnt; ++i) {
            printf("%d\n",pArr->pBase[i]);
        }
    }
}

bool append_arr(struct Arr *pArr,int val)
{
    // 慢的时候返回false
    if (is_full(pArr)) {
        return false;
    } else { // 不满时追加
        pArr->pBase[pArr->cnt] = val;
        (pArr->cnt)++;
        return true;
    }
}

bool insert_arr(struct Arr *pArr,int pos,int val)
{
    int i;
    if (is_full(pArr)) {
        return false;
    }
    
    if (pos < 1 || pos > pArr->cnt + 1) {
        return false;
    }
    for (i = pArr->cnt - 1; i >= pos - 1; --i) {
        pArr->pBase[i + 1] = pArr->pBase[i];
    }
    pArr->pBase[pos - 1] = val;
    pArr->cnt ++;
    return true;
}

bool delete_arr(struct Arr *pArr,int pos,int *pVal)
{
    int i;
    if (is_empty(pArr)) {
        return false;
    }
    if (pos < 1 || pos > pArr->cnt) {
        return false;
    }
    
    *pVal = pArr->pBase[pos - 1];
    for (i = pos; i < pArr->cnt; ++i) {
        pArr->pBase[i - 1] = pArr->pBase[i];
    }
    pArr->cnt --;
    return true;
    
}

void inversion_arr(struct Arr *pArr)
{
    int i = 0;
    int j = pArr->cnt - 1;
    int t;
    while (i < j) {
        t = pArr->pBase[i];
        pArr->pBase[i] = pArr->pBase[j];
        pArr->pBase[j] = t;
        ++i;
        --j;;
    }
    return;
    
}

void sort_arr(struct Arr *pArr)
{
    int i;
    int j;
    int t;
    for (i = 0; i < pArr->cnt; i++) {
        for (j = i + 1; j < pArr->cnt; j++) {
            if (pArr->pBase[i] < pArr->pBase[j]) {
                t = pArr->pBase[i];
                pArr->pBase[i] = pArr->pBase[j];
                pArr->pBase[j] = t;
            }
        }
    }
    return;
}