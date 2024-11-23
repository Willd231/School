#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>


typedef struct treenode{
    int data; 
    treenode *left;
    treenode *right;

}treenode; 

treenode * createnewnode(int data){
    treenode * newnode = malloc(sizeof(treenode));
    newnode -> left = NULL;
    newnode -> right = NULL;
    newnode -> data = data; 

    return(newnode);
}

bool insert(treenode ** rootptr, int value){
     treenode *root = *rootptr; 

    if(root == NULL){
        
    }
}


