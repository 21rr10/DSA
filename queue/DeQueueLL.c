#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;

void beg_enque(){

    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data");
    scanf("%d",&t->data);
    t->next=NULL;
    if(front==NULL){
        front=rear=t;
        return;
    }
    t->next=front;
    front=t;
    return;

}

void end_enque(){
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
     printf("Enter the data");
    scanf("%d",&t->data);
    
    t->next=NULL;
    if(front==NULL){
        front=rear=t;
        return;
    }
    rear->next=t;
    rear=t;
    return;

}

void end_deque(){
        struct node *t;
        t=front;
        if(front==NULL){
                printf("list is empty");
                return;
        }
        printf("choose a way1 or a way 2"); int ch;
        scanf("%d", &ch);
        switch (ch){
        case 1:                 while(t->next!=rear){
                                        t=t->next;
                                }
                                t->next=NULL;
                                printf("%d",rear->data);
                                free(rear);
                                rear=t;
                break;
        case 2:                 while(t->next->next!=NULL){
                                t=t->next;
                                }
                                struct node *p= t->next->next;
                                t->next=NULL;
                                printf("%d",p->data);
                                free(p);
                                rear=t;
                                
                                break;
        default: printf("wrong input;");
                break;
        }
        
}

void beg_deque(){
        struct node *t;
        
        if(front==NULL){
                printf("list is empty");
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
int main() {
    int choice = 0, ch = 0;
    while (choice != 3) {
        printf("\nMenu\n1. Input restricted Enque\n2. Output restricted enque\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:ch=0;
                while (ch != 5) {
                    printf("\nMenu\n1. Insert into input restricted queue\n2. Delete from front from input restricted enque\n3. Delete from rear\n4. Display\n5. Exit\nEnter your choice: ");
                    scanf("%d", &ch);
                    switch (ch) {
                        case 1:
                            end_enque();
                            break;
                        case 2:
                            beg_deque();
                            break;
                        case 3:
                            end_deque();
                            break;
                        case 4:
                            display();
                            break;
                        case 5:
                            printf("Exit\n");
                            break;
                        default:
                            printf("Wrong choice\n");
                    }
                }
                break;

            case 2:ch=0;
                while (ch != 5) {
                    printf("\nMenu\n1. Insert at rear into output restricted queue\n2. Insert at front into input restricted enque\n3. Delete from front\n4. Display\n5. Exit\nEnter your choice: ");
                    scanf("%d", &ch);
                    switch (ch) {
                        case 1:
                            end_enque();
                            break;
                        case 2:
                            beg_enque();
                            break;
                        case 3:
                            beg_deque();
                            break;
                        case 4:
                            display();
                            break;
                        case 5:
                            printf("Exit\n");
                            break;
                        default:
                            printf("Wrong choice\n");
                    }
                }
                break;

            case 3:
                printf("Exit\n");
                exit(0);
                break;
                
            default:
                printf("Enter the right choice\n");
        }
    }
    return 0;
}