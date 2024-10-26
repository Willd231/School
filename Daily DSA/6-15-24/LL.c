#include <stdio.h> 
#include <stdlib.h>

typedef struct node{
    int data;
    struct node * next;
}node;

node * createnewnode(int data){
    node * newnode = (node*)malloc(sizeof(node));
    newnode -> data = data;
    newnode -> next = NULL;
    return newnode;
}

void  addnodetofront(node ** head, int data){
node * newnode = createnewnode(data);
newnode -> next = *head;
*head = newnode; 

}

void addnodetoback(node ** head, int data){
node * newnode = createnewnode(data); 
if(*head == NULL){
    newnode -> next = *head;
    head = newnode; 
}
    node * temp = *head; 
    while(temp->next != NULL){
        temp = temp->next; 
    }
    //remember its the next one not the one at the end, we are making a new one 
    temp->next = newnode; 
}

void deletenode(node**head, int data){

    node * temp = *head; 
    node * prev = NULL; 

}

