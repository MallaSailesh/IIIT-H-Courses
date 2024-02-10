#include<stdio.h>
#include<math.h>
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

ll max (ll a ,ll b)
{
    return (a>b)?a:b;
}
ll min(ll a,ll b)
{
    return (a<b)?a:b;
}
ll gcd(ll a,ll b)
{
    if(b)
    {
        return gcd(b,a%b);
    }
    return a;
}
ll lcm(ll a,ll b)
{
    return (a*b)/gcd(a,b); 
}
int main()
{
    int n;scanf("%d",&n);
    Node top = NULL;
    Node top1 = NULL;
    for(int i=0;i<n;++i) 
    {
        ll k;
        scanf("%lld",&k);
        Push(&top,k);
    }
    int size = Size(&top);
    while(size>1)
    {
        if(gcd(Top(&top),Top(&(top->next)))>1)
        {
            ll val1 = Pop(&top);
            size--;
            ll val2 = Pop(&top);
            Push(&top,lcm(val1,val2));
            if(Size(&top1)!=0)
            {
                Push(&top,Pop(&top1));
                size++;
            }
        }
        else 
        {
            ll  val3 = Pop(&top);
            Push(&top1,val3);
            size--;
        }
    }
    printf("%d\n",Size(&top)+Size(&top1));
    printf("%lld ",Pop(&top));
    while(Size(&top1)!=0)
    {
        printf("%lld ",Pop(&top1));
    }
    printf("\n");
    return 0;
}