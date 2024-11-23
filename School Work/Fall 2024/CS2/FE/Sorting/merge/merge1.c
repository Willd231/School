#include <stdio.h>
#include <stdlib.h>




void merge(int * p, int left, int mid, int right){

    int n1 = mid - left + 1;
    int n2 = right - mid;


    int L[n1];
    int R[n2];


    for(int i = 0; i < n1; i ++){
        L[i] = p[left + i];
    }
    for(int j = 0; j < n2; j++){
        R[j] = p[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            p[k] = L[i];
            i++;
        }
        else{
            p[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        p[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        p[k] = R[j];
        j++;
        k++;
    }
    
}



void mergesort(int * p, int left, int right){
    if(left < right){
         int mid = left + (right - left)/2;

         mergesort(p, left, mid);
         mergesort(p, mid + 1, right);

         merge(p, left, mid, right);
    }
}
















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
