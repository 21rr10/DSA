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

void mergeSort(int a[],int start,int end){
    int mid=start+(end-start)/2;
    if(start>=end){
        return;
    }
    mergeSort(a,start,mid);//left part
    mergeSort(a,mid+1,end);//right part
    merge(a,start,mid,end);
}
void merge(int a[],int start,int mid,int end){
    int temp[end-start+1];
    int i=start,j=mid+1,k=0;

    while(i<=mid &&j<=end){
        if(a[i]<a[j]){ 
            temp[k]=a[i];
            i++;
        }
        else{
            temp[k]=a[j];
            j++;
            
        }k++;}
    while (i<=mid)
    {
        temp[k++]=a[i++];
    }

    while(j<=end){
        temp[k++]=a[j++];
    }

    for(k=0,i=start;k<end-start+1;k++,i++){
        a[i]=temp[k];
    }
    
    }
    


int main(){
    
    printf("enter the size of the array");
    scanf("%d",&n);
    int a[MAX];
    printf("enter the el of the array");
    int i;
    for(i=0;i<n;i++){
        scanf("%d\t", &a[i]);
    }

    mergeSort(a,0,n-1);
    print(a);
}