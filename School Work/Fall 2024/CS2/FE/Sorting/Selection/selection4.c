#include <stdio.h>
#include <stdlib.h> 



void swap(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


void selection(int * p, int n){

    for(int i = 0; i < n - 1; i ++){
        int min = i;
        for(int j = i + 1; j < n; j ++){
            if(p[j] < p[min]){
                min = j;
            }
            
        }
        if(min != i){
            swap(p[i] , p[min]);
        }
    }
}