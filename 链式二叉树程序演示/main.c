//
//  main.c
//  链式二叉树程序演示
//
//  Created by 911 on 15/11/10.
//  Copyright (c) 2015年 911. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


struct BTNode{
    char data;
    struct BTNode* pLchild;
    struct BTNode* pRchild;
};

struct BTNode* CreatBTree(void);
void PreTraverseBTree(struct BTNode*);

int main()
{
    struct BTNode *pT = CreatBTree();
    PreTraverseBTree(pT);
    return 0;
}

struct BTNode* CreatBTree(void)
{
    struct BTNode* pA = (struct BTNode *)malloc(sizeof(struct BTNode));
    struct BTNode* pB = (struct BTNode *)malloc(sizeof(struct BTNode));
    struct BTNode* pC = (struct BTNode *)malloc(sizeof(struct BTNode));
    struct BTNode* pD = (struct BTNode *)malloc(sizeof(struct BTNode));
    struct BTNode* pE = (struct BTNode *)malloc(sizeof(struct BTNode));
    
    pA->data = 'A';
    pB->data = 'B';
    pC->data = 'C';
    pD->data = 'D';
    pE->data = 'E';
    
    pA->pLchild = pB;
    pA->pRchild = pC;
    pB->pLchild = pB->pRchild = NULL;
    pC->pLchild = pD;
    pC->pRchild = NULL;
    pD->pLchild = NULL;
    pD->pRchild = pE;
    pE->pLchild = pE->pRchild = NULL;
    
    return pA;
}

void PreTraverseBTree(struct BTNode* pT)
{
    /*
     伪算法
     先访问根节点
     再先序访问左子树
     在先序访问右子树
     */
    if (NULL != pT) {
        printf("%c\n",pT->data);
        
        if (NULL != pT->pLchild) {
            PreTraverseBTree(pT->pLchild);
        }
        
        PreTraverseBTree(pT->pRchild);
    }
}