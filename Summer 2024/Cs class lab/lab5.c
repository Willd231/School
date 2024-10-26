#include <stdio.h>
#include <stdlib.h>


//swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function similar to the quick sort one 
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  
    int i = (low - 1);      //smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++;    // Increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quickselect function to find the k-th smallest element in the array
int quickSelect(int arr[], int low, int high, int k) {
    if (low <= high) {
        // get the pivot index
        int pivotIndex = partition(arr, low, high);

        // If pivotIndex is the k-th element return the current value of pivotindex
        if (pivotIndex == k - 1)
            return arr[pivotIndex];

        // If pivotIndex is greater than k, search in the left 
        if (pivotIndex > k - 1)
            return quickSelect(arr, low, pivotIndex - 1, k);

        // If pivotIndex is less than k, search in the right 
        return quickSelect(arr, pivotIndex + 1, high, k);
    }
    return -1;  // If k is out of bounds
}

//print function 
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main() {
    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    printf("Given array: ");
    printArray(arr, n);
    int result = quickSelect(arr, 0, n - 1, k);
    if (result != -1)
        printf("%d-th smallest element is %d\n", k, result);
    else
        printf("Element out of bounds\n");
    return 0;
}
