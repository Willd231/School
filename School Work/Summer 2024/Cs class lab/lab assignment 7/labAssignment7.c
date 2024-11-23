#include <stdio.h>
#include <stdlib.h>

 
int arr1[9] = {97 , 16 , 45 , 63 , 13 , 22 , 7 , 58 , 72};
int arr2[9] = {90 , 80 , 70 , 60 , 50 , 40 , 30 , 20 , 10};

int nS7,nS13,nS16,nS22,nS97,nS45,nS63,nS58,nS72;
int nS90,nS80,nS70,nS60,nS50,nS40,nS30,nS20,nS10;


void compare(){

int temp;

for(int i = 0; i<9;i++){
    for(int j = 0; j< 9 - i - 1; j++){
        if(arr1[j]>arr1[j+1]){

            temp = arr1[j];
            arr1[j] = arr1[j+1];
            arr1[j+1]= temp;
        }





}
}


    
}










int main(){

compare();

int i = 0;

for(i; i < 9; i++)
{

printf("%d", arr1[i]);
}
return 0;

}
