#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}*root=NULL;



struct Node* insert(struct Node* root, int n) {
    if (root == NULL) {
       struct Node* newnode=(struct Node*)(malloc(sizeof(struct Node)));
       newnode->data=n;
         newnode->left = NULL; 
        newnode->right = NULL;
       return newnode;
    }

    if (n < root->data) {
        root->left = insert(root->left, n);
    } else if (n > root->data) {
        root->right = insert(root->right, n);
    }
    return root;
}







void preOrder(struct Node* root) {
    if (root != NULL) {
        printf("\t%d", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("\t%d", root->data);
        inOrder(root->right);
    }
}

void postOrder(struct Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("\t%d", root->data);
    }
}

static int c=0;
static int leaf=0;

int height(struct Node* root){

   if(root==NULL){
         return 0;
   }

else {
    int left=height(root->left);
    int right=height(root->right);
    if(left>right){
        return left+1;
    }
    else{
        return right+1;
    }
}
}

void numberofnodes(struct Node* root){
    if(root==NULL){
        return;
    }
    c++;
    numberofnodes(root->left);
    numberofnodes(root->right);
}

void numberofleafnodes(struct Node* root){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
    leaf++;}
    numberofleafnodes(root->left);
    numberofleafnodes(root->right);
}



// struct Node* search(struct Node * root, int p){
//               if(root==NULL){
//                 return NULL;
//               }
//         if(root->data==p){
//             return root;
//         }
//         else if(root->data>p){
//             return search(root->left,p);
//         }
//         else{
//             return search(root->right,p);
//         }
// }

struct Node *search(struct Node *root,int k){
    if(root==NULL){
        return NULL;
    }
    if(root->data==k){
        printf("\nElement found: %d",root->data);
        return root;
    }
   else if(root->data>k){
        return search(root->left,k);
    }
    else return search(root->right,k);
    
}



  struct Node * inOrderPredessor(struct Node *root){
    // left subtree ka rightmost child
           root=root->left;
           while(root->right!=NULL){
            root=root->right;
           }
               return root;
  }


struct Node *deleteNode (struct Node *root,int value){
    struct Node* iPre;
         if(root==NULL){
            return NULL;
         }
            if(root->left==NULL && root->right==NULL){
            free(root);
            return NULL;
           }

        //Search for the node to be deleted
          if(value<root->data){
          root->left=deleteNode(root->left,value);
          }   
           else if(value>root->data){
          root->right=deleteNode(root->right,value);
          }  
          


 else{//value == root->data
        
        if (root->left != NULL) {
            // find predecessor in the left subtree
            iPre = Predecessor(root);
            root->data = iPre->data;
            root->left = dele(root->left, iPre->data);
        } 
        else {
            // no left child, replace with right child
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
    }

    return root;
}





//  when the node is found
        //   else{
        //        iPre=inOrderPredessor(root);
        //        root->data=iPre->data;
        //       root->left=deleteNode(root->left,iPre->data);
        //   }

        //   return root;
// }




















int main() {
   
    int choice = 1;
    int key;
    

    while (choice) {
        printf("\n1. Insert element\n2. Preorder\n3. Inorder\n4. PostOrder\n5.Number of nodes\n6.Number of leaf nodes\n7.Height of a tree\n8.Search an element\n9.Delete from tree\n10.Exit\nEnter a choice: ");
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

            case 5: numberofnodes(root);
               printf("Number of nodes= %d",c);
               break;
                case 6: numberofleafnodes(root);
               printf("Number of nodes= %d",leaf);
               break;

  case 7: printf("Height of the tree %d",height(root));
             break;

case 8: printf("\nEnter the element to search: ");
          int a;
          scanf("%d",&a);
          search(root,a);
        //   struct Node *n=search(root,a);

        //   if(n==NULL){
        //     printf("\nElement not found");
        //   }
        //   else{
        //     printf("\nElement found: %d",n->data);
        //   }


 break;

        case 9: int del;
        printf("\nEnter the element you want to delete:");
        scanf("%d",&del);
        root=deleteNode(root,del);
        break;

        case 10:
            printf("\nExiting program");
            exit(0);

        default:
            printf("\nEnter a valid choice: ");
        }
    }

    return 0;
}