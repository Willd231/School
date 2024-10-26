#include <stdio.h>
#include <stdlib.h> 

typedef struct node{
    int data; 
    struct node * next;
}node; 

node * createnewnode(int data){

node * newnode = (node*)malloc(sizeof(node)); 
newnode->data= data;
newnode->next=NULL;
return newnode; 
}

void addtofront(node**head, int data){
    node * newnode = createnewnode(data); 
    newnode->next = *head; 
    *head = newnode; 
}

void addtoback(node**head, int data){
    node * newnode = createnewnode(data); 
    if(*head == NULL){
        newnode->next = *head;
        *head = newnode; 
    }
    node * temp = *head; 
    while(temp->next!=NULL ){
        temp = temp->next; 
    }
    temp->next = newnode; 
}

void deletenode(node**head, int data){ 
    node*temp = *head;
    node*prev = NULL;

    if( temp->next !=NULL && temp->data = data){
        *head = temp->next;  
        free(temp);
        return; 

    }
    while(temp!=NULL && temp->data!= data){
        prev = temp;
        temp = temp->next; 
    }
    if(temp = NULL){
        return; 
    }
    prev -> next = temp->next; 
    free(temp); 
} 

void printlist(node*head){

}