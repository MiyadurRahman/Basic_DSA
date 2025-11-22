#include <stdio.h>
void printArray(int arr[], int n)
{
    printf("The elements of the array: ");
    for(int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selection_sort(int arr[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        int min_index = i;

        for(int j=i+1; j<n; j++)
        {
            if(arr[j]<arr[min_index])
            {
                min_index = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;

        printArray(arr, n);
    }
}
int main()
{
    int n = 6;
    int arr[n] = {7, 8, 9, 2, 4, 3};
    printArray(arr, n);
    selection_sort(arr, n);

    return 0;
}