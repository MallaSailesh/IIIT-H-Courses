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
        return -1;
    }
    return (*top)->data;
}

int max(int a,int b)
{
    return (a>b)?a:b;
}
int min(int a,int b)
{
    return (a<b)?a:b;
}
int main()
{
    Node top = NULL;
    int n,m,maxv=0,height=1e9,width,a[1001][1001];
    char b[1001][1001];
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;++i)
    {
        scanf("%s",b[i]);
        for(int j=0;j<m;++j)
        {
            if(b[i][j]=='.') a[i][j] = 1;
            else a[i][j] = 0;
        }
    }
    for(int i=1;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(a[i][j]!=0) 
            a[i][j] = a[i-1][j] + a[i][j];
        }
    }
    for(int k=0;k<n;++k)
    {
        int i = 0;
        while(i<m)
        {
            if(isEmpty(&top)||a[k][i]>=a[k][Top(&top)])
            Push(&top,i++);
            else
            { 
               int index = Pop(&top);
               if(isEmpty(&top))
               maxv = max(maxv,a[k][index]*i);
               else
               maxv = max(maxv,a[k][index]*(i-Top(&top)-1));
            }
        }
        while(!isEmpty(&top))
        {
            int index = Pop(&top);
            if(isEmpty(&top))
            maxv = max(maxv,a[k][index]*i);
            else
            maxv = max(maxv,a[k][index]*(i-Top(&top)-1));
        }
    }
    printf("%d\n",maxv);
    return 0;
}