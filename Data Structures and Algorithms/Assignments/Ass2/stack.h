#ifndef STACK_H
#define STACK_H

// typedef int ElementType;
typedef long long   ElementType;
typedef struct node *Node;
struct node
{
    ElementType data;
    Node next;
};
void Push(Node * top,ElementType data);
ElementType  Pop(Node * top);
int Size(Node * top);
int isEmpty(Node  * top);
ElementType Top(Node * top);

#endif