/* #include <stdio.h> 
#include <stdlib.h>

typedef struct node{
char data;
struct node * next;
}node;

node * createnewnode(char data){
    node * newnode = (node*)malloc(sizeof(node));
    newnode->data = data; 
    newnode -> next = NULL; 

    return newnode;
}


void addnodetohead(node ** head, char data){

    node * newnode = createnewnode(data); 

    if(head == NULL){
        printf("list is empty");
        return -1;
    }

    newnode->next = *head;
    *head = newnode; 


}


void addnodetoend(node ** head, char data){
    node * newnode = createnewnode(data); 

    if(*head ==NULL){
        newnode->next = head; 
        *head = newnode; 

    }

    node * temp = *head; 
    while(temp->next != NULL){
        temp = temp -> next; 

    }
    temp -> next = newnode; 

}




#include <stdio.h> 
#include <stdlib.h>

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

void addnodetofront(node ** head, char data){

    node * newnode = createnewnode(data);
    
    newnode -> next = *head;
    *head = newnode;

}

void addnodetoend( node ** head, char data){
    node * newnode = createnewnode(data);

   

    node * temp = *head; 

    while(temp -> next != NULL){
        temp = temp->next;
    }
    temp ->next = newnode; 
}
*/



#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    char data;
    struct node * next;
}node;

node * createnewnnode(char data){
    node * newnode = (node*)malloc(sizeof(node));
    newnode -> next = NULL;
    newnode -> data = data; 
    return newnode;
}


void addnodetotop(node ** head, char data){
    node * newnode = createnewnode(data);
    newnode -> next = *head;
    *head = newnode; 
}

void addnodetoend(node ** head, char data){
    node * newnode = createnewnode(data); 

    if (*head == NULL){
        newnode -> next = *head;
        *head = newnode;
    }

    node * temp = head;
    while(temp!= NULL){
        temp = temp->next;
    }
    temp -> next = newnode; 
}


int main(){

addnodetoend(1, 'r'); 



}