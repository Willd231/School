
/*Fall 2021 Data Structures Exam, Part A
Page 4 of 4
3) (10 pts) ALG (Queues)
Suppose we wish to implement a queue using an array. The structure of the queue is shown below.*/

/*The queue contains the array and three attributes: the current number of elements in the array, the current
front of the queue, and the maximum capacity. Elements may be added to the queue not just at the end of
the array but also in the indices at the beginning of the array before front. Such a queue is called a circular
queue.
Write a function to implement the dequeue functionality for the queue, while ensuring that no null pointer
errors occur. Your function should take in 1 parameter: a pointer to the queue. Your function should return
the integer that was dequeued. If the queue is NULL or if there are no elements to dequeue, your function
should return 0.*/

#include <stdio.h>
#include <stdlib.h>

struct queue {
 int *array;
 int num_elements;
 int front;
 int capacity;
};

int dequeue(struct queue * q) {
    if(q->num_elements == 0 || q == NULL){ //check the two initial conditions, essentially if the queue is empty but make sure to access the size via the arrow op within the array 
        return 0;
    }


    int retval = q->array [q->front]; //obtain the value to dequeue and return 

    //
    q->front = (q->front + 1) % q -> capacity; 

    //after you dequeue, update the size of the queue
    q->num_elements = q->num_elements - 1; 

    return retval;  
}
