/*Fall 2017 Data Structures Exam, Part A
Page 3 of 4
2) (10 pts) DSN (Linked Lists)
Write a recursive function that takes in the head of a linked list and frees all dynamically allocated
memory associated with that list. You may assume that all the nodes in any linked list passed to your
function (including the head node) have been dynamically allocated. It’s possible that your function
might receive an empty linked list (i.e., a NULL pointer), and you should handle that case appropriately.
Note that your function must be recursive in order to be eligible for credit.
The linked list node struct and the function signature are as follows:
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
struct node *next;
int data;
} node;


void destroy_list(node *head) {

    if(head==NULL){
        printf("List is empty");
        return 0;
    }

    
    if(head->next != NULL){
        free(head->next);
        destroy_list(head);
    }
    else if(head->next == NULL){
        free(head);

    }

    



}


//end of my attempt

//start of correct answer

typedef struct node {
struct node *next;
int data;
} node;
void destroy_list(node *head) {
if (head == NULL)
return;
destroy_list(head->next);
free(head);
}
/*Grading: Award 3 pts for correctly handling the base case. Award 3 points for a correct recursive call.
Award 4 points for freeing head after the recursive call.
Note: Some students might set head->next to NULL before freeing head., which causes some
unnecessary computation, but doesn’t render their solution incorrect. You can ignore that.
However, if they set head itself to NULL before freeing it, they should not be eligible to receive the 4
points for freeing head after the recursive call. 

Pretty freaking close i would say 

just shouldve used the recursive part to also act as the iterator rather than what i had
also i just needed to do return not return 0
*/