/*Fall 2016 Data Structures Exam, Part A
Page 2 of 4
1) (10 pts) DSN (Dynamic Memory Management in C)
Consider the following struct, which contains a string and its length in one nice, neat package:
typedef struct smart_string {
 char *word;
 int length;
} smart_string;
Write a function that takes a string as its input, creates a new smart_string struct, and stores a new copy
of that string in the word field of the struct and the length of that string in the length member of the
struct. The function should then return a pointer to that new smart_string struct. Use dynamic memory
management as necessary. The function signature is:
*/



// my initial submission
#include <stdio.h>
#include <stdlib.h>

typedef struct smart_string {
 char *word;
 int length;
} smart_string;

smart_string *create_smart_string(char *str) {

    smart_string*newsmart_string = (smart_string*)malloc(sizeof(smart_string));
    newsmart_string ->word = word;
    newsmart_string->length = length; 
    newsmart_string*newstring;
    return newstring;

}

/*
the correct answer: */


smart_string *create_smart_string(char *str) {
 smart_string *s = malloc(sizeof(smart_string));
 s->length = strlen(str); 
 // this is different from my submission as the instructions told us to 
 //create a new copy of the new string and the version i created just took all the stats from the intial 
 //string and put it in the new one but thats incorrect, the right way to do it is to find the length of the 
 //new string 

 s->word = malloc(sizeof(char) * (s->length + 1));
 // this is different from my submission as it allocates memory for the new string 
 //
 strcpy(s->word, str);
 return s;
}





/*second part of the question: 
Now write a function that takes a smart_string pointer (which might be NULL) as its only argument,
frees all dynamically allocated memory associated with that struct, and returns NULL when it’s finished.
*/


//my submission:
smart_string *erase_smart_string(smart_string *s) {
    if(word != null){
        free(word);
        
    }

    return NULL;
}




//the correct submission:
smart_string *erase_smart_string(smart_string *s) {
    if(s != null){
        free(s->word);
        free(s);
        /*this varies greatly from my submission as i tried to free a component of the struct without 
        accessing it correctly
        in this submission first the word component is accessed from the pointer to the struct that was created
        in the first function : s
        then it frees that pointer to the struct
        */
    }

    return NULL;
}