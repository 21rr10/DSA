#include <stdio.h>
#include<stdlib.h>
#define MAX 10

int front=-1;
int rear=-1;

int queue[MAX];

void enque(){
    if((front==0 && rear==MAX-1)||front==rear+1){
        printf("queue is full");
        return;
    }
    

    if(front==-1&&rear==-1){
        front=0;rear=0;       
    }
    else{
    rear=(rear+1)%MAX;
    }

    printf("Enter the data");
    scanf("%d",&queue[rear]);
    return;
}

void deque(){
    if(front==-1 &&rear==-1){
        printf("queue empty ...nothing to delete");
        return;
    }
    if(front==rear){
        printf("deleted element is %d", queue[front]);
        front=rear=-1;
        return;
    }
    printf("deleted element is %d", queue[front]);
    front=(front+1)%MAX;
}

void display(){
    if(front==-1){
        printf("queue qmpty");
        return;
    }
    for(int i=front;i<=rear;i=(i+1)%MAX){
        printf("%d\t",queue[i]);
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