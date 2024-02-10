#ifndef _DQUEUE_H
#define _DQUEUE_H
typedef struct node * Node ;
typedef int ElementType ;
typedef struct dequeue * Dequeue;
struct node 
{
    Node next  ;
    ElementType data;
};
struct dequeue
{
    Node front ;
    Node rear;
};

ElementType PopFront(Dequeue q);
ElementType PopBack(Dequeue q);
void PushFront(Dequeue q,int x);
void PushBack(Dequeue q,int x);
ElementType Front(Dequeue q);
ElementType Back(Dequeue q);
int isEmpty(Dequeue q);
int Size(Dequeue q);
#endif