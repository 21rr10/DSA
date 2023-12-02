#include <stdio.h>

#define MAX 100
static int len;

void bubbleSort(int a[]){
            int i, j, temp;
            
            // Sort the array using bubble sort
            for (i = 0; i < len-1; i++){
                 for (j = 0 ; j < len-1-i; j++){
                    if (a[j] > a[j+1]){
                    
                        // Swap the minimum element with the current element
                        temp = a[j];
                        a[j] = a[j+1];
                        a[j+1] = temp;
                    }
                }
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
            bubbleSort(a);
            print(a);
        

            return 0;
        }
