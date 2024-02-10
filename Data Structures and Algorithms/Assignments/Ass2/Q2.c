#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef long long ll;
typedef struct node * Node ;
typedef long long ElementType ;
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

void PushBack(Dequeue q,ElementType x)
{
  Node temp = (Node)malloc(sizeof(struct node));
  assert(temp!=NULL);
  temp -> next = NULL;
  temp -> data = x;
  if(q->front == NULL) q->front = temp;
  if(q->rear!=NULL) q->rear -> next = temp;
  q->rear = temp;
}
void PushFront(Dequeue q,ElementType x)
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
  ElementType val ;
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
  ElementType val ;
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
ElementType Size(Dequeue q)
{
    ElementType cnt = 0;
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
int main()
{
    Dequeue q = (Dequeue)malloc(sizeof(struct dequeue));
    q->front = NULL;
    q->rear = NULL;
    Dequeue q1 = (Dequeue)malloc(sizeof(struct dequeue));
    q1->front = NULL;
    q1->rear = NULL;
    ll n,m;
    scanf("%lld %lld",&n,&m);
    ll v,c=0;
    scanf("%lld",&v);
    PushBack(q,v);
    PushBack(q1,1);
    if(m==1)
    {
      c = 1;
      printf("%lld ",Front(q));
    }
    for(ll i=2;i<=n;++i)
    {
        scanf("%lld",&v);
        if(Back(q)<=v)
        {
            PushBack(q,v);
            PushBack(q1,i);
        }
        else 
        {
            while(!isEmpty(q)&&Back(q)>v)
            {
                PopBack(q);
                PopBack(q1);
            }
            PushBack(q,v);
            PushBack(q1,i);
        }
        if(i==m)
        {
            c = 1;
            printf("%lld ",Front(q));
        }
        if(c&&i>m)
        {
            while(Front(q1) == i-m)
            {
                PopFront(q);
                PopFront(q1);
            }
            printf("%lld ",Front(q));
        }
    }
    printf("\n");
    return 0;
}