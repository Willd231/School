#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct node * next;
}node;

node * head = NULL;


node * createnewnode(int data){
    node * newnode = malloc(sizeof(node));
    newnode -> data = data;
    newnode -> next = NULL;
    return(newnode);
}


void push(int data){
    node * newnode = createnewnode(data); 
    newnode -> next = head;
    head = newnode; 
}

int pop(){
    if(head == NULL){
        printf("stack is empty");
        return(-1);
    }
    else{
        node * temp = head;
        int data = head-> data;
        head = head -> next;
        free(temp);
        return(data); 

    }
}