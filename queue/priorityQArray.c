
#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int queue[MAX];
int front = -1;
int rear = -1;

void enque(int data){
    if(rear == MAX-1){
        printf("Queue is full");
        return;
    }
    if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = data;
    }else{
        int i;
        for(i=front; i<=rear; i++){
            if(data > queue[i]){
                break;
            }
        }
        for(int j=rear+1; j>i; j--){
            queue[j] = queue[j-1];
        }
        queue[i] = data;
        rear++;
    }
}

void deque(){//delete at beginning
    if(front==-1 && rear==-1){
        printf("the queue is empty");
        return;
    }
    if(front==rear){
        printf(" deleted element is %d", queue[front]);
        front=rear=-1;
        return;
    }
     printf("deleted element is %d", queue[front++]);
}


void display(){
    if(front == -1){
        printf("Queue is empty");
        return;
    }
    for(int i=front; i<=rear; i++){
        printf("%d\t", queue[i]);
    }
}

int main(){
    int choice =0;
    while(choice!=4){
        printf("\nMenu\n1.insert into priority queue\n2.remove from queue\n3.display\n4. exit\nenter you choice ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: 
            printf("Enter the data: ");
            int data;
            scanf("%d", &data);
            enque(data);
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