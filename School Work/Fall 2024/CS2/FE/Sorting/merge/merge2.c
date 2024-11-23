#include <stdio.h>
#include <stdlib.h>






int main(){

    int n;
    scanf("%d", &n);
    int * p = malloc(sizeof(int) * n);
    for(int i = 0; i < n; i ++){
        scanf("%d", &p[i]);
    }

    mergesort(p, 0 ,n - 1);


    for(int i = 0; i < n; i ++){
        printf("%d", p[i]);
    }

    return 0;
}
