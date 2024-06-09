#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key) {
    // low and high need for calculating midPoint...
    int low = 0;   // Lower index of the array...
    int high = size - 1;  // Higher index of the array...

    while(low <= high) {
        int mid = (low + high) / 2;

        if (key == arr[mid]) { // if key value as mid value then we can say we found the number....
            return mid;
        }
        else if (key > arr[mid]) {
            // Check right side...
            low = mid + 1; // we need to check in right side thats why we have to update low value...
        }
        else if (key < arr[mid]) {
            // Check left side...
            high = mid - 1; // we need to check in left side thats why we have to update low value...
        }
    }
    return -1;
}


int main() {
    // Firstly in binary search array must be sorted...
    int arr[10] = {0, 1, 4, 6, 9, 10, 28, 32, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    int key; // We need to search this value from the given array...
    cout << "Enter a number for the key value: ";
    cin >> key;

    if(binarySearch(arr, size, key) != -1) {
        cout << "Found the value at the index: " << binarySearch(arr, size, key) << endl;
    } else {
        cout << "Not found!";
    }
}