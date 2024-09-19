/* Find the Smallest Element from an Array */
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
    int arr[] = {8, 10, 3, 6, 9, 2, 4, 15, 23};
    int size = sizeof(arr) / sizeof(arr[0]);

    int n = 4;

    insertionSort(arr, size);

    std::cout << "<--Sorted array-->\n";
    for(int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";  
    }

    std::cout << '\n';
    std::cout << '\n';

    std::cout << "nth smallest number: " << arr[n-1];

    return 0;
}