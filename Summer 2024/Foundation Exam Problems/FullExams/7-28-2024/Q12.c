//What is the output of the following program?

#include <stdio.h>
int main() {
 int n = 182, i = 0;
 while (n > 0) {
 if ((n & (1<<i)) > 0) {
 printf("%d\n", (1<<i));
 n ^=(1<<i);
 }
 i++;
 }
 return 0;
}
