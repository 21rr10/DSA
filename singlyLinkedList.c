#include<stdio.h>
#include<stdlib.h>

/*

  
  
  remove element at a position
  remove element after a position
  remove element before a position
  remove element after an element
  remove element before an element
  
  
  
*/
struct node{
    int data;
    struct node *next;
}*head=NULL,*tail=NULL;

void removeAftEl(){

}
void removeBfrEl(){
    
}
void removeAftPos(){
    
}
void removeBfrPos(){
    
}
void removeAtEnd(){
        struct node *t;
        t=head;
        if(head==NULL){
                printf("list is empty");
                return;
        }
        printf("choose a way1 or a way 2"); int ch;
        scanf("%d", &ch);
        switch (ch){
        case 1:                 while(t->next!=tail){
                                        t=t->next;
                                }
                                t->next=NULL;
                                free(tail);
                                tail=t;
                break;
        case 2:                 while(t->next->next!=NULL){
                                t=t->next;
                                }
                                struct node *p= t->next->next;
                                t->next=NULL;
                                free(p);
                                tail=t;
                                
                                break;
        default: printf("wrong input;");
                break;
        }
        
}

void removeAtBeg(){
        struct node *t;
        
        if(head==NULL){
                printf("list is empty");
                return;
        }
        if(head->next==NULL){
                head=tail=NULL;
                free(head);
                free(tail);
                return;
        }
        t=head;
        head=head->next;
        free(t);
    
}
void removeAtPos(){
    
}

void create(int x){
    struct node *t,*temp;
    t= (struct node *)malloc (sizeof(struct node));
    t->data=x;
    t->next=NULL;
    if(head==NULL)
        {
            head=t;
            tail=t;
            return;
        }
    // temp=head;
    // while(temp->next!=NULL)
    //     {
    //         temp=temp->next;

    //     }
    // temp->next=t;
    tail->next=t;
    tail=t;
}

void display()
    {
      struct  node *p;
    p=head;
    if(head==NULL){
        printf("list is empty");
        return;
    }
    while(p!=NULL){
        printf("%d->",p->data);
        p=p->next;
    }  
    
}

void addAtBeg(int x){
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    t->data=x;
    t->next=NULL;
    if(head==NULL){
        head=tail=t;
        return;
    }
    t->next=head;
    head=t;
    return;

}

void addAtEnd(int x){
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    t->data=x;
    t->next=NULL;
    if(head==NULL){
        head=tail=t;
        return;
    }
    tail->next=t;
    tail=t;
    return;

}

 void addAtPos(int x,int pos){
    struct node *t,*temp;
    t=(struct node *)malloc(sizeof(struct node));
    t->data=x;
    t->next=NULL;
    if(pos==0){
        t->next=head;
        head=t;
        return;
    }
    temp=head;
    for (int i = 1; i < pos; i++)
    {
        temp=temp->next;
    }
    t->next=temp->next;
    temp->next=t;
    


 }
void addAftPos(int x,int pos){
    struct node *t,*temp;
    t=(struct node *)malloc(sizeof(struct node));
    t->data=x;
    t->next=NULL;
    if(pos==0){
        t->next=head->next;
        head->next=t;
        return;
    }
    temp=head;
    for (int i = 1; i <= pos; i++)
    {
        temp=temp->next;
    }
    t->next=temp->next;
    temp->next=t;
    


 }
 void addBfrPos(int x,int pos){
    struct node *t,*temp;
    t=(struct node *)malloc(sizeof(struct node));
    t->data=x;
    t->next=NULL;
    if(pos==0){
        t->next=head;
        head=t;
        return;
    }
//     if(pos==1){
//         t->next=head->next;
//         head->next=t;
//         return;
//     }
    temp=head;

    for (int i = 1; i < pos-1; i++)
    {
        temp=temp->next;
    }
    t->next=temp->next;
    temp->next=t;
    
    return;

 }
 void addAftEl(int x){
        struct node *t,*temp,*p; int y;
        printf("Enter the el u want to insert after");
        scanf("%d",&y);
        t= (struct node *)malloc (sizeof(struct node));
        t->data =x;
        t->next=NULL;
        temp=head;
        while(temp!=NULL && temp->data!=y)
                {
                        temp=temp->next;
                        
                        
                }

        if(temp==NULL){printf("el not found");return;}
        p= temp->next;
        temp->next=t;
        t->next=p;
        return;

 }
 void addBfrEl(int x){
        struct node *t,*temp,*p; int y;
        printf("Enter the el u want to insert before");
        scanf("%d",&y);
        t= (struct node *)malloc (sizeof(struct node));
        t->data =x;
        t->next=NULL;
        if(head->data==y){
                t->next=head;
                head=t;
                return;
        }
        temp=head;
        while(temp->next!=NULL&&temp->next->data!=y)
                {
                        temp=temp->next;
                        
                        
                }
        if(temp->next==NULL){
                printf("el not found");
                return;
        }
        p= temp->next;
        temp->next=t;
        t->next=p;
        return;


 }

