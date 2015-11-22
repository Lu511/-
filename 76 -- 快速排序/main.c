//
//  main.c
//  76 -- 快速排序
//
//  Created by 911 on 15/11/10.
//  Copyright (c) 2015年 911. All rights reserved.
//

#include <stdio.h>

void QuickSort(int * ,int ,int );
int FindPos(int * ,int ,int );

int main ()
{
    int a[6] = {2,1,0,5,4,3};
    int i;
    
    QuickSort(a, 0, 5); // 第二个参数表示第一个元素的下标、第三个参数表示最后一个元素的下标
    
    for (i = 0; i < 6; ++i) {
        printf("%d ",a[i]);
    }
    printf("\n");
    
    return 0;
}

void QuickSort(int * a,int low,int high)
{
    int pos;
    
    if (low < high) {
        pos = FindPos(a,low,high);
        QuickSort(a, low, pos - 1);
        QuickSort(a, pos + 1, high);
    }
}

int FindPos(int * a,int low,int high)
{
    int val = a[low];
    
    while (low < a[low]) {
        while (low < high && a[high] >= val) {
            -- high;
        }
        a[low] = a[high];
        
        while (low < high && a[low] <= val) {
            ++ low;
        }
        a[high] = a[low];
    } // 终止while循环之后low和high一定是相等的
    a[low] = val;
    
    return high; // high可以改为low，等不能改为val、a[low]、a[high]
}
