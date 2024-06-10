#include <iostream>

void insertionSort(int arr[], int size) {
    for(int i = 1; i < size; i++) {
        
        int key = arr[i];
        int j = i - 1; 

        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}


int main() {
    int arr[] = {2, 3, 6, 5, 4, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, size);

    for(int i = 0; i < size; i++) {
        std::cout << " " << arr[i];
    }
}