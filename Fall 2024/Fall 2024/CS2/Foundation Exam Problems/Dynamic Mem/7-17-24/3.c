/* (10 pts) DSN (Dynamic Memory Management in C)
Consider allocating space for an array of arrays, where each of the individual lengths of the different one
dimensional arrays may differ. For example, we might want 5 arrays, which have lengths 10, 5, 20, 100
and 50, respectively. Write a function makeArray that takes in an array of integers itself and the length
of that array (so for the example above the first parameter would be the array storing 10, 5, 20, 100 and
50 and the second parameter would have a value of 5) and allocates space for an array of arrays where
each of the individual arrays have the lengths specified by the values of the input array. Before returning
a pointer to the array of arrays, the function should store 0 in every element of every array allocated.
*/


int** makeArray(int* lengths, int numarrays) {


arraylist *array = malloc(sizeof(numarrays))


}

//was very stuck on this one 
//end of my submission



//beg of the correct submission

int** makeArray(int* lengths, int numarrays) {
 int** array = malloc(sizeof(int*)*numarrays); // this declares a pointer to a pointer of integers named array
 //allocates memory for all of the numarrays 
 int i;
 for (i=0; i<numarrays; i++)
 array[i] = calloc(lengths[i], sizeof(int)); //accesses the ith element which is a pointer to a sub array, allocates
 //mem for that and initializes it to zero
 return array;
}
//differences between this and my submission are very large
//in this submission they use a double pointer to an 'array'
//they then allocate