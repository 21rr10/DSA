#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;

void enque(){
        struct node *t,*temp;
        t=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data");
        scanf("%d",&t->data);
        t->next=NULL;
        if(front==NULL||front->data<t->data){
                t->next=front;
                front=t;
                return;
        }
        temp=front;
        while(temp->next!=NULL && temp->next->data>t->data){
                temp=temp->next;
        }
        t->next=temp->next;
        temp->next=t;

}
void deque(){
        struct node *t;
        
        if(front==NULL){
                printf("queue is empty");
                return;
        }
        if(front->next==NULL){
                printf("%d",front->data);
                front=rear=NULL;
                free(front);
                free(rear);
                return;
        }
        t=front;
        front=front->next;
        printf("%d",t->data);
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
        printf("\nMenu\n1.insert into priority queue\n2.remove from queue\n3.display\n4. exit\nenter you choice ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: enque();
            break;

        case 2: deque();
            break;
        case 3: display();
            break;
        case 4: printf("exit");
                exit(0);

            break;
        default: printf("wrong choice");

        }
    }
}