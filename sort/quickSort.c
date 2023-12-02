#include<stdio.h>
#include<stdlib.h>


#define MAX 100
static int n;


void print(int a[]){
    int i;
    for(i=0;i<n;i++){
        printf("%d\t", a[i]);
    }
    printf("\n"); 
}

void quickSort(int a[],int start,int end){
    
    if(start>=end){
        return;
    }
    int pivot= partition(a,start,end);
    quickSort(a,start,pivot-1);
    quickSort(a,pivot+1,end);
   
}
int  partition(int a[],int start,int end){
    int pivot=a[end];
    int i=start-1;

    for(int j=start;j<end;j++){
        if(a[j]<=pivot){
             i++;
             int temp=a[j];
             a[j]=a[i];
             a[i]=temp;
        }
    }i++;
    int temp=pivot;
    a[end]=a[i];a[i]=temp;
    return i;
    
    }
    


int main(){
    
    printf("enter the size of the array");
    scanf("%d",&n);
    int a[MAX];
    printf("enter the el of the array");
    int i;
    for(i=0;i<n;i++){
        scanf("%d", &a[i]);
    }

    quickSort(a,0,n-1);
    print(a);
}