//
//  main.c
//  47 -- 循环队列
//
//  Created by 911 on 15/10/23.
//  Copyright (c) 2015年 911. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue{
    int *pBase;
    int front;
    int rear;
}QUEUE;

void init(QUEUE *); // 初始化
bool en_queue(QUEUE *,int val); // 入队
void traverse_queue(QUEUE *);
bool full_queue(QUEUE *);
bool empty_queue(QUEUE *);
bool out_queue(QUEUE *,int *);

int main()
{
    int val;
    QUEUE Q;
    init(&Q);
    en_queue(&Q, 1);
    en_queue(&Q, 2);
    en_queue(&Q, 3);
    en_queue(&Q, 4);
    en_queue(&Q, 5);
    traverse_queue(&Q);
    
    if (out_queue(&Q, &val)) {
        printf("出对成功，出队元素为%d\n",val);
    } else {
        printf("失败");
    }
    
    traverse_queue(&Q);
    
    return 0;
}

void init(QUEUE *pQ)
{
    pQ->pBase = (int *)malloc(sizeof(int) * 6);
    pQ->front = 0;
    pQ->rear = 0;
}

bool full_queue(QUEUE *pQ)
{
    if ((pQ->rear + 1) % 6 == pQ->front) {
        return true;
    } else {
        return false;
    }
}

bool empty_queue(QUEUE *pQ)
{
    if (pQ->front == pQ->rear) {
        return true;
    } else {
        return false;
    }
}

bool en_queue(QUEUE *pQ,int val)
{
    if (full_queue(pQ)) {
        return false;
    } else {
        pQ->pBase[pQ->rear] = val;
        pQ->rear = (pQ->rear + 1) % 6;
        return true;
    }
}

// 遍历
void traverse_queue(QUEUE *pQ)
{
    int i = pQ->front;
    
    while (i != pQ->rear) {
        printf("%d",pQ->pBase[i]);
        i = (i + 1) % 6;
    }
    return;
}

bool out_queue(QUEUE *pQ,int *pVal)
{
    if (empty_queue(pQ)) {
        return false;
    } else {
        *pVal = pQ->pBase[pQ->front];
        pQ->front = (pQ->front + 1) % 6;
        return true;
    }
}
