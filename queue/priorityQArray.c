
#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int array[MAX];
int front = -1;
int rear = -1;

void enque(int data){
    if(rear == MAX-1){
        printf("Queue is full");
        return;
    }
    if(front == -1 && rear == -1){
        front = rear = 0;
        array[rear] = data;
    }else{
        int i;
        for(i=front; i<=rear; i++){
            if(data > array[i]){
                break;
            }
        }
        for(int j=rear+1; j>i; j--){
            array[j] = array[j-1];
        }
        array[i] = data;
        rear++;
    }
}

void deque(){
    if(front == -1){
        printf("Queue is empty");
        return;
    }
    printf("%d ", array[front]);
    if(front == rear){
        front = rear = -1;
    }else{
        front++;
    }
}

void display(){
    if(front == -1){
        printf("Queue is empty");
        return;
    }
    for(int i=front; i<=rear; i++){
        printf("%d\t", array[i]);
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