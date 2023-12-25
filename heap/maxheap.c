//MAX HEAP
/*in max heap the input value after being inserted into array is sent 
to upheap function.here the input value is compared with the parent 
node . if the value is greater than parent node it will swap itself with each index and 
reach the parent node and become the parent node*/
#include<stdio.h>
#include<stdlib.h>
int arr[100000];
int size=0;


void swap(int a,int b){
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}

int parent(int index){
    return (index -1)/2;
}

void upheap(int index){
    if(index==0){
        return;
    }
    int p=parent(index);
    if(arr[index]>arr[p]){
        swap(index,p);
        upheap(p);
    }
}
/*the input data from the main is passed into the insert function 
the global variable size whose size is initially  0 increases by 
1 and the value is assigned in a[0].  */
void insert(int value){
    arr[size++]=value;
    upheap(size-1);
}

void downheap(int index){
    if(size==0){
        return;
    }
    int max=index;
    int left=(2*index)+1;
    int right=(2*index)+2;
    if(left<size && arr[left]>arr[max]){
        max=left;
    }
    if(right<size && arr[right]>arr[max]){
        max=right;
    }
    if(max!=index){
        swap(index,max);
        downheap(max);
    }
}

int rem(){
    if(size==0){
        return -1;
    }
    int x=arr[0];
    // if(size!=0){
        arr[0]=arr[size-1];
        size--;
        downheap(0);
    // }
    return x;
}

int main(){
    int x=1;
    printf("enter the elements into the heap\n -1 when done");
    while(x){
        scanf("%d",&x);
        if(x==-1){
            break;
        }
        insert(x);
    }
    int S_arr[size];
    int sortedsize=size;
    int i=0;
    while(size!=0){
        S_arr[i++]=rem();
    }
    for(int i=0;i<sortedsize;i++){ 
        printf(" %d ",S_arr[i]);
    }
    return 0;
}