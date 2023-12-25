#include <stdio.h>
#include <stdlib.h>


struct node{
     int exp;
     int coff;
     struct node *next;
}*s1=NULL,*s2=NULL,*s3=NULL;

struct node* create(struct node *start,int x,int p){
     struct node *newnode;
     newnode=(struct node *)(malloc(sizeof(struct node)));

     newnode->exp=x;
     newnode->coff=p;
     newnode->next=NULL;

     if(start==NULL || start->exp<x){
          newnode->next=start;
          start=newnode;
          return start;
     }
  struct node *t=start;
  while(t->next!=NULL && t->next->exp>x){
    t=t->next;
  }
      newnode->next=t->next;
     t->next=newnode;
     return start;
}



void display(struct node *start){
     struct node *t;

     if(start==NULL){
          printf("\nEmpty");
          return;
     }
     t=start;
     while(t->next!=NULL){
          printf("%dx^%d+",t->coff,t->exp);
          t=t->next;
     }
     printf("%dx^%d",t->coff,t->exp);

}

void add(struct node *s1,struct node *s2,struct node **s3){
     struct node *t1,*t2;
     t1=s1,t2=s2;
     *s3=NULL;

if(s1==NULL){
     *s3=s2;
     return;
}

if(s2==NULL){
     *s3=s1;
     return;
}

while(t1!=NULL && t2!=NULL){

     if(t1->exp>t2->exp){
          *s3=create(*s3,t1->exp,t1->coff);
          t1=t1->next;
     }

     if(t2->exp>t1->exp){
          *s3=create(*s3,t2->exp,t2->coff);
          t2=t2->next;
          }

          else if(s1->exp==s2->exp){
               *s3=create(*s3,t1->exp,(t1->coff)+(t2->coff));
               t1=t1->next;
               t2=t2->next;
          }}

   while(t1!=NULL){
     *s3=create(*s3,t1->exp,t1->coff);
     t1=t1->next;
   }

    while(t2!=NULL){
     *s3=create(*s3,t2->exp,t2->coff);
     t2=t2->next;
   }





}

















int main(){

        int choice=1;
     while(choice){
          printf("\nMENU\n1.Enter polynomial 1\n2.Enter polynomial 2\n3.Display\n4.Add\n5.Exit\nEnter a choice: ");
          scanf("%d",&choice);

          switch(choice){
            case 1: int el,coff;
                   printf("\nEnter an exp and coff: ");
                   scanf("%d%d",&el,&coff);
                   s1=create(s1,el,coff);
                   break;
            case 2: int el2,coff2;
                   printf("\nEnter an exp and coff: ");
                   scanf("%d%d",&el2,&coff2);
                   s2=create(s2,el2,coff2);
                   break;



          case 3: printf("\nEnter the polynomial you want to print 1,2 or 3(summed): ");
               int list;
               scanf("%d", &list);
               switch (list)
               {
               case 1:
                    display(s1);
                    break;
               case 2:
                    display(s2);
                    break;
               case 3:
                    display(s3);
                    break;

               default:
                    printf("\nWrong choice");
               }
                  break;

           case 4: add(s1,s2,&s3);
           break;

            case 5:printf("\nExitting program");
                     exit(0);       

          }}
return 0;
}