#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int stack1[MAX];
int stack2[MAX];
int top1=-1;
int top2=-1;
int size=0;


void push1(int x)
{
     if (top1 == MAX - 1)
     {
          return;
     }
     stack1[++top1] = x;
}
void push2(int x)
{
     if (top2 == MAX - 1)
     {
          return;
     }
     stack2[++top2] = x;
}

int pop1()
{
     if (top1 == -1)
     {
          return -1;
     }
     return stack1[top1--];
}
int pop2()
{
     if (top2 == -1)
     {
          return -1;
     }
     return stack2[top2--];
}


void enqueue(int x){
     push1(x);
     size++;
}



int dequeue(){
     if(top1==-1){
          return -1;
     }
     for (int i = 0; i < size; i++)
     {
         push2(pop1());
     }
   int p=pop2();
   size--;
   for (int i = 0; i <size; i++)
   {
         push1(pop2());
   }
   
     return p;
}


void display(){
     if(top1==-1){
          printf("\nEmpty queue");
          return;
     }
     for (int i = 0; i <=top1; i++)
     {
          printf("\t %d",stack1[i]);
     }
     
}
















int main(){
           int choice = 1;

     while (choice)
     {
          printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter a choice: ");
          scanf("%d", &choice);
          switch (choice)
          {
          case 1:
               printf("\nEnter an element to enter:");
               int el;
               scanf("%d", &el);
               enqueue(el);
               break;
          case 2:
               int popp = dequeue();
               if (popp == -1)
               {
                    printf("\nQueue underflow");
               }
               else
               {
                    printf("\nRemoved element is %d", popp);
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