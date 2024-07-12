#include <iostream>

void selectionSort(int arr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        int min_pos = i;
        for(int j = i + 1; j < size; j++) {
            if(arr[j] < arr[min_pos]) {
                min_pos = j;

            }
        }
        if(min_pos != i) {
            int temp = arr[i];
            arr[i] = arr[min_pos];
            arr[min_pos] = temp;
        }
    }
}


int main() {
    int arr[] = {2, 3, 6, 5, 4, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, size);

    for(int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
}