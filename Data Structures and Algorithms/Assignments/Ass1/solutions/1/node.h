#ifndef NODE_H
#define NODE_H

typedef struct node * Node;

struct node
{
    int data;
    Node prev;
    Node next;
};

#endif