//
//  main.c
//  数据结构-18
//
//  Created by 911 on 15/10/11.
//  Copyright (c) 2015年 911. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node
{
    int data; // 数据域可以非常复杂
    struct Node *pNext; // 指针域
}NODE,*PNODE; // NODE == struct Node , PNODE == struct Node *

// 函数声明
PNODE creat_list(void);
void traverse_list(PNODE pHead);
void sort_list(PNODE pHead);
int length_list(PNODE pHead);
bool insert_list(PNODE pHead, int pos,int val);
bool delete_list(PNODE pHead, int pos,int *pVal);

int main ()
{
    PNODE pHead = NULL; // 等价于 struct Node *pHead = NULL;
    
    int pVal;
    pHead = creat_list(); // 创建一个非循环单链表，并将该链表的头结点的地址付给pHead
//    insert_list(pHead, 2, 6);
    
    delete_list(pHead, 4, &pVal);
    traverse_list(pHead);
//    int len = length_list(pHead);
//    printf("链表的长度是%d\n",len);
//    
//    sort_list(pHead);
//    traverse_list(pHead);
    

    return 0;
}

// 创建链表
PNODE creat_list(void)
{
    int len; // 用来存放有效节点的个数
    int i;
    int val; // 用来临时存放用户输入节点的值
    
    // 分别了一个不存放有效性数据的头结点
    PNODE pHead = (PNODE)malloc(sizeof(NODE));
    if (NULL == pHead) {
        printf("分配内存失败！\n");
        exit(-1);
    }
    
    PNODE pTail = pHead;
    pTail->pNext = NULL;
    
    printf("请输入需要的节点数：len = ");
    scanf("%d",&len);
    
    for (i = 0; i < len; ++i) {
        printf("请输入第%d个节点的值：",i + 1);
        scanf("%d",&val);
        
        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if (NULL == pNew) {
            printf("分配内存失败！\n");
            exit(-1);
        }
        pNew->data = val;
        pTail->pNext = pNew;
        pNew->pNext= NULL;
        pTail = pNew;
    }
    return pHead;
}

// 遍历链表
void traverse_list(PNODE pHead)
{
    PNODE p = pHead->pNext;
    while (NULL != p) {
        printf("%d",p->data);
        p = p->pNext;
        printf("\n");
    }
    printf("\n");
    return;
}

// 求链表的长度
int length_list(PNODE pHead)
{
    int len = 0;
    PNODE p = pHead->pNext;
    while (NULL != p) {
        len++;
        p = p->pNext;
    }
    return len;
}

// 排序链表
void sort_list(PNODE pHead)
{
    int i,j,t;
    int len = length_list(pHead);
    PNODE p,q;
    for (i = 0,p = pHead->pNext;i < len - 1 ; ++i,p = p->pNext) {
        for (j = i + 1,q = p->pNext; j < len; ++j,q = q->pNext) {
            if (p->data > q->data) {
                t = p->data;
                p->data = q->data;
                q->data = t;
            }
        }
    }
}

// 在pHead所指向链表的第pos个节点的前面插入一个新的节点，节点的值为val；
bool insert_list(PNODE pHead, int pos,int val)
{
    int i = 0;
    PNODE p = pHead;
    
    while (NULL != p && i < pos - 1) {
        p = p->pNext;
        ++i;
    }
    
    if (i > pos - 1 || NULL == p) {
        return false;
    }
    
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if (NULL == pNew) {
        printf("动态内存分配失败！\n");
        exit(-1);
    }
    pNew->data = val;
    PNODE q = p->pNext;
    p->pNext = pNew;
    pNew->pNext = q;
    
    return true;
}

bool delete_list(PNODE pHead, int pos,int *pVal)
{
    int i = 0;
    PNODE p = pHead;
    
    while (NULL != p->pNext && i < pos - 1) {
        p = p->pNext;
        ++i;
    }
    
    if (i > pos - 1 || NULL == p->pNext) {
        return false;
    }
    
    PNODE q = p->pNext;
    *pVal = q->data;
    
    // 删除p节点后面的结点
    p->pNext = p->pNext->pNext;
    free(q);
    q = NULL;
    
    return true;
}