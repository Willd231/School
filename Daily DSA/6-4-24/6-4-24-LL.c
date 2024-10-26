/*#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data; 
    struct node * next ;
}node;


node * createnewnode(int data){
node * newnode = (node*)malloc(sizeof(node)); 
newnode -> data = data; 
newnode->next = NULL; 
return newnode; 
}

void addnodetobeg(node**head, int data){
    node * newnode = createnewnode(data); 
    newnode -> next = *head; 
    *head = newnode; 

}

void insertatend(node**head, int data){
    node * newnode = createnewnode(data);
    if(*head == NULL){
        *head = newnode; 
        return;
    }
    node*temp = *head; 
    while(temp->next != NULL){
        temp = temp->next; 
    }
    temp->next = newnode;  
}
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node { 
    int data; 
    struct node * next; 
}node;


node * createNewNode(int data){

    node*newnode = (node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;


}

void addnodetobeginning(node**head, int data){

    node*newnode = createNewNode(data);
    newnode->next= *head; 
    *head = newnode ; 
}


void addnodetoend(node **){
    
}




