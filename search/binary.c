#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int a[MAX];
int  bin();

int main(){
    int i;
    printf("enter the elements of the array");
    for(i=0;i<MAX;i++){
        scanf("%d",&a[i]);
    }
    int x=bin(a);
    
}

int  bin(int a[]){
    int key;
    printf("enter the key");
    scanf("%d",&key);
    int start=0,mid,end=MAX-1;
    mid=start+(end-start)/2;
    while(start<=end){

    
        if(a[mid]<key){
            start=mid +1;

        }
        else if(a[mid]>key){
            end=mid-1;
        }
        else {
            printf("element found %d",mid);return 1 ;

            }
    }
    printf("element not found ");
    return -1 ;
}
