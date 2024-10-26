/*Fall 2020 Data Structures Exam, Part A
Page 3 of 4
2) (10 pts) ALG (Linked Lists)
Suppose we have a queue implemented as a doubly linked list using the structures shown below. Use
head for the front of the queue and tail for the end of the queue.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
 int data;
 struct node* next, *prev;
}node;

typedef struct queue {
int size;
struct node *head, *tail;
}queue;
/*
Write a dequeue function for this queue. If the queue is NULL or is already empty, return 0 and take no
other action. If the queue isn't empty, dequeue the appropriate value, make the necessary adjustments, and
return the dequeued value. (Note: You must free the node that previously stored the dequeued value.)*/


int dequeue(queue *thisQ) {
    if(thisQ->size==0){
        return 0;
    }
    if(thisQ == NULL){
        return 0;
    }

    int retVal = thisQ->head->data;
    node * temp =thisQ-> head;

    while(temp->data != retVal){
        temp = temp->next;
    }

    free(temp);

}