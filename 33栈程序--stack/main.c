//
//  main.c
//  33栈程序--stack
//
//  Created by 911 on 15/10/20.
//  Copyright (c) 2015年 911. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *pNext;
}NODE, *PNODE;

typedef struct Stack
{
    PNODE pTop;
    PNODE pButtom;
}STACK, *PSTACK;

void init(PSTACK);
void push(PSTACK,int);
void traverse(PSTACK);
bool pop(PSTACK,int *);
bool empty(PSTACK pS);
void clean(PSTACK pS);

int main()
{
    STACK S; // STACK等价于 struct Stack
    int val; // 出栈元素
    
    init(&S); // 造出一个空栈
    push(&S, 1);
    push(&S, 2);
    push(&S, 3);
    push(&S, 4);
    traverse(&S);
    clean(&S);
    
    if(pop(&S, &val)){
        printf("出栈成功,元素为%d\n",val);
    } else {
        printf("出栈失败");
    }
    traverse(&S);
    return 0;
}

void init(PSTACK pS)
{
    pS->pTop = (PNODE)malloc(sizeof(NODE));
    if (NULL == pS->pTop) {
        printf("动态内存分配失败！\n");
        exit(-1);
    } else {
        pS->pButtom = pS->pTop;
        pS->pTop->pNext = NULL; // 或者换成pS->pButtom->pNext = NULL
    }
}

void push(PSTACK pS,int val)
{
    PNODE pNew = (PNODE)malloc(sizeof(PNODE));
    
    pNew->data = val;
    pNew->pNext = pS->pTop;
    pS->pTop = pNew;
    return;
}

void traverse(PSTACK pS)
{
    PNODE p = pS->pTop;
    
    while (p != pS->pButtom) {
        printf("%d\n",p->data);
        p = p->pNext;
    }
    printf("\n");
    return;
}

bool empty(PSTACK pS)
{
    if (pS->pTop == pS->pButtom) {
        return true;
    } else {
        return false;
    }
}

// 把pS所指向的栈出栈一次，并把出栈的元素存入pVal形参所指向的变量中
bool pop(PSTACK pS,int * pVal)
{
    if (empty(pS)) { // pS本身存放的就是S的地址
        return false;
    } else {
        PNODE r = pS->pTop;
        *pVal = r->data;
        pS->pTop = r->pNext;
        
        free(r);
        r = NULL;
        
        return true;
    }
}

void clean(PSTACK pS)
{
    if (empty(pS)) {
        return;
    } else {
        PNODE p = pS->pTop;
        PNODE q = NULL;
        
        while (p != pS->pButtom) {
            q = p->pNext;
            free(p);
            p = q;
        }
        pS->pTop = pS->pButtom;
    }
}


