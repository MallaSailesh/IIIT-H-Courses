#include "dequeue.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void PushBack(Dequeue q,int x)
{
  Node temp = (Node)malloc(sizeof(struct node));
  assert(temp!=NULL);
  temp -> next = NULL;
  temp -> data = x;
  if(q->front == NULL) q->front = temp;
  if(q->rear!=NULL) q->rear -> next = temp;
  q->rear = temp;
}
void PushFront(Dequeue q,int x)
{
  Node temp = (Node)malloc(sizeof(struct node));
  assert(temp!=NULL);
  temp -> next =  q->front;
  temp -> data = x;
  if(q->rear == NULL) q->rear = temp;
  q->front = temp;
}
ElementType PopBack(Dequeue q)
{
  if(q->rear == NULL)
  {
    printf("Queue is Empty");
    exit(1);
  }
  int val ;
  Node temp = q->front;
  if(temp -> next == NULL)
  {
      val = temp -> data;
      free(temp);
      q->rear = NULL;
      q->front = NULL;
      temp = NULL;
      return val;
  }
  while(temp->next->next!=NULL)
  temp  = temp -> next;
  q->rear = temp ;
  val = temp -> next -> data;
  free(temp-> next);
  temp-> next  = NULL;
  return val;
}
ElementType PopFront(Dequeue q)
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
  if(q->front==NULL) q->rear = NULL;
  free(temp);
  temp  = NULL;
  return val;
}
ElementType Front(Dequeue q)
{
  if(q->front==NULL)
  {
    printf("Empty queue");
    exit(1);
  }
  return q->front ->data;
}
ElementType Back(Dequeue q)
{
   if(q->rear == NULL)
   {
       printf("Empty Queue");
       exit(1);
   }
   return q->rear->data;
}
int Size(Dequeue q)
{
    int cnt = 0;
    Node temp = q-> front;
    while(temp != NULL)
    {
        cnt++;
        temp = temp -> next;
    }
    return cnt ;
}
int isEmpty(Dequeue q)
{
    if(q->front == NULL)
    return 1;
    return 0;
}
