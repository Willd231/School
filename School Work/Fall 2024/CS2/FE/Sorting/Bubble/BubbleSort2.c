#include <stdio.h>
#include <stdlib.h> 







void bubbleSort(int* p, int length){
    int temp = 0;
    for(int i = 0; i < length - 1; i++ ){
        for(int j = 0; j < length - i - 1; j++){
            if(p[j + 1 ] < p[j]){
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp; 
            }
        }
    }

}


int main(){

    int n = 0;
    printf("How large is your array?: ");
    scanf("%d", &n);

    int *p = malloc(sizeof(int) * n); 

    printf("Enter the values of your array: ");
    for(int i = 0; i < n; i ++){
        scanf("%d", &p[i]);
        }

    bubbleSort(p, n);

    printf("Here is your array sorted");
    for(int i = 0; i < n; i++){
        printf("%d\t", p[i]);
    }

    free(p); 
return 0;

}