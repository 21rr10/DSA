#include <stdio.h>
#include<stdlib.h>
// push= add at beginning and pop= remove at beginning
struct node{
    int data;
    struct node *next;
}*start=NULL;

void push(){
    struct node *t;
    t=(struct node*)malloc (sizeof(struct node));
    t->next=NULL;
    printf("Enter the element to push");
    scanf("%d",&t->data);
    
    t->next=start;
    start=t;
    return;
    
    
}

void pop(){
    if(start==NULL){
        printf("stack is empty");
        return;
    }
    struct node *t=start;
    printf("the popped element is %d",t->data);
    start=start->next;
    free(t);
    
}

void display(){
    struct node *t=start;
    if(start==NULL){
        printf("the stack is empty");
        return;
        }
    while(t!=NULL){
        printf("\t%d\n", t->data);
        t=t->next;
    }
}

void peek(){
    printf("%d",start->data);
}

int main(){
    int choice=0;
    while (choice !=5){
        printf("\nMenu\n1. push\n2. pop\n 3.display\n4. Peek\n 5. exit\n\nenter you choice");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: push();
            break;
        case 2: pop();
            break;
        case 3:display();
            break;
        case 4: peek();
            break;
        case 5: printf("exit");exit(0);
        default:printf("enter right choice");
            
        }


    }
}