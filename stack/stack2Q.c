#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int q1[MAX];
int f1=-1;
int r1=-1;

int q2[MAX];
int f2=-1;
int r2=-1;

int size=0;


void enqueue1(int x){
     // if(r1==MAX-1){
     //      printf("\nQueue is full");
     //      return;
     // }
     if(f1==-1){
          f1=0;
          r1=0;
     }
     else{
          r1++;
     }
     q1[r1]=x;
}


int dequeue1(){
     // if(f1==-1){
     //      printf("\nQueue is empty");
     //      return -1;
     // }
 if(f1==r1){
        int i=q1[f1];
            f1=-1;
            r1=-1;
        return i;
 }
      return q1[f1++];
}


void enqueue2(int x){
     if(r2==MAX-1){
          printf("\nQueue is full");
          return;
     }
     if(f2==-1){
          f2=0;
          r2=0;
     }
     else{
          r2++;
     }
     q2[r2]=x;
}


int dequeue2(){
     if(f2==-1){
          printf("\nQueue is empty");
          return -1;
     }
 if(f2==r2){
        int i=q2[f2];
            f2=-1;
            r2=-1;
        return i;
 }
      return q2[f2++];
}



void push(int x){
     if(r1==MAX-1){
       printf("\nStack overflow");
       return;
     }
     enqueue1(x);
     size++;
}


int pop(){
     if(f1==-1){
        return -1;
     }
     for (int i = 0; i < size-1; i++)
     {
          enqueue2(dequeue1());
     }
     int r=dequeue1();
     size--;
     for (int i = 0; i < size; i++)
     {
           enqueue1(dequeue2());
     }
     return r;
}


void display(){
     if(f1==-1){
          printf("\nStack underflow");
          return;
     }
     for (int i = r1; i>=0; i--)
     {
          printf("\t %d",q1[i]);
     }
}


int main(){
      int choice = 1;

     while (choice)
     {
          printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter a choice: ");
          scanf("%d", &choice);
          switch (choice)
          {
          case 1:
               printf("\nEnter an element to push:");
               int el;
               scanf("%d", &el);
               push(el);
               break;
          case 2:
               int popp = pop();
               if (popp == -1)
               {
                    printf("\nStack underflow");
               }
               else
               {
                    printf("\nPopped element is %d", popp);
               }
               break;
          case 3:
               display();
               break;
          case 4:
               exit(0);

          default:
               printf("\nInvalid option");
          }
     }
return 0;
}