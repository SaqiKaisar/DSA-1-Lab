#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

void selectionSort(int arr[], int n)
{
    for(int i=0; i<n-1; i++){
        int min_idx = i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[min_idx]){
                min_idx = j;
            }
        }
        int temp = arr[i];
        arr[i]=arr[min_idx];
        arr[min_idx] = temp;
    }
}


void printArray(int arr[], int N)
{
    int i;
    for (i = 0; i < N; i++)
        printf("%d ", arr[i]);

    printf("\n");
}


int main()
{
    int n, arr[MAX_SIZE];
    printf("Selection Sort\n");
    printf("Input the number of elements to be sorted: \n");
    scanf("%d", &n);
    printf("Input the values to be sorted: \n");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    selectionSort(arr, n);
    printf("Sorted Array: \n");
    printArray(arr, n);
    return 0;
}
