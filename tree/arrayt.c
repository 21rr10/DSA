#include <stdio.h>

#define MAX_NODES 100

int tree[MAX_NODES];
void inorder();
void preorder();
void postorder();
int countNodes();
void printLeafNodes();

void create() {
    int i, data;

    
    for(i = 0; i < MAX_NODES; i++) {
        tree[i] = -1;
    }

    printf("Enter the data for the nodes (enter -1 for no node):\n");

    // Create the binary tree by entering data level by level
    for(i = 0; i < MAX_NODES; i++) {
        printf("Enter data for node %d (Index %d in the array): ", i+1, i);
        scanf("%d", &data);
 
        if(data != -1) {
            tree[i] = data;
        } else {
            break;  // Stop if the user enters -1
        }
    }
}

void preorder(int index) {
    if(index >= MAX_NODES || tree[index] == -1) {
        return;
    }

    // Visit the root (current node)
    printf("%d ", tree[index]);

    // Traverse the left subtree
    preorder(2*index + 1);

    // Traverse the right subtree
    preorder(2*index + 2);
}

int main() {
    
    create();

    printf("Preorder traversal of the tree is: ");
    preorder(0);
    printf("\n");
    inorder(0);
    printf("\n");
    postorder(0);
    printf("\n");
     int x= countNodes(0);
    printf("the number of nodes %d", x);
    printf("\n");
    

    printLeafNodes(0);
   
    printf("\n");

    return 0;
}

int countNodes(int index) {
    // If the current node is empty or out of bounds, return 0
    if(index >= MAX_NODES || tree[index] == -1) {
        return 0;
    }

    // Count the current node and the nodes in the left and right subtrees
    return 1 + countNodes(2*index + 1) + countNodes(2*index + 2);
}


void printLeafNodes(int index) {
    // If the current node is empty or out of bounds, return
    if(index >= MAX_NODES || tree[index] == -1) {
        return;
    }
//2*index + 1 >= MAX_NODES ||
//2*index + 2 >= MAX_NODES || 
    // If the current node is a leaf node (i.e., both its children are empty), print it
    if(( tree[2*index + 1] == -1) && 
       (tree[2*index + 2] == -1)) {
        printf("%d ", tree[index]);
    }

    // Otherwise, print the leaf nodes in the left and right subtrees
    printLeafNodes(2*index + 1);
    printLeafNodes(2*index + 2);
}

void inorder(int index){
    if(index>=MAX_NODES || tree[index]==-1){
        return;
    }

    //traverse the left subtree
    inorder(2*index+1);

    //visit the root (current node)
    printf("%d ", tree[index]);

    //traverse the right subtree
    inorder(2*index + 2);
}

void postorder(int index){
    if(index>=MAX_NODES || tree[index]==-1){
        return;
    }

    //traverse the left subtree
    postorder(2*index+1);

    //traverse the right subtree
    postorder(2*index+2);

    //visit the root(current node)
    printf("%d ", tree[index]);
}

