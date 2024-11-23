/*William Dellinger
  Script assignment 5
  7/14/24
  COP 3502
  */


#include <stdio.h>
#include <stdlib.h>

// struct for tree
struct tree_node {
    int data;
    struct tree_node *left;
    struct tree_node *right;
};

// Function to create a new  node
struct tree_node* new_node(int data) {
    struct tree_node* node = (struct tree_node*)malloc(sizeof(struct tree_node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to print values greater than or equal to a given value
void PrintBig(struct tree_node *current_ptr, int value) {
    if (current_ptr == NULL) {
        return;
    }
    
    //traverse the right subtree first
    PrintBig(current_ptr->right, value);
    
    // see if its eligible to be correct
    if (current_ptr->data >= value) {
        printf("%d ", current_ptr->data);
    }
    
    //traverse the left subtree
    PrintBig(current_ptr->left, value);
}

//function to insert a new node with given key in BST
struct tree_node* insert(struct tree_node* node, int data) {
    // If the tree is empty, return a new node
    if (node == NULL) return new_node(data);
    
    
    if (data < node->data)
        node->left  = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);   
    
    
    return node;
}


int main() {
    struct tree_node *root = NULL;
    root = insert(root, 50);
    insert(root, 100);
    insert(root, 1000);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    
    int value = 40;
    printf("Values in the tree greater than or equal to %d:\n", value);
    PrintBig(root, value);
    
    return 0;
}
