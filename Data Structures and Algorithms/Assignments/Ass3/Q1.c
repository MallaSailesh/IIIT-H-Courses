#include <stdio.h>
#include <stdlib.h>
#include<assert.h>

int max(int a, int b)
{
    return (a>b)?a:b;
}
int min(int a, int b)
{
    return (a<b)?a:b;
}

int finalvalue=__INT32_MAX__;

typedef struct tnode * Tnode ;
struct tnode 
{
    int data;
    Tnode left;
    Tnode right;
    int sumv;
    int checkBSTa;
    int checkBSTd;
    int minv;
    int maxv;
};

typedef struct node * Node ;
typedef Tnode ElementType; 
typedef struct queue *Queue;
typedef struct tree * Tree ;

typedef struct tree * Tree;

struct tree 
{
    Node root;
    int size;
};
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


ElementType Dequeue(Queue q)
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
  free(temp);
  temp  = NULL;
  return val;
}
void Enqueue(Queue q,Tnode x)
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
    return NULL;
  }
  return q->front ->data;
}

Tnode minnoise(Tnode root)
{
   if(root==NULL) return NULL;
   minnoise(root->left);
   minnoise(root->right);
   if(root->left!=NULL&&root->right!=NULL)
   {
     root -> checkBSTa = 0;
     root -> checkBSTd = 0;
     if(root->right->checkBSTa == 1&&root->left->checkBSTa==1&&root->right->minv>root->data&&root->left->maxv<root->data)
     root -> checkBSTa = 1;
     if(root->right->checkBSTd == 1&&root->left->checkBSTd==1&&root->right->maxv<root->data&&root->left->minv>root->data)
     root -> checkBSTd = 1;
     root -> sumv = (root->data) + (root->right->sumv) + (root->left->sumv);
     root -> minv = min(root->data,root->right->minv);
     root -> minv = min(root->minv,root->left->minv);
     root -> maxv = max(root->data,root->right->maxv);
     root -> maxv = max(root->maxv,root->left->maxv);
   }
   else if(root->right != NULL)
   {
     root->checkBSTa = 0;
     root->checkBSTd = 0;
     if(root->right->checkBSTa==1 && root->data < root->right->minv)
     root -> checkBSTa = 1;
     if(root->right->checkBSTd==1 && root->right->maxv < root -> data)
     root -> checkBSTd = 1;
     root->sumv = root->data + (root->right->sumv);
     root->minv = min(root->data,root->right->minv);
     root->maxv = max(root->data,root->right->maxv);
   }
   else if(root -> left != NULL)
   {
     root -> checkBSTa = 0;
     root -> checkBSTd = 0;
     if(root->left->checkBSTa == 1 && root->data > root->left->maxv)
     root ->checkBSTa = 1;
     if(root->left->checkBSTd == 1 && root->data < root->left->minv)
     root -> checkBSTd = 1;
     root->sumv = root->data + root->left->sumv;
     root->minv = min(root->left->minv,root->data);
     root->maxv = max(root->left->maxv,root->data);
   } 
   else
   {
     root->sumv = root->data;
     root->minv = root->data;
     root->maxv = root->data;
     root->checkBSTa = 1;
     root->checkBSTd = 1;
   }
   if(root -> checkBSTa)
   finalvalue = min(finalvalue,root->sumv);
   if(root->checkBSTd)
   finalvalue = min(finalvalue,root->sumv);
}

int main()
{
  int testcases;
  scanf("%d",&testcases);
  for(int i=0;i<testcases;++i)
  {
    finalvalue = 1e9;
    Queue q = (Queue)malloc(sizeof(struct queue));
    q->front = NULL;
    q->rear = NULL;
    Tnode root = NULL;
    int n;
    scanf("%d",&n);
    int array[n];
    for (int i = 0; i < n; i++)
    scanf("%d", &array[i]);
    root=(Tnode)malloc(sizeof(struct tnode));
    root->data = array[0];
    root->left = NULL;
    root -> right = NULL;
    Enqueue(q,root); 
    int ch = 0;
    for(int i=1;i<n;++i)
    {
      ch++;
      if(array[i]!=0)
      {
        Tnode temp = (Tnode)malloc(sizeof(struct tnode));
        temp -> data = array[i];
        temp -> left = NULL;
        temp -> right = NULL;
        Tnode parent = Front(q);
        if(ch == 1)
        parent -> left = temp;
        else 
        parent -> right = temp ;
        Enqueue(q,temp);
      }
      if(ch == 2)
      {
        Dequeue(q);
        ch = 0;
      }
    }
    minnoise(root);
    printf("%d\n",finalvalue);
  }
}