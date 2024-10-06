/*2) (10 pts) DSN (Linked Lists)
The structure of each node of a singly linked list is shown below.*/

#include <stdio.h>
#include <stdlib.h>
typedef struct node {
 int data;
 struct node* next;
} node;
/*Write a function insertAfterN, that takes the head of a linked list, and two integers M and N (M ≠ N) and
inserts M after all the nodes containing N.
For example, if M = 200 and N = 6, the linked list 3, 6, 4, 6, 6, 5 will be changed to 3, 6, 200, 4, 6, 200,
6, 200, 5.*/


void insertAfterN(node* head, int M, int N) {

    if(head ==NULL){
        return;
    }
    
    node * temp = head;
    while(temp->next != NULL){
    if(temp->data = N){
    node * newnode = (node*)malloc(sizeof(node));
    newnode->data = M;
    newnode -> next = NULL;
    temp->next = newnode;
            
        }
    }
    

   
}

//conclusion: 4/6 pretty freaking good, just i made an infin loop and should called it recursively also didnt link properly
