#include<stdio.h>

void printArray(int arr[], int n)
{
    printf("The elements of the array: ");
    for(int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertion_sort(int arr[], int n)
{
    for(int i=1; i<n; i++)
    {
        int key = arr[i];
        int c_index = i;

        while(c_index>0 && arr[c_index-1]>key)
        {
            arr[c_index] = arr[c_index-1];
            c_index = c_index - 1;
        }

        arr[c_index] = key;

        printArray(arr, n);
    }
}


int main()
{
    int n = 6;
    int arr[n] = {7, 9, 8, 2, 4, 3};
    printArray(arr, n);
    insertion_sort(arr, n);

    return 0;
}
