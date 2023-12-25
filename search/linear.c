#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int main(){
    int a[MAX];
    int i;

    printf("enter the elements of the array");
    for(i=0;i<MAX;i++){
        scanf("%d",&a[i]);
    }

    int x= lin(a);
    if(x== -1){
        printf("search unsuccess");

    }
    else printf("success %d",x);
    return 0;
    
}

int lin(int a[]){
    int key;
    printf("enter the key element");
    scanf("%d",&key);

    for(int i=0;i<MAX;i++){
        if(a[i]==key){
            
            return i;
        }
    }

    return -1;
}