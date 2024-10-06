/*  William Dellinger
    Script assignment 3
    6/16/2024
    Cop 3502
*/


#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


//fuction to reverse a string using pointers 
void reverseString(char *str){
//initialize the first and last characters to pointers
char *start = str;
char *end  = str + strlen(str) -1 ; 
//swapping each until the middle essentially
while(start < end){
    char temp = *start; 
    *start = *end; 
    *end = temp; 

    start++;
    end--;
}
}






//function to check if a string is a palindrome using recursion 
bool isPalindromeRecursive(char *str1, int start, int end){
    //base case 1 
    if(start>=end){
        return true;
    }

    //base case 2 returning false if the front and end arent equal 
    if(str1[start] != str1[end]){
        return false;
    }
    //returning new starts and ends to iterate through the whole word
    return isPalindromeRecursive(str1, start + 1, end -1);
}

bool isPalindrome(char str1[]){
int len = strlen(str1); 
//base case 
if (len == 0 ){
    return true; 
}
return isPalindromeRecursive(str1, 0, len-1);
}







//function to count vowels using recursion
int countVowelsRecursive(char *str2, int index){
    if(index>=strlen(str2)){
        return 0; 
    }
    //put all the current characters to lowercase so i dont have to have another set of conditionals 
    char current = tolower(str2[index]);
    //lowecase cases
    if(current == 'a' || current == 'e' || current == 'i' || current == 'o' || current  == 'u'){
        return 1 + countVowelsRecursive(str2, index + 1);
    }
    else{
        return countVowelsRecursive(str2, index + 1); 
    }
}
//main function calling the other one recursively
int countVowels(char *str2){
return countVowelsRecursive(str2, 0);
}



int main(){
    //same format for all three

    //declare string
    char str[10]; 
    //print statement specifying which it is 
    printf("Enter the string to be reversed ");
    //user input
    scanf("%s", str); 
    //function call
    reverseString(str);
    //print result
    printf("%s\n", str);
    


    char str1[10]; 
    printf("Enter the string to be checked if it is a palindrome: ");
    scanf("%s", str1); 
    printf("%s is %s\n", str1, isPalindrome(str1) ? "a palindrome" : "not a palindrome");
    


    char str2[10]; 
    printf("Enter the string to have its vowels counted: ");
    scanf("%s", str2); 
    printf("The amount of vowels in your word is %d", countVowels(str2)); 

    



}