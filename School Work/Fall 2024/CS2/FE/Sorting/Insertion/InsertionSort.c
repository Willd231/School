#include <stdio.h>
#include <stdlib.h>




void insertionSort(int * arr, int n){
    int temp = 0; 



}





int main(){
    int n = 0;
    print("Enter size of your array here: ");
    scanf("%d", &n);


    int * arr = malloc(sizeof(int) * n);


    print("Enter the values of your array here: ");
    for(int i = 0; i < n; i ++){
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, n);


    print("Here is your sorted array: ");
    for(int i = 0; i < n; i++){
        printf("%d" , arr[i]);
    }

    return 0;
}