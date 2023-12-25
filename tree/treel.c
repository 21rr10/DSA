#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
}*root;

struct node * create(){
    struct node *t;
    int n;
    printf("enter the data \t -1 for no input");
    scanf("%d",&n);
    if(n==-1){
        return NULL;
    }
    t=(struct node *)malloc(sizeof(struct node));
    t->data=n;
    printf("\nenter the left child of %d",t->data);
    t->left=create();
    printf("\nEnter the rigth child of %d",t->data);
    t->right=create();
    return t;
}

void preorder(struct node *root){
    if(root!=NULL){
    printf("\t%d",root->data);
    preorder(root->left);
    preorder(root->right);
    }
}

void inorder(struct node *root){
    // p=root;
    if(root!=NULL){
    inorder(root->left);
    printf("\t%d",root->data);
    inorder(root->right);
    }}
 void postorder(struct node *root){
    // p=root;
     if(root!=NULL){
    postorder(root->left);
    postorder(root->right);
    printf("\t%d",root->data);
 }}

 static int c=0;
 void count(struct node *root){
    if(root==NULL){
        return;
    }
    c++;
    count(root->left);
    count(root->right);
 }
 static int l =0;
 void leaf(struct node *root){
    if(root==NULL){
        return ;
    }
    if(root->left==NULL&&root->right == NULL){
        l++;
    }
    leaf(root->left);
    leaf(root->right);

 } 
 int height(struct node *root){
    if(root==NULL){
        return 0;
    }
    else{
    int le= height(root->left);
    int ri=height(root->right);
    if(le>ri){
        return le+1;
    }
    else return ri+1;
    }
 }

int main(){
    int ch=0;
    while (ch!=8)
    {
        ch=0;
        printf("\nMenu\n1.insert\n2.print preorder\n3.print inorder\n4.print post order\n5. count number of nodes\n6. leaf nodes\n7.height\n8.exit\n Enter you CHOICE");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:root=create();
            break;
        case 2: preorder(root);
            break;
        case 3: inorder(root);
            break;
        case 4: postorder(root);
            break;
        case 5: count(root);
            printf("%d",c);
            break;
        case 6: leaf(root);
            printf("%d",l);
                break;
        case 7: printf("the height of the tree is %d",height(root));
            break;
        case 8: printf("exit with code 0");
                exit(0);
        default:printf("wrong choice");
            
        }
    }
    
}