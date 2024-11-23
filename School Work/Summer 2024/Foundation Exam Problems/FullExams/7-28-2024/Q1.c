/* ) (5 pts) DSN (Dynamic Memory Management in C)
Suppose we have a function that is designed to take in a large string and trim it down to only the needed
size. The function is called trim_buffer. It takes in 1 parameter: the buffer, which is a string with a max
size of 1024 characters. It returns a string that is only the size needed to represent the valid characters in
the buffer. The function is implemented below.
Identify all of the errors (there are multiple errors) with the following trim_buffer function.*/

#define BUFFERSIZE 1024
// Pre-condition: buffer has a '\0' character at or before index
// BUFFERSIZE-1.
// Post-condition: returns a pointer to a dynamically allocated
// string that is a copy of the contents of buffer,
// dynamically resized to the appropriate size.
char * trim_buffer(char * buffer) {
char *string;
int length;
 while (length < BUFFERSIZE && buffer[length] != '\0')
 length++;
 string = malloc(sizeof(char) * (length));
 length = 0;
 while ((string[length] = buffer[length]) != '\0')
 length++;
 return;
}

//Errors: 