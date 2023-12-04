#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;

void addAtBeg(){

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

void addAtEnd(){
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

void removeAtEnd(){
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

void removeAtBeg(){
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

int main(){
    int choice =0,ch=0;
    while(choice!=3){
        printf("\nMenu\n1.input restricted Enque\n2.output restricted enque\n3. exit\nenter you choice ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: while(ch!=5){
                         printf("\nMenu\n1.insert into input restricted queue\n2.delete from front from input restricted enque\n3. delete from rear 4. display\n5. exit\nenter you choice ");
                         scanf("%d",&ch);
                         switch (ch){
                            case 1: addAtEnd();;
                                break;
                            case 2: removeAtBeg();
                                break;
                            case 3: removeAtEnd();
                                break;
                            case 4:display();
                                break;
                            case 5: printf("exit");
                                    
                                    break;
                            default: printf("wrong choice");

                         }
                            }
            break;

        case 2: while(ch!=5){
                         printf("\nMenu\n1.insert at rear into output restricted queue\n2.insert at front into input restricted enque\n3. delete from front4. display \n4. exit\nenter you choice ");
                         scanf("%d",&ch);
                         switch (ch){
                            case 1: addAtEnd();
                                break;
                            case 2: addAtBeg();
                                break;
                            case 3: removeAtBeg();
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