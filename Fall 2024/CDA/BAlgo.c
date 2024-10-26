#include <stdio.h>


int toBin(){
int arr1[8], arr2[8], number1[8], number2[8], count = 0, zeros = 0, num1, num2, temp1, temp2;
printf("Enter the two numbers you would like to multiply: ");
fscanf("%d %d", &num1, &num2);



for(int i = 0; i<7; i++){
    if(num1 % 2 == 0){
        arr1[i] == 0;
    }
    if(num2 % 2 == 0){
        arr2[i] == 0;
    }
    elif(num1 % 2 != 0){
        while(temp1 != 0){
        temp1 = num1; 
        while( 1 + temp * 2 != num1){
            temp -=1; 
        }
        arr1[i] = temp;
        }
    }
count +=1; 
}

zeros = 8 - count;
}










int main(){






}