#include <stdio.h>


/*The linear search algorithm iterates through each element of the array until the element the user 
requests is found or the end of the array is reached and the element is not found.
Best case time complexity: O(1) (if the element is found at the first position).
Worst case time complexity: O(n) (if the element is found at the last position or not found at all).*/


int linearSearch(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            printf("The number you requested does exist in this array and its index is: %d\n", i);
            return i;
        }
    }
    printf("The element you requested does not exist in this array\n");
    return -1;
}

/*The algorithm iterates through each element of the array once to find the max element.
Time complexity: O(n), where n is the num of elements in the array.*/

int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Driver function
int main() {
    int arr[] = {1, 4, 5, 3, 2, 6, 5, 4, 3, 6, 7, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int valueToSearch = 3;

    // linear search
    linearSearch(arr, size, valueToSearch);

    // findMax
    int maxElement = findMax(arr, size);
    printf("The maximum element in the array is: %d\n", maxElement);

    return 0;
}
