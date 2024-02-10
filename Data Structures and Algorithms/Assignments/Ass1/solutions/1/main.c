#include<stdio.h>
#include<stdlib.h>
#include "my_dll.h"
#include<string.h>

int main()
{
    char a[100];
    struct my_dll * list ;
    list = (struct my_dll *)malloc(sizeof(struct my_dll));
    list -> head = NULL;
    list -> tail = NULL;
    while(1)
    {
       scanf("%s",a);
       if(strcmp(a,"print")==0)
       {
           print(list);
       }
       else if(strcmp(a,"print_reverse")==0)
       {
           print_reverse(list);
       }
       else if(strcmp(a,"get_size")==0)
       {
          int c ;
          c = get_size(list); 
          printf("%d\n",c);
       }
       else if(strcmp(a,"prune")==0)
       {
          list = prune(list);
       }
       else if(strcmp(a,"insert")==0)
       {
          int x;
          scanf("%d",&x);
          list = insert(list,x);
       }
       else if(strcmp(a,"insert_at")==0)
       {
          int x,i;
          scanf("%d %d",&x,&i);
          list = insert_at(list,x,i);
       }
       else if(strcmp(a,"delete")==0)
       {
          int i;
          scanf("%d",&i);
          list = delete(list,i);
       }
       else if(strcmp(a,"find")==0)
       {
          int x;
          scanf("%d",&x);
          printf("%d\n",find(list,x));
       }
       else
       {
          printf("Invalid Command");
       }
    }
    return 0;
}