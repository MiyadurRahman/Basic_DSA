#include<stdio.h>
#include<stdbool.h>

void printArray(int arr[], int n)
{
    printf("The elements of the array: ");
    for(int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubble_sort(int arr[], int n)
{
    for(int i=n-2; i>=0; i-=1)
    {
        bool swapped = false;

        for(int j=0; j<=i; j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        printArray(arr, n);

        if(swapped == false)
        {
            break;
        }
    }
}


int main()
{
    int n = 6;
    int arr[n] = {7, 8, 9, 2, 4, 3};
    printArray(arr, n);
    bubble_sort(arr, n);

    return 0;
}