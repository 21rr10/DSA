#include <stdio.h>
#include<stdlib.h>
// enque = add at end and deque = delete from beginning
struct node{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;

void enque(){
    struct node *t;
    t=(struct node*)malloc (sizeof(struct node));
    t->next=NULL;
    printf("Enter the element to add");
    scanf("%d",&t->data);
    
    if(front==NULL&rear==NULL){
        t->next=front;
        rear=front=t;
        return;
    }
    rear->next=t;
    rear=t;
    
    return;
    
    
}

void deque(){
    struct node *t;
    t=front;
    if(front==NULL&&rear==NULL){
        printf("queue empty");
        return;
    }
    if(front==rear){
        printf("%d",front->data);
        front=rear=NULL;
        return;
    }
    front=front->next;
    printf("the deleted element is %d",t->data);
    free(t);
}

void display(){
    struct node *t;
    t=front;
    if(front==NULL&&rear==NULL){
        printf("queue empty");
        return;
    }
    while(t!=NULL){
        printf("%d\t",t->data);
        t=t->next;
    }
}



int main(){
    int choice =0;
    while(choice!=4){
        printf("\nMenu\n1.Enque\n2.Deque\n 3. display\n4.Exit\n\nenter you choice ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:enque();
            break;
        case 2:deque();
            break;
        case 3: display();
                break;
        case 4:printf("exit");
                exit(0);
                break;
        default:printf("enter the right choice");
            
        }
    }
}