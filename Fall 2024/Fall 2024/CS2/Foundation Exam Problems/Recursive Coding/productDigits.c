#include <stdio.h>
#include <stdlib.h>

int productdigits(int n){

    int num1 = 0;
    if(n>=100){
        num1 = n % 100;
        n = n - num1;
        return productdigits(n);
    }

    else if(n<100){
        num1 = 
    }


}

int main(){
    int n;

    printf("Enter the number: ");
    scanf("%d", &n);

    productdigits(n);

}