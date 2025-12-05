#include<stdio.h>

int _upper_bound(int arr[], int n, int key)
{
    int low = 0;
    int high = n-1;
    int answer = -1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] > key)
        {
            answer = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return answer;   
}

int _lower_bound(int arr[], int n, int key)
{
    int low = 0;
    int high = n-1;
    int answer = -1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] >= key)
        {
            answer = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return answer; 
}

int main()
{
    int n = 5;
    int arr[n] = {5, 7, 9, 12, 15};
    int key = 5;

    printf("%d\n", _upper_bound(arr, n, key));
    printf("%d\n", _lower_bound(arr, n, key));

    return 0;
}
