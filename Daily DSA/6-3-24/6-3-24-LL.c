#include <stdio.h>
#include <stdlib.h> 

typedef struct node{
    int data; 
    struct node * next; 
}node;

node * addnodetobeg(int data){
    node * newnode = (*node)malloc (sizeof(node));
    newnode->data = data;
    newnode->next = NULL; 
    *head = data; 
    return newnode; 
}