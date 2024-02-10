#ifndef _DLL_H
#define _DLL_H
#include "node.h"

struct my_dll
{
    Node head;
    Node tail;
};

struct my_dll * insert(struct my_dll * list , int x);
struct my_dll * insert_at(struct my_dll * list,int x,int i);
struct my_dll * delete(struct my_dll * list , int i);
int find(struct my_dll * list , int x);
int get_size(struct my_dll * list);
void print(struct my_dll * list);
void print_reverse(struct my_dll * list);
struct my_dll * prune(struct my_dll * list);
#endif