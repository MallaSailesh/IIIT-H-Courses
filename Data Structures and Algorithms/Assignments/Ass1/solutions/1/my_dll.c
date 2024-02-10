#include "my_dll.h"
#include<stdio.h>
#include<stdlib.h>

struct my_dll * insert(struct my_dll * list , int x)
{
    Node temp = (Node)malloc(sizeof(struct node));
    temp -> data = x;
    temp -> next = NULL;
    if(list->head == NULL)
    {
        list -> head = temp;
        temp -> prev = NULL;
        list -> tail = temp ;
    }
    else
    {
        list -> tail -> next = temp ;
        temp -> prev = list -> tail;
        list -> tail = temp;
    }
    return list ;
}
struct my_dll * insert_at(struct my_dll * list,int x,int i)
{
    Node temp = (Node)malloc(sizeof(struct node));
    temp -> data = x;
    Node ptr = list -> head;
    if(i==0)
    {
        temp -> next = list -> head ;
        temp -> prev = NULL;
        if(list->head !=NULL)
        list -> head -> prev = temp;
        else
        list -> tail = temp;
        list -> head = temp;
    }
    else if(i==get_size(list))
    {
        temp -> next = NULL;
        temp -> prev = list -> tail;
        list -> tail -> next = temp;
        list -> tail = temp;
    }
    else
    {
        while(i>1)
        {
            ptr = ptr -> next;
            i--;
        }
        temp-> prev = ptr ;
        temp -> next = ptr -> next ;
        temp -> next -> prev = temp;
        ptr -> next = temp;
    }
    return list;
}
struct my_dll * delete(struct my_dll * list , int i)
{
    Node temp = list -> head ;
    if(i==0)
    {
        list->head = temp->next;
        if(list->head!=NULL)
        list -> head ->prev = NULL;
        else 
        list -> tail = NULL;
        free(temp);
        temp = NULL;
    }
    else if(i==get_size(list)-1)
    {
        list -> tail = list -> tail -> prev ;
        free(list->tail->next);
        list->tail->next = NULL;
    }
    else
    {
        Node temp2 ;
        while(i>1)
        {
            temp = temp -> next;
            i--;
        }
        temp2 = temp -> next ;
        temp2->next -> prev  = temp ;
        temp -> next = temp2 -> next;
        free(temp2);
        temp2 = NULL;
    }
    return list;
}
int find(struct my_dll * list , int x)
{
   Node temp = list -> head ;
   int c = 0,d=0;
   while(temp!=NULL)
   {
       if(temp -> data != x)
       {
           c++;
       }
       else 
       {
           d = 1;
           break;
       }
       temp = temp -> next ;
   }
   if(d == 0)
   return -1 ;
   else 
   return c;
}
int get_size(struct my_dll * list)
{
   Node temp = list ->head;
   int cnt = 0;
   while(temp != NULL)
   {
       cnt++;
       temp = temp -> next;
   }
   return cnt;
}
void print(struct my_dll * list)
{
   Node temp = list -> head ;
   while(temp !=NULL)
   {
       printf("%d ",temp->data);
       temp = temp -> next;
   }
}
void print_reverse(struct my_dll * list)
{
   Node temp = list -> tail;
   while(temp != NULL)
   {
       printf("%d ",temp->data);
       temp = temp -> prev;
   }
}
struct my_dll * prune(struct my_dll * list)
{
   int  c = 1,d=get_size(list);
   d = d/2;
   while(d)
   {
      list = delete(list,c);
      d--;
      c+=1;
   }
}