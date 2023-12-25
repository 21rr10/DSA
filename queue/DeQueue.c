#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int queue[MAX];

int front=-1,rear=-1;
//input restricted queue= insert at end and delete at front and rear
// output restricted dequeue is deletion at ront and insert at both front and back
void end_enque(){//insert at end
    if(rear==MAX-1){
        printf("queue is full");
        return;
    }
    printf("Enter the data");

    if(front==-1 && rear==-1){
        front=0;rear=0;  
        scanf("%d",&queue[front]);
        queue[rear]=queue[front]; 
        return;   
    }
  
        scanf("%d",&queue[++rear]);
        return;
}
void display() {
    if(front == -1) {
        printf("queue empty");
        return;
    }
    printf("Elements in the  queue are: ");
    if(rear >= front) {
        for(int i = front; i <= rear; i++)
            printf("%d ",queue[i]);
    }
    else {
        for(int i = front; i < MAX; i++)
            printf("%d ", queue[i]);
  
        for(int i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    printf("\n");
}

void begin_enque() {
    if((front == 0 && rear == MAX-1) || rear == front-1){
        printf("queue is full");
        return;
    }
    else {
        if(front == -1) { // if queue is initially empty
            front = 0;
            rear = 0;
        }
        else if(front == 0) { // if front is at the first position of queue
            front = MAX - 1;
        }
        else { // decrement front
            front = front - 1;
        }
        printf("enter the data"); 
        scanf("%d", &queue[front]);
    }
}

void begin_deque(){//delete at beginning
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

void end_deque(){//delete at end
    if(front==-1 && rear==-1){
        printf("the queue is empty");
        return;
    }
    if(front==rear){
        printf("deleted element is %d", queue[front]);
        front=rear=-1;
        return;
    }
     printf(" deleted element is %d", queue[rear--]);

}
int main(){
    int choice =0,ch=0;
    while(choice!=3){
        printf("\nMenu\n1.input restricted Enque\n2.output restricted enque\n3. exit\nenter you choice ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: ch=0;while(ch!=5){
                         printf("\nMenu\n1.insert into input restricted queue\n2.delete from front from input restricted enque\n3. delete from rear 4. display\n5. exit\nenter you choice ");
                         scanf("%d",&ch);
                         switch (ch){
                            case 1: end_enque();
                                break;
                            case 2: begin_deque();
                                break;
                            case 3: end_deque();
                                break;
                            case 4:display();
                                break;
                            case 5: printf("exit");
                                    
                                    break;
                            default: printf("wrong choice");

                         }
                            }
            break;

        case 2: ch=0;while(ch!=5){
                         printf("\nMenu\n1.insert at rear into output restricted queue\n2.insert at front into output restricted enque\n3. delete from front\n4. display \n4. exit\nenter you choice ");
                         scanf("%d",&ch);
                         switch (ch){
                            case 1: end_enque();
                                break;
                            case 2: begin_enque();
                                break;
                            case 3: begin_deque();
                                break;
                            case 4:display();
                                break;
                            case 5: printf("exit");
                                    
                                    break;
                            default: printf("wrong choice");

                         }
                            }
            break;
        
        case 3:printf("exit");
                exit(0);
                break;
        default:printf("enter the right choice");
            
        }
    }
}