#ifndef _HEAP_H
#define _HEAP_H

typedef struct MinHeap * MinHeap;

struct MinHeap{
    int capacity;//capacity of the heap
    intheap_size;//tells the current size of the heap
    int * harr;//pointer to the array of elements in the heap
};

void swap(int * x,int * y);
MinHeap createheap(int capacity);
int parent(int i);//gives the index of the parent 
int left(int i); //gives the index of the left child 
int right(int i);
MinHeap extractMin(MinHeap mh);// method to remove min element in the heap 
MinHeap MinHeapify(MinHeap mh , int i);// method to sort the heap
MinHeap insertkey(MinHeap mh , int k);
MinHeap decreaseKey(MinHeap mh , int k, int i);// decreasing the value of the key at index i
MinHeap deleteKey(MinHeap mh, int i);
void print(MinHeap mh);
#endif