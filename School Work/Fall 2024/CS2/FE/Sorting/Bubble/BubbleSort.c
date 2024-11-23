#include <stdio.h>



void bubbleSort(int arr[8] ,int n){

    int i, j, temp; 
    
    for(i = 0; i < n - 1; i++){
        for(j = 0 ; j < n - i - 1; j++){
            if(arr[j + 1] < arr[j]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }


}



int main(){



int arr[] = {4 , 5 , 6, 12 , 6 , 4, 23 , 5};
int length = (sizeof(arr)/sizeof(arr[0]));
bubbleSort(arr, length);
for(int i = 0; i < length; i++){
    printf("%d \t", arr[i] );
}

}