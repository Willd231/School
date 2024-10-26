#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
     char songname[20];
     struct node * next; 

}node;


node*createnewnode(char songname[20]){
    node * newnode = (node*)malloc(sizeof(node));

    newnode -> songname[i] = songname[i];
    newnode -> next = NULL;
}

