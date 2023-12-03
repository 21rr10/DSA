#include <stdio.h>
#include<stdlib.h>
#define MAX 10

int top=-1;

int stack[MAX];

void push(){
    int el;
    if(top==MAX-1){
        printf("stack overflow");
        return;
    }
    printf("enter the element to input");
    scanf("%d",&el);
    stack[++top]=el;

}

void pop(){
    if(top==-1){
        printf("stack empty");
        return;
    }
    printf("the popped item is %d ",stack[top]);
    top--;
}

void display(){
    int i;
    printf("The elements of the stack are\n ");
    for(i=top;i>-1;i--){
        printf("\t%d\n ",stack[i]);
    }
}


int main(){
    int choice;
    while (choice !=4){
        printf("Menu\n1. push\n2. pop\n 3.display\n 4. exit\n\nenter you choice");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: push();
            break;
        case 2: pop();
            break;
        case 3:display();
            break;
        case 4: printf("exit");exit(0);
        default:printf("enter right choice");
            
        }


    }
}