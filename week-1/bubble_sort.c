#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100
bool flag;

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++) {
        flag = false;
        for (j = 0; j < n - i - 1 ; j++) {
            if (arr[j] > arr[j + 1]){
                int temp;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = true;
            }
        }
        if (flag == false) break;
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
    printf("Bubble Sort\n");
    printf("Input the number of elements to be sorted: \n");
    scanf("%d", &n);
    printf("Input the values to be sorted: \n");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    bubbleSort(arr, n);
    printf("Sorted Array: \n");
    printArray(arr, n);
    return 0;
}
