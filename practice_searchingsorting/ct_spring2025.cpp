#include <iostream>
using namespace std;

int binarySearch(int arr[], int target, int n) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {   
            low = mid + 1;      // go right
        }
        else {
            high = mid - 1;     // go left
        }
    }
    return -1; // if not found
}

int main() {
    int n = 7;
    int arr[n] = {35, 50, 55, 60, 65, 70, 85};

    int x = 60;
    int index = binarySearch(arr, x, n);

    if (index == -1) {
        cout << "Element not found\n";
        return 0;
    }

    int count = n - (index + 1);

    cout << "number of elements greater than " << x << " is: " << count << endl;

    return 0;
}
