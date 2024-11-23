#include <stdio.h>
#include <stdlib.h>





void insertion(int * p, int n){


//loop through the array
for(int i = 0; i<n; i++){
    //set the index value to iterate through the array
    int index = p[i];
    //set j = i - 1 
    int j = i-1;

    //starting when j os greater than the index
    while(j >= 0 && p[j] > index){
        //swap the next one and the current
        p[j + 1] = p[j];
        //decrement the j value
        j=j-1;
    }

    p[j+1] = index;
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