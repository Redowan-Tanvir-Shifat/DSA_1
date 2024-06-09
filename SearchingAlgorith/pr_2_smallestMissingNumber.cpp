/* Find  the smallest missing number in a sorted array of non-negative numbers...*/

// Given sorted array that means we need to go for binary search....
// If no number is missing then we return next index of the last index of given array..

#include <iostream>
using namespace std;

int findSmallestMissingNumber(int arr[], int size) {
    int low = 0;
    int high = size - 1;

    if(arr[0] != 0) {
        return 0;
    }
    if(arr[size-1] == size-1) {
        return size;
    }

    while(low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] != mid && arr[mid-1] == mid-1) { 
        // (mid-1) index has value of (mid-1) but mid has not value of mid...
        //So, mid is the missing number...
            return mid;
        }
        else if (arr[mid] != mid) {
        // it means missing number is in left side. so check left... 
            high = mid - 1;
        }
        else if (arr[mid] == mid) {
        // it means missing number is in right side. so check right side... 
            low = mid + 1;
        }
    }
    return -1;
}

int main() {
    int arr[10] = {0, 1, 2, 3, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Missing number at index: " << findSmallestMissingNumber(arr, size) << endl;
}