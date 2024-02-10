#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef long long ll;
typedef long long  ElementType;
typedef struct node *Node;
struct node
{
    ElementType data;
    Node next;
};

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

int main()
{
    int n,ch=0;scanf("%d",&n);
    int h[n];
    ll sum = 0;
    Node top = NULL;
    for(int i=0;i<n;++i)
    {
        scanf("%d",&h[i]);
    }
    for(int i=0;i<n;++i)
    {
        ch = 0;
        if(top==NULL)
        {
            Push(&top,i);
        }
        else if(h[Top(&top)]>h[i])
        {
            sum += i-Top(&top)+1;
            Push(&top,i);
        }
        while(top!=NULL&&h[Top(&top)]<h[i])
        {
            ch = 1;
            sum += i-Top(&top)+1;
            Pop(&top);
        }
        if(ch==1)
        {
            if(top!=NULL)
            sum += i-Top(&top) + 1;
            Push(&top,i);
        }
    }
    printf("%lld",sum);
    return 0;
}