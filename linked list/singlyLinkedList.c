#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node *next;
}*head=NULL,*tail=NULL;

void removeAftEl() {
    struct node *temp, *t;
    int key;
    printf("Enter the element after which you want to remove: ");
    scanf("%d", &key);

    temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Element not found or no element after it to remove.\n");
        return;
    }

    t = temp->next;
    temp->next =NULL;
    free(t);
}

void removeBfrEl() {
    struct node *temp, *t;
    int key;
    printf("Enter the element before which you want to remove: ");
    scanf("%d", &key);

    temp = head;
    if (temp == NULL || temp->data != key) {
        printf("Element not found or no element before it to remove.\n");
        return;
    }

    if (temp->next != NULL && temp->next->data == key) {
        struct node *toRemove = temp;
        head = temp->next;
        free(toRemove);
        return;
    }

    while (temp->next != NULL && temp->next->next != NULL && temp->next->next->data != key) {
        temp = temp->next;
    }

    if (temp->next == NULL || temp->next->next == NULL) {
        printf("Element not found or no element before it to remove.\n");
        return;
    }

    t = temp->next;
    temp->next = t->next;
    free(t);
}

void removeAftPos() {
    struct node *temp, *t;
    int pos;
    printf("Enter the position after which you want to remove: ");
    scanf("%d", &pos);

    temp = head;
    for (int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position or no element after it to remove.\n");
        return;
    }

    t = temp->next;
    temp->next = t->next;
    free(t);
}

void removeBfrPos() {
    struct node *temp, *t;
    int pos;
    printf("Enter the position before which you want to remove: ");
    scanf("%d", &pos);

    if (pos <= 1 || head == NULL || head->next == NULL) {
        printf("Invalid position or no element before it to remove.\n");
        return;
    }

    temp = head;
    for (int i = 1; i < pos - 1 && temp->next->next != NULL; i++) {
        temp = temp->next;
    }

    if (temp->next == NULL || temp->next->next == NULL) {
        printf("Invalid position or no element before it to remove.\n");
        return;
    }

    t = temp->next;
    temp->next =NULL;
    free(t);
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
        // t->next=head;
        // head=t;
        printf("cant be added bfr 0");
        free(t);
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
    while(choice!=19){
   printf("\nMenu\n1. Create a singly linked list\n2. Display\n3. Add element at the beginning\n4. Add element at the end\n5. Add element at a position\n6. Add element after a position\n7. Add element before a position\n8. Add element after an element\n9. Add element before an element\n10. Create a sorted linked list\n11. Reverse a linked list\n12. Remove element at the beginning\n13. Remove element at the end\n14. Remove element before a position\n15. Remove element after an element\n16. Remove element before an element\n17. Sort the linked list\n18. Search for an element using linear search\n19. Exit\nEnter your choice:\n-> ");
   scanf("%d", &choice);

  
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

    case 12 :removeAtBeg();
            break;
    case 13 :removeAtEnd();
            break;
    case 14 :removeBfrPos(x);
            break;
 
    case 16 :removeBfrEl();
            break;
    case 15 :
            removeAftEl();
            break;
    
    case 17 :removeAftPos();
            break;
    case 18 :printf("enter the key el");
                scanf("%d",&x);
             linSearch(x);
            break;
    
    case 19 : printf("exit");
                exit(0);
            break;
    default:printf("Wrong ");
   
   }
  }
}