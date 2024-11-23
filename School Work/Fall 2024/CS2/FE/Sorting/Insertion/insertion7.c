
#include <stdio.h>
#include <stdlib.h>







void insertion(int * p, int n){
    for(int i = 0; i < n; i ++){
        int temp = p[i];
        int j = i - 1;

        while(j >= 0 && p[j] > temp){
            p[j+1] = p[j];
            j--;
        }
        p[j+1] = temp;
    }
}







int main(){


int n;
scanf("%d", &n);

int *p = malloc(sizeof(int) * n);
for(int i = 0; i < n; i++)
{
    scanf("%d", &p[i]);
}


insertion(p, n);


for(int i = 0; i < n; i++){
    printf("%d", p[i]);
}

}
