// Min heap
 
#include <stdio.h>
#include <stdlib.h>
int arr[10000000];
int size=0;


void swap(int a,int b){
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}

int parent(int index){
    return (index-1)/2;
}

void upheap(int index){
    if(index==0){
        return;
    }
    int p=parent(index);
    if(arr[index]<arr[p]){
        swap(index,p);
        upheap(p);
    }
}

void insert(int value){
    arr[size++]=value;
    upheap(size-1);
}

void downheap(int index){
    if(size==0){
        return;
    }
    int min=index;
    int left=(index*2)+1;
    int right=(index*2)+2;
    if(left<size && arr[left]<arr[min]){
        min=left;
    }
    if(right<size && arr[right]<arr[min]){
        min=right;
    }
    if(min!=index){
        swap(index,min);
        downheap(min);
    }
}

int rem(){//delete function basically
    if(size==0){
        return -1;
    }
    int x=arr[0];
    if(size!=0){
        arr[0]=arr[size-1];
        size--;
        downheap(0);
    }
    return x;
}


int main(){
   
    int x=1;
    while(x){
        scanf("%d",&x);
        if(x==-1){
            break;
        }
        insert(x);
    }
    int sorted[size];
    int sortedsize=size;
    int i=0;
    while(size!=0){
        sorted[i++]=rem();
    }
    for (int i = 0; i < sortedsize; i++){
        printf("\t %d",sorted[i]);
    }
    return 0;
}