/*3) (10 pts) DSN (Queues)
A queue is implemented as an array. The queue has the 2 attributes, front and size. front is the index in the array
where the next element to be removed from the queue can be found, if the queue is non-empty. (If the queue is
empty, front may be any valid array index from 0 to 19.) size is the total number of elements currently in the
queue. For efficient use of resources, elements can be added to the queue not just at the end of the array but also
in the indices at the beginning of the array before front. Such a queue is called a circular queue. A circular queue
has the following structure:
typedef struct {
 int values[20];
 int front, size;
} cQueue;
Write an enqueue function for this queue. If the queue is already full, return 0 and take no other action.
If the queue isn't full, enqueue the integer item into the queue, make the necessary adjustments, and
return 1. Since the array size is hard-coded to be 20 in the struct above, you may use this value in your
code and assume that is the size of the array values inside the struct.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
 int values[20];
 int front, size;
} cQueue;

int enqueue(cQueue* thisQ, int item) {


// if the size is 20 ig it is full
   if(thisQ->size == 20){
    return 0; 
   }
    //idk about this tho 
    thisQ -> values[(thisQ->front + thisQ-> size)%20] = item; 
    //increase the size after enqueueing item
    thisQ -> size++; 
    //return 1
    return 1; 

}

