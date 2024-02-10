#include "queue.h"
#include<stdlib.h>
#include<assert.h>
#include<stdio.h>

ElementType Dequeue(Queue q)
{
  if(q->rear == NULL)
  {
    printf("Queue is Empty");
    exit(1);
  }
  int val ;
  Node temp = q->front;
  val = temp -> data;
  q->front = q-> front -> next;
  free(temp );
  temp  = NULL;
  return val;
}
void Enqueue(Queue q,int x)
{
  Node temp = (Node)malloc(sizeof(struct node));
  assert(temp!=NULL);
  temp -> next = NULL;
  temp -> data = x;
  if(q->front == NULL) q->front = temp;
  if(q->rear!=NULL) q->rear -> next = temp;
  q->rear = temp;
}
int Size(Queue q)
{
   int cnt = 0;
   Node temp = q->front ;
   while(temp!= NULL)
   {
     cnt++;
     temp = temp -> next;
   }
   return cnt ;
}
int isEmpty(Queue q)
{
  if(Size(q)==0)
  {
    return 1;
  }
  return 0;
}
ElementType Front(Queue q)
{
  if(q->front==NULL)
  {
    printf("Empty queue");
    exit(1);
  }
  return q->front ->data;
}