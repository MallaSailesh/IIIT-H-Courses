#include "heap.h"
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void swap(int *x,int *y)
{
    int temp = *x ;
    *x = *y;
    *y = temp;
}
MinHeap createheap(int capacity)
{
    MinHeap mh = (MinHeap)malloc(sizeof(struct MinHeap));
    mh->capacity = capacity;
    mh->heap_size = 0;
    mh->harr = (int *)malloc(sizeof(int)*capacity);
}
int parent(int i)
{
    return (i-1)/2; // indexes are 0,1,2,-- in level order wise
}
int left(int i)
{
    return 2*i + 1;
}
int right(int i)
{
    return 2*i+2;
}
MinHeap extractMin(MinHeap mh)
{
    if((mh -> heap_size) <= 0)
    {
       printf("Heap is Empty");
       return mh;                 
    }
    if((mh -> heap_size) == 1)
    {
        (mh -> heap_size) --;
        printf("%d\n",(mh -> harr[0]));
        return mh;
    }
    // printf("%d\n",(mh -> harr[0]));
    mh -> harr[0] = mh->harr[--(mh->heap_size)];
    mh = MinHeapify(mh,0);
    return mh;
}
MinHeap MinHeapify(MinHeap mh , int i)
{
  int l = left(i);
  int r = right(i);
  int smallest = i;
  if(l < (mh -> heap_size) && (mh->harr[smallest]) > (mh -> harr[l]))
  smallest = l;
  if(r < (mh -> heap_size) && (mh->harr[smallest]) > (mh -> harr[r]))
  smallest = r;
  if(smallest != i)
  {
      swap(&(mh->harr[smallest]),&(mh->harr[i]));
      mh = MinHeapify(mh,smallest);
  }
  return mh ;
}
MinHeap insertkey(MinHeap  mh , int k)
{
    if((mh->heap_size) == mh->capacity)
    {
        printf("HeapArrray is full");
        return mh;                                    
    }
    mh->harr[mh->heap_size] = k;
    int i = mh->heap_size;
    (mh -> heap_size)++;
    while(i!=0 && (mh->harr[parent(i)]) > (mh ->harr[i]))
    {
        swap(&(mh->harr[parent(i)]),&(mh ->harr[i]));
        i = parent(i);
    }
    return mh ;
}
MinHeap decreaseKey(MinHeap mh , int k, int i)
{
    if(i>(mh->heap_size))
    {
        printf("index greater then heap size");
        return mh;
    }
    (mh -> harr[i]) = k;
    while(parent(i)!=0 &&  (mh->harr[parent(i)]) > (mh ->harr[i]))
    {
        swap(&(mh->harr[parent(i)]),&(mh ->harr[i]));
        i = parent(i);
    }
    return mh;
}
MinHeap deleteKey(MinHeap mh ,int i)
{
   decreaseKey(mh,INT_MIN,i);
   extractMin(mh);
}
void print(MinHeap mh)
{
    for(int i=0;i<(mh->heap_size);++i)
    {
        printf("%d ",mh->harr[i]);
    }
    printf("\n");
}
