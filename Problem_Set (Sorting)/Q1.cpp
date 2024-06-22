/* Find the Max Element from an Array */
#include <iostream>

void insertionSort(int arr[], int size) {
    for(int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key; 
    }
}

int main() {
    int arr[] = {3, 10, 20, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, size);

    std::cout << "Max Element: " << arr[size-1];

    return 0;
}