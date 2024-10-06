/*Spring 2018 Data Structures Exam, Part A
Page 3 of 4
2) (5 pts) DSN (Linked Lists)
Given the linked list structure named node, defined in lines 1 through 4, and the function named
eFunction defined in lines 6 through 14, answer the questions below.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
int data;
struct node * next;
} node;
 
  node* eFunction(node* aNode){
  if(aNode == NULL) return NULL;
  if(aNode->next == NULL) return aNode;
 
 node* rest = eFunction(aNode->next);
 aNode->next->next = aNode;
 aNode->next = NULL;
 return rest;
 }



/*(a) (1 pt) Is this function recursive? (Circle the correct answer below.)
YES NO
(b) (2 pts) What does the function eFunction do, in general to the list pointed to by its formal
parameter, aNode?
it splits up the nodes

(c) (2 pts) What important task does line 12 perform?
*/



/*begin my response here:
Yes


*/


//I got 1/3 i shouldve read more carefully 