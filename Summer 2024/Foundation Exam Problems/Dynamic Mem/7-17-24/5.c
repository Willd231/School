/*The following function has 5 memory management issues, each one occurring on a different one of the 17
labeled lines of code. Please clearly list which five lines of code have the errors on the slots provided
below. Please list exactly five unique line numbers in between 1 and 17, inclusive. An automatic
grade of 0 will be given to anyone who lists MORE than 5 line numbers.*/
int n = 10; // line 1
int *p1, *p2, *p3, **p4; // line 2
char str1[100] = "test string "; // line 3
char *str2; // line 4
strcpy(str2, str1); // line 5
p1 = (int *)malloc(n * sizeof(int)); // line 6
p2 = (int *)malloc(n * sizeof(int)); // line 7
for(int i=0; i<n; i++) // line 8
p1[i] = rand()%100; // line 9
p2 = p1; // line 10
*p3 = 50; // line 11
p4 = (int **) malloc(n * sizeof(int*)); // line 12
for(int i=0; i<n; i++) // line 13
p4[i] = -5; // line 14
free(p1); // line 15
free(p2); // line 16
free(p4); // line 17


//my submission:
//Lines with Memory Management Errors: _______ , _______ , _______ , line 11 , line 14 