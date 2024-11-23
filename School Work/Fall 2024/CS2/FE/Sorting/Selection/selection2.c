#include <stdio.h>
#include <stdlib.h>


void swap(int *a, int *b){
    int temp; 
    temp = *a; 
    *a = *b; 
    *b = temp; 
}

void selection(int * p, int n){
    for(int i = 0; i < n - 1 ; i ++){
        int min = i;
        for(int j = i + 1; j < n; j++){
            if(p[j] < p[min]){
                min = j;
            }
        }
        if(min != i){
        swap(&p[i], &p[min]);
    }
    }
}







int main(){
    int n;
    scanf("%d", &n); 
    int * p = malloc(sizeof(int) * n);

    for(int i = 0; i < n; i ++){
        scanf("%d", &p[i]);
    }

    selection(p, n);

    for(int i = 0; i < n ; i ++){
        printf("%d", p[i]);
    }
}