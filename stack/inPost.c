//wap to convert an infix expression into its equivalent postfix expression
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

char stack[MAX];
char infix[MAX],postfix[MAX];
int top=-1;

void inToPost();
int precedence(char);
void print();
void push(char);
char pop();
int isEmpty();
int space(char);


int main(){
    //left paraentheses has the least precedence
    //normally brackets have the highest precedence
    printf("enter the infix expression:\n");
    gets(infix);

    inToPost();
    print();
    return 0;
}

void inToPost(){
    int i,j=0;
    char next,symbol;
    for(i=0;i<strlen(infix);i++){
        symbol=infix[i];
        if(!space(symbol)){//if symbol is not a whitespace
            switch(symbol){
                case '(':push(symbol);
                     break;
                case ')':while((next=pop())!='(')
                        postfix[j++]=next;
                     break;
                case '+':
                case '-':
                case '*':
                case '/':
                case '^':while(!isEmpty() && precedence(stack[top])>=precedence(symbol))
                            postfix[j++]=pop();
                         push(symbol);
                         break;
                default:postfix[j++]=symbol;
            }
        }
    }
    while(!isEmpty())
       postfix[j++]=pop();
    postfix[j]='\0';
}

int space(char c){
    //if symbol is a blank space or a tab
    if(c== ' '|| c=='\t')
       return 1;
    else
       return 0;
}

int precedence(char symbol){
    switch(symbol){
        //higher value is indicating greater precedence
        case '^':return 3;
        case '/':
        case '*':return 2;
        case '+':
        case '-':return 1;
        default:return 0;
    }
}

void print(){
    int i=0;
    printf("The equivalent posyfix expression is:\n");
    while(postfix[i]){
        printf("%c",postfix[i++]);
    }
    printf("\n");
}

void push(char c){
    if(top==MAX-1){
        printf("stack overflow\n");
        return;
    }
    stack[++top]=c;
}

char pop(){
    char c;
    if(top==-1){
        printf("stack undeflow\n");
        return;
    }
    c=stack[top];
    top=top-1;
    return c;
}

int isEmpty(){
    if(top==-1)
      return 1;
    else
      return 0;
}