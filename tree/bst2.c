#include <stdio.h>
#include <stdlib.h>

struct node{
     int data;
     struct node *left;
     struct node *right;
}*root=NULL;


struct node * insert(struct node * root,int val){
    struct node *newnode;
    newnode=(struct node *)(malloc(sizeof(struct node)));
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;
    
    if(root==NULL){
        return newnode;
    }
    if(root->data>val){
        root->left=insert(root->left,val);
    }

    else{
        root->right=insert(root->right,val);
    }

    return root;
}

void preOrder(struct node* root) {
    if (root != NULL) {
        printf("\t%d", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("\t%d", root->data);
        inOrder(root->right);
    }
}

void postOrder(struct node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("\t%d", root->data);
    }
}

struct node *Predecessor(struct node *root){
    root=root->left;
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}

struct node *dele(struct node *root,int t){
    struct node *iPre;
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        free(root);
        return NULL;
    }
    //search for the node
    if(root->data>t){
        root->left=dele(root->left,t);
    }
    else if(root->data<t){
        root->right=dele(root->right,t);
    }

    else{
        
        if (root->left != NULL) {
            // find predecessor in the left subtree
            iPre = Predecessor(root);
            root->data = iPre->data;
            root->left = dele(root->left, iPre->data);
        } 
        else {
            // no left child, replace with right child
            struct node *temp = root->right;
            free(root);
            return temp;
        }
    }

    return root;
}


int main() {
   
    int choice = 1;
    int key;
    
    while (choice) {
        printf("\n1. Insert element\n2. Preorder\n3. Inorder\n4. PostOrder\n5.Delete\n6.Exit\nEnter a choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\nEnter a value to insert: ");
            scanf("%d", &key);
            root = insert(root, key);
            break;

        case 2:
            printf("\nPreorder Traversal: ");
            preOrder(root);
            break;

        case 3:
            printf("\nInorder Traversal: ");
            inOrder(root);
            break;

        case 4:
            printf("\nPostorder Traversal: ");
            postOrder(root);
            break;
        
        case 5: 
            int del;
            printf("\nEnter the element you want to delete:");
            scanf("%d",&del);
            root=dele(root,del);
            break;

        case 6:
            printf("\nExiting program");
            exit(0);

        default:
            printf("\nEnter a valid choice: ");
        }
    }

    return 0;
}