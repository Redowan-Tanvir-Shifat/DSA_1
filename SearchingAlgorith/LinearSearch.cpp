#include <iostream>
using namespace std;

// Just travel the array and check the value of each index is equal to the key value or not....
int linearSearch(int arr[], int size, int key) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == key) {
            return i;
        }
    }
    return -1;  // -1 means that the key value is missing in the given array...
}

int main() {
    int arr[10] = {2, 3, 4, 6, 67, 0, 78, 98, 8, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    int key; // The value we will be searching from the given array...
    cout << "Enter a number for the key value: ";
    cin >> key;

    if(linearSearch(arr, size, key) != -1) {
        cout << "Found the value at the index: " << linearSearch(arr, size, key) << endl;
    } else {
        cout << "Not found!";
    }
}