//
//  main.c
//  MinHeap
//
//  Created by Bharath G M on 9/15/13.
//  Copyright (c) 2013 Bharath G M. All rights reserved.
//

#include <stdio.h>
#include<stdio.h>


void swap(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}



void minHeapify(int a[], int size, int i)
{
    int left = 2*i;
    int right = 2*i+1;
    int smallest = i;
    if(left <size && a[left]<a[smallest])
        smallest = left;
    if(right<size && a[right]<a[smallest])
        smallest  = right;
    if(smallest!=i)
    {
        swap(&a[i],&a[smallest]);
    }
}



void buildMinHeap(int a[], int size)
{
    for(int i=size/2;i>=0;i--)
        minHeapify(a,size,i);
}



int kthLargest(int a[], int size, int k)
{
    int minHeap[k];
    int i;
    for(i=0;i<k;i++)
        minHeap[i] = a[i];
    buildMinHeap(minHeap,k);
    for(i=k;i<size;i++)
        if(a[i]>minHeap[0])
        {
            minHeap[0]=a[i];
            minHeapify(minHeap,k,0);
        }
    return minHeap[0];
}

int main()
{
    int a[] = {0,7,8,4,2,3,5,1};
    int size = sizeof(a)/sizeof(a[0]);
    int k = 2;
    printf("%d ",kthLargest(a,size,k));
    return 0;
}
