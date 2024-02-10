#include "stack.h"
#include<stdlib.h>
#include<assert.h>

void Push(Node * top,ElementType data)
{
    Node temp = (Node)malloc(sizeof(struct node));
    assert(temp!=NULL);
    temp -> data = data;
    if(*top==NULL)
    {
        * top = temp ;
        (* top) -> next = NULL;
        
    }
    else 
    {
        temp -> next = *top;
        *top = temp;
    }
}
int Size(Node * top)
{
    int cnt = 0;
    Node temp = * top;
    while(temp != NULL)
    {
        cnt++;
        temp = temp -> next ;
    }
    return cnt;
}
ElementType Pop(Node * top)
{
    if(*top==NULL)
    {
        printf("List is aldready Empty");
        exit(1);
    }
    Node temp = * top;
    ElementType val;
    val = temp -> data;
    * top = (* top) -> next ;
    temp = NULL;
    return val;
}
int isEmpty(Node * top)
{
    if(* top == NULL)
    return 1;
    return 0;
}
ElementType Top(Node * top)
{
    if(*top==NULL)
    {
        printf("Empty Stack");
        exit(1);
    }
    return (*top)->data;
}