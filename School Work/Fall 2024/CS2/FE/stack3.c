#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct node * next; 
}node;


node * head = NULL;

node * createnewnode(int data){
    node * newnode = malloc(sizeof(node));
    newnode ->data = data; 
    
}




int pop(){

}

/*void push(data){
    node * newnode = createnewnode(data); 
    newnode ->next = head;
    head = newnode;

}*/



/*void push(data){
    node * newnode = createnewnode(data);
    newnode -> next = head;
    head = newnode;
}*/





/*void push(data){
    node * newnode = createnewnode(data);
    newnode -> next = head; 
    head = newnode;
}*/



/*
void push(data){
node * newnode = createnewnode(data);
newnode -> next = head; 
head = newnode; 
}

*/
/*
void push(data){
    node * newnode = createnewnode(data);
    newnode -> next = head; 
    head = newnode;
}

*/

/*
void push(data){
    node * newnode = createnewnode(data);
    newnode -> next = head;
    head = newnode; 

}
*/



