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

void addtofront(node**head, int data){
    node * newnode = createnewnode(data);
    newnode ->next = *head;
    *head = newnode; 
}

void addtoback(node **head, int data){
    node * newnode = createnewnode(data);
    if(*head == NULL){
        newnode -> next = *head;
        *head = newnode; 
    }

    node * temp = *head;
    while(temp!=NULL){
        temp = temp->next;
    }
    temp->next = newnode;

}
 
 void deletenode(node**head, int data){
    node * temp = *head;
    node *prev = NULL;
    printf("Enter the node you want to delete");
    scanf("%d", &data);


while(temp ->data != data){
    temp = temp->next; 
}

temp->next = temp ->next->next; 
prev ->next = prev->next->next; 
free(temp);

 }



int main(){
    node *head = NULL;

    addtofront(&head, 1);
    addtofront(&head, 2);
    addtoback(&head, 3);

    printf("List after adding nodes: ");
    node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    deletenode(&head, 2);
    
    printf("List after deleting node with data 2: ");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    // Free the remaining nodes to avoid memory leaks
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}