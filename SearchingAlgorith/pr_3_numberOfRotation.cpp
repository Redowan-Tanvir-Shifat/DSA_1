/* Find the number of rotation in a sorted circular array... */ 

#include <iostream>
using namespace std;

int findNumberOfRotation(int arr[], int size) {
    int low = 0;
    int high = size - 1 ;

    if(arr[low] < arr[high]) {  // Already sorted...
        return 0;
    }

    while(low <= high) {
        int mid = (low + high) / 2;

        int next = (mid+1) % size;  // This formula for cicular array...
        int prev = (mid-1+size) % size;  // This formula for cicular array...

        if(arr[mid] < arr[next] && arr[mid] < arr[prev]) {
            return size - mid;
        }
        else if(arr[mid] < arr[high]) {  // That means right side all ok..check left side..
            high = mid -1;
        }
        else {
            low = mid + 1;
        }
    }
    return -1;
} 

int main() {
    int arr[10] = {3, 4, 5, 6, 7, 8, 9, 0, 1, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    if(findNumberOfRotation(arr, size) == 0) {
        cout << "The number of rotation is: " << findNumberOfRotation(arr, size);
    }
    else if(findNumberOfRotation(arr, size) != -1) {
        cout << "The number of rotation is: " << findNumberOfRotation(arr, size) << endl;
    }
}