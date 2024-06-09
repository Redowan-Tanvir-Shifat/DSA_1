/* Find the last occurrence of a number in a sorted array...*/

// Given sorted array that means we need to go for binary search....

#include <iostream>
using namespace std;

int findLastOccurrence(int arr[], int size, int key) {
    int low = 0;
    int high = size - 1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if ((arr[mid] == key) && (arr[mid+1] != key)) {  // mid value != next value means last occurrence... 
            return mid;
        }
        else if (key >= arr[mid]) {
            low = mid + 1;
        }
        else if (key < arr[mid]) {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[10] = {2, 3, 3, 3, 9, 10, 28, 32, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    // int key = 3;

    int key;
    cout << "Enter a number for the key value: ";
    cin >> key;

    if(findLastOccurrence(arr, size, key) != -1) {
        cout << "Last occurrence at index: " << findLastOccurrence(arr, size, key) << endl;
    } else {
        cout << "Not found!";
    }
}