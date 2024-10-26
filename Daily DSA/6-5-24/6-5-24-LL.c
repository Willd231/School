#include <stdlib.h>
#include <stdio.h>

typedef struct node{

    int data; 
    node * next;
}node;

node * createnewnode(int data){
    node * newnode = (node*)malloc(sizeof(node)); 
    newnode->data = data;
    newnode->next=NULL;
    return newnode;
}

void addnodetofront(node**head, int data){
    node * newnode = createnewnode(data);
    newnode->next = *head;
    *head = newnode; 

}

void addnodetoback(node**head, int data){
    node * newnode = createnewnode(data);
    while(newnode->next!=NULL){
        newnode->next = next;
    }
}