/*(5 pts) DSN (Dynamic Memory Management in C)
Suppose we have a structure to store information about cases of juice. The structure is shown below: the
name of the juice in the case is statically allocated. The structure also contains the number of containers
of juice in that case. Complete the function below so that will takes 2 parameters: the name of a juice and
an integer. Your function should create a new case of juice by allocating space for it, copying in the
contents specified by the formal parameters into the struct and returning a pointer to the new case. You
may assume that the pointer new_name is pointing to a valid string storing the name of a juice for which
memory has already been allocated and is 127 or fewer characters.
*/

#include <string.h>
#include <stdlib.h>
struct juice_case {
char name[128];
int num_bottles;
};

struct juice_case* create_case(char *new_name, int new_number) {

juice_case*new_case = malloc(sizeof(juice_case));
new_case->name = new_name;
new_case->num_bottles = new_number;

return new_case;


}

//my submission ends here



//correct submission

struct juice_case* create_case(char *new_name, int new_number) {
// allocate space for a new case – 2 points
struct juice_case *new_case = malloc(sizeof(struct juice_case));
// add the name for the case – 1 point
 strcpy(new_case->name, new_name);
// add the number for the case – 1 point
 new_case->num_bottles = new_number;
// return the case – 1 point
 return new_case;


 // the main differences are that i did not specify struct when i was allocating memory because there is not typedef
 //also i guess it wanted it wanted the original name to be copied in the new case i have missed that twice in a 
 //row now i need to examine the problem description again
//other than that i got most everything right, this was a pretty simple problem 4/5 if we ignore the fuckup with the 
//typedef lol