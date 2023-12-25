#include <stdio.h>

#define MAX 100
static int len;

void insertionSort(int a[]){
            int i;
            
            // Sort the array using insertion sort
            for (i = 1; i < len; i++){
                 int curr=a[i];
                 int prev=i-1;
                 while(prev>=0 && a[prev]>curr){
                    a[prev+1]=a[prev];
                    prev--;
                    
                 }
                 
                 a[prev+1]=curr;
                }
            }


void print(int a[]){
    int i;
    printf("\nSorted numbers in ascending order:\n");
            for (i = 0; i < len; i++)
            {
                printf("%d ", a[i]);
                printf("\n");
            }
}

int main()
        {
            int a[MAX];
            int i, j;
            printf("enter the size of the array");
            scanf("%d",&len);
            printf("Enter %d numbers:",len);
            for (i = 0; i < len; i++)
            {
                scanf("%d", &a[i]);
            }
            insertionSort(a);
            print(a);
        

            return 0;
        }
