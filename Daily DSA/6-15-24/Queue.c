#include <stdio.h>
#include <stdlib.h>

typedef struct node{
int data; 
struct node * next; 

}node;

node * createnewnode(int data){
    node * newnode = (node*)malloc(sizeof(node));
    newnode -> data = data;
    newnode ->next = NULL; 

}

void enqueue(node ** head, int data){

}

void dequeue(node ** head, int data){
    
}
