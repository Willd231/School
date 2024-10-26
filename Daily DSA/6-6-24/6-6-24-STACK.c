//gonna make this perform infix to post fix using file manipulation and strcmp
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data; 
    node * next; 
}node; 

node * createnewnode(int data){
    node * newnode = (node *)malloc(sizeof(node)); 
    newnode -> data = data; 
    newnode ->next = NULL; 
}

void push(node**head, int data){

}



int pop(){
     
}