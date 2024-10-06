#include <stdio.h>

/*This function finds the requested value through the method of binary search
The worst case time complexity scenario for this is Olog(n)
The best case time complextity for this is O(1)*/
int binarySearch(int arr[], int size, int value) {
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == value) {
            printf("The number you requested does exist in this array and its index is: %d\n", mid);
            return mid;
        }
        
        if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    printf("The element you requested does not exist in this array\n");
    return -1;
}






/*This function finds the minimum value in an array of integers
the worst case time complexity scenario for this algo is O(n)
and the best case time complexity scenario for this algo is O(n) either way you have to iterate through every 
element in the array*/
int findMin(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}


// Driver function for binary search
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int valueToSearch = 7;

    binarySearch(arr, size, valueToSearch);
    

    int minElement = findMin(arr, size);
    printf("The minimum element in the array is: %d\n", minElement);


    return 0;
}
