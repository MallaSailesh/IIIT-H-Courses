#ifndef QUEUE_H
#define QUEUE_H
#include <stdlib.h>

typedef struct node * Node ;
typedef int ElementType; 
typedef struct queue *Queue;
struct node
{
    ElementType data;
    Node next;
};
struct queue
{
    Node front ;
    Node rear ;
};

ElementType Dequeue(Queue q);
void Enqueue(Queue q,int x);
ElementType Front(Queue q);
int isEmpty(Queue q);
int Size(Queue q);

#endif