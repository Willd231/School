#include <stdio.h>
#include <stdlib.h> 
#define MAX_SIZE 50

typedef struct node{
    char data; 
    node * next;
}node; 

node *top = NULL;

node * createnewnode(char data){
node*newnode = (node*)malloc(sizeof(node)); 
newnode->data = data; 
newnode->next = NULL; 
return newnode; 
}




void push(char data){
node *newnode = createnewnode(data);
    newnode->next = top;
    top = newnode;
}

char pop(){
 if (top == NULL) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    char popped_data = top->data;
    node *temp = top;
    top = top->next;
    free(temp);
    return popped_data;
}


int isempty(){
    return top == NULL ? 1:0; 
}

int main(){
    char temp[50];
    FILE *fp = fopen("input.txt", "r");
    for(int i = 0; i<MAX_SIZE; i++){
    fscanf(fp, "%c", temp[i]);
    if(temp[i] == '{' || temp[i] == '(' || temp[i] == '['){
    push(temp[i]); 
    }
    }

    fclose(fp); 


    for (int i = 0; i<MAX_SIZE; i++){
        if(temp[i] == '}' || temp[i] == ']' || temp[i] == ')'){
            if(isempty()){
                printf("Mismatched");
                return -1; 
            } 
            char popped = pop(); 

            if(temp[i] =='(' && popped != ')' || 
            temp[i] == '[' && popped != ']' || 
            temp[i] == '{' && popped != '}') {
                printf("Mismatched"); 
                return -1; 
            }
        }

    }
    if(!isempty()){
        printf("Mismatched");
        return -1; 

    }

    printf("Matched"); 



    return 0 ;
}