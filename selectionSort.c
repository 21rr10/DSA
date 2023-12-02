#include <stdio.h>

#define MAX 100
static int n;

void selectionSort(int a[]){
            int i, j, min, temp;
            
            // Sort the array using selection sort
            for (i = 0; i < 9; i++)
            {
                min = i;
                for (j = i + 1; j < 10; j++)
                {
                    if (a[j] < a[min])
                    {
                        min = j;
                    }
                }
                // Swap the minimum element with the current element
                temp = a[i];
                a[i] = a[min];
                a[min] = temp;
            }
}

void print(int a[]){
    int i;
    printf("\nSorted numbers in ascending order:\n");
            for (i = 0; i < 10; i++)
            {
                printf("%d ", a[i]);
                printf("\n");
            }
}

int main()
        {
            int a[10];
            int i, j;
            printf("Enter 10 numbers:\n");
            for (i = 0; i < 10; i++)
            {
                scanf("%d", &a[i]);
            }
            selectionSort(a);
            print(a);
        

            return 0;
        }
