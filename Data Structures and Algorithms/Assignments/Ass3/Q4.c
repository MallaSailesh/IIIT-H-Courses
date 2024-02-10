#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node * Node ;
typedef int ElementType;

struct node
{
    ElementType val;
    Node left;
    Node right;
    int index;
}; 

int preorder(Node root,int array[],int zeroc)
{
    if(root!=NULL)
    {
        array[zeroc++]=root->val;
        root->index=zeroc;
        zeroc = preorder(root->left,array,zeroc);
        zeroc = preorder(root->right,array,zeroc);
    }
    return zeroc ;
}

Node * tnode;

int main()
{
    int n,zeroc = 0;
    scanf("%d",&n);
    tnode=(Node *)malloc(n*sizeof(Node));
    
    for(int i=0;i<n;i++)
    tnode[i]=(Node)malloc(sizeof(struct node));
    
    char string1[n];
    scanf("%s",string1);

    for(int i=0;i<n;i++)
    {
        tnode[i]->val = i;
        tnode[i]->left=NULL;
        tnode[i]->right=NULL;
    }

    for(int i=1;i<n;i++)
    {
        int a,b,c;
        scanf("%d %d %d\n",&a,&b,&c);
        if(c==1)
        tnode[a-1]->left=tnode[b-1];
        else
        tnode[a-1]->right=tnode[b-1];
    }
    int array[n],query;
    char string2[1000000] , string3[n]; 
    scanf("%s",string2);
    scanf("%d",&query);
    preorder(tnode[0],array,zeroc);
    
    for(int i=0;i<n;++i)
         string3[i] = string1[array[i]];
    
    while(query)
    {
        int t;
        scanf("%d",&t);

        if(t==1)
        {
            int i;
            char c;
            scanf("%d %c",&i,&c);
            string1[i-1] = c;
            string3[(tnode[i-1]->index)-1] = c;
        }
        else
        {
            int l,r,i;
            scanf("%d %d %d",&l,&r,&i);
            
            if(strncmp(&string3[(tnode[i-1]->index)-1],&string2[l-1],r-l+1)!=0)
            printf("NO\n");
            else
            printf("YES\n");
        }
        query--;
    }

    return 0;

}