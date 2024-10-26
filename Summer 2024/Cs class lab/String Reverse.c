#include <stdio.h>
#include <string.h>
#include <ctype.h> // for toupper() and tolower()

// Function to reverse a string with case sensitivity
void reverseString(char str[], int start, int end) {
    while (start < end) {
        // Swap characters
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        
        start++;
        end--;
    }
}

// Function to reverse words in a sentence
void reverseWords(char str[]) {
    int start = 0;
    int length = strlen(str);
    
    for (int end = 0; end <= length; end++) {
        if (str[end] == ' ' || str[end] == '\0') {
            // Found a word boundary or end of string, reverse the word
            reverseString(str, start, end - 1);
            start = end + 1; // Move to start of next word
        }
    }
    
    // Finally, reverse the entire string
    reverseString(str, 0, length - 1);
}

int main() {
    char str[] = "Hello, World!";
    
    // Reverse the entire string keeping case sensitivity
    reverseString(str, 0, strlen(str) - 1);
    printf("Reversed string with case sensitivity: %s\n", str);
    
    // Reverse sentence
    reverseWords(str);
    printf("Reversed words in sentence: %s\n", str);
    
    return 0;
}
