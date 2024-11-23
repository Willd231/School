#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int data; 
    struct node * next;
    struct node * prev;
}node; 

//so i dont have to intiailize it each time plus its good to have a global head 
node * head = NULL;

node * createnewnode(int data){
    node * newnode = malloc(sizeof(node));
    newnode -> data = data;
    newnode ->next = NULL;
    return newnode; 
}

void push(int data){
//create new node at beginning
node * newnode = createnewnode(data);
newnode -> next = head;
head = newnode;
}




int pop(){
    
    if(head == NULL){
        printf("stack is empty");
        return(0);
    }
    else{
        node * temp = head;
        int data = head -> data; 
        head = head->next;
        free(temp);
        return data;
    }
    
}




int main(){

    push(10);
    int n = pop();
    printf("%d", n);
    
}