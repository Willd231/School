/*#include <stdio.h>
#include <stdlib.h> 
#define SIZE 50

typedef struct node{
    char data; 
    struct node * next; 
}node;

node * top = NULL; 


node*createnode(int data){
    node*newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;

}


void push(char data){
node * newnode = createnode(data); 
newnode->next = top; 
top = newnode; 
}

char pop(){
    if(top == NULL){
        printf("Stack is empty");
        return -1; 
    }
    char popped_result = top -> data; 
    node *temp = top; 
    top = top->next;
    free(temp);
    return popped_result; 


}

int isempty(){
    return top == NULL ? 1:0; 
}

*/



#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 50

typedef struct node{
    char data; 
    struct node * next;
}node;

node * top = NULL;

node * createnewnode(char data){
node * newnode = (node*)malloc(sizeof(node));
newnode -> data = data;
newnode -> next = NULL;
return newnode; 

}


void push(char data){
node * newnode = createnewnode(data); 
newnode -> next = top; 
top = newnode; 
}

char pop(){
if(top == NULL){
    printf("Stack is Empty");
    return -1;
}
char popped = top->data; 
node * temp = top; 
top = top->next

}

int isempty(){
    return top == NULL ? 1:0; 
}

int main(){



}