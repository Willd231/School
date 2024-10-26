#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
typedef struct node{
    char data;
    struct node * next;
}node;


node * createnewnode(char data){
    node * newnode = (node*)malloc(sizeof(node));
    newnode -> data = data;
    newnode -> next = NULL;
    return newnode;
}

void push(char data){

    
}

char pop(){


}