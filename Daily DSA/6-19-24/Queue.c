#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char songname[20];
    struct node * next;
}node;

node * createnewnode(char songname[20]){
    node * newnode = (node*)malloc(sizeof(node));
    newnode ->songname[20] = songname[20];
    newnode -> next = NULL;
    return newnode;
}

void enqueue(node**head, char songname[20]){
    node * newnode = createnewnode(songname[20]); 
    node * temp = *head; 

    if(*head == NULL){
        newnode->next = *head;
        *head = newnode;
    }
    while(temp!=NULL){
        temp = temp->next;
    }
    temp -> next = newnode; 
}

void dequeue(node**head, char songname[20]){
    //not sure what to dequeue at the moment so im moving on
}