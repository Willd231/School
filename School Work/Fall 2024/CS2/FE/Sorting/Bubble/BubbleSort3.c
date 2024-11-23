#include <stdio.h>
#include <stdlib.h>




void bubble(int * p, int n){
    int temp = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - i + 1; i++){
            if(p[j+1] < p[j]){
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }



}





int main(){

int n;
scanf("%d", &n);
int * p = malloc(sizeof(int) * n);

for(int i = 0; i<n; i++){
    scanf("%d", &p[i]);
}

bubble(p, n);

for(int i = 0; i < n; i++){
    printf("%d", p[i]);
}


}