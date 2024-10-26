#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int index; 
    struct node *left, *right;
}node;

node * newNode(int index){
    node * newnode = (node*)malloc(sizeof(node));
    newnode->index = index;
    newnode->left = newnode ->right = NULL;
    return newnode;
}

struct node * insert(node*newnode, int index){
    if(newnode == NULL){
        return newNode(index);
    }
    if(newnode ->index > index ){
        newnode->left = insert(newnode->left, index); 
    }
    else if (index > newnode -> index)
    {
        newnode -> right = insert(newnode -> right, index); 
    }
    
    return newnode; 

    }


    void inorder(struct node*root){
        if(root!=NULL){
            
        }
    }




    int main(){
        node * root = NULL; 



        return 0; 
    }