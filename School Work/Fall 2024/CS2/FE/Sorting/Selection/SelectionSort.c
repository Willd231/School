#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection(int *p, int n) {
    for (int i = 0; i < n - 1; i++) {
        // Find the minimum element in the unsorted part of the array
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (p[j] < p[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element
        if (minIndex != i) {
            swap(&p[i], &p[minIndex]);
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