void sort(int x){
        struct node *t,*temp;
        t=(struct node*)malloc(sizeof(struct node));
        t->data=x;
        t->next=NULL;
        if(head==NULL||head->data>x){
                t->next=head;
                head=t;
                return;
        }
        temp=head;
        while(temp->next!=NULL && temp->next->data<x){
                temp=temp->next;
        }
        t->next=temp->next;
        temp->next=t;

}

void linSearch(int x){
        struct node *t;
        t=head;
        while(t!=NULL){
                if(t->data==x){
                        printf("key found");
                        return;
                }
                t=t->next;
        }
        if(t==NULL){printf("key not found");}

}

void reverse(){
        struct node *p1,*p2,*p3;
        p1=head;
        p2=p1->next;
        p3=p2->next;
        p1->next=NULL;
        p2->next=p1;
        
        while(p3!=NULL){
                p1=p2;
                p2=p3;
                p3=p3->next;
                p2->next=p1;
        }
        head=p2;
}


int main(){
    int choice,x,p;
    while(choice!=20){
    printf("\nMenu\n1. create a singly linked lisvoid t \n2.display\n3. add element at the beginning\n  4.add element at the end\n  5.add element at a position\n  6.add element after a position\n  7.add element before a position\n  8.add element after an element\n  9.add element before an element\n  10 create a sorted ll\n  11 reverse a linked list\n  12 remove element at beginning\n  13 remove element after a position\n  14 remove element before a position\n  15 remove element after an element\n  16 remove element before an element\n  17 sort the link list\n  19 search for an element using linear search\n  18 search for an element using binary search\n20. exit\n Enter your choice:\n-> ");
  scanf("%d",&choice); 
  
   switch (choice)
   {
   case 1 : printf("enter the data");
            scanf("%d",&x);
            create(x);
            break;
    case 2 :display();
            break;
    case 3 :printf("enter the data");
            scanf("%d",&x);
            addAtBeg(x);
            break;
    case 4 :printf("enter the data");
            scanf("%d",&x);
            addAtEnd(x);
            break;
    case 5 :printf("enter the data and the position");
            scanf("%d%d",&x,&p);
            addAtPos(x,p);
            break;
    case 6 :printf("enter the data and the position");
            scanf("%d%d",&x,&p);
            addAftPos(x,p);
            break;
    case 7 :printf("enter the data and the position");
            scanf("%d%d",&x,&p);
            addBfrPos(x,p);
            break;

    case 8 :printf("enter the data");
            scanf("%d",&x);
            addAftEl(x);
            break;
    case 9 :printf("enter the data");
            scanf("%d",&x);
            addBfrEl(x);
            break;
   
    case 10 :printf("enter the data");
            scanf("%d",&x);
            sort(x);
            break;
    case 11 :reverse();
             printf("reversed");
            break;
    case 12 :
            removeAtBeg();
            break;
    case 13 :
            removeAtEnd();
            break;
    case 14 :printf("enter the data");
            scanf("%d",&x);
            removeBfrPos(x);
            break;

    case 15 :printf("enter the data");
            scanf("%d",&x);
            removeAftEl(x);
            break;
    case 16 :printf("enter the data");
            scanf("%d",&x);
            removeBfrEl(x);
            break;
    case 17 :removeAftEl();
            break;
    case 18 :
            break;
    case 19 :printf("enter the key el");
                scanf("%d",&x);
             linSearch(x);
            break;
    
    case 20 : printf("exit");
                exit(0);
            break;
    default:printf("Wrong ");
   
   }
  }
}