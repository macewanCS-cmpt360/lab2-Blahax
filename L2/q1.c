// SPDX-License-Identifier: GPL-2.0+
// Lab 2: Brandon Carl

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* Question 1:
 * The variable x is set to 100 before forking. After forking, the value
 * of x remains the same as before forking. Both the parent and child are
 * allowed to manipulate x. The child adds 1 while the parent adds 10. The
 * system ends up printing the parent first, and then the child. Each one
 * is allowed to run independantly once forked, so each runs to completion
 * without modifying the other's value.
 */

int main(void)
{

int x = 100;
int f = fork();

printf("The value of x is %d before everything.\n", x);
if (f < 0) {
		fprintf(stderr, "Fork failed.\n");
		exit(1);
} else if (f == 0) {
		printf("The value of x is %d after forking to Child\n", x);
		x++;
		printf("The value of x is %d in the Child.\n", x);
} else {
		printf("The value of x is %d after forking to Parent\n", x);
		x += 10;
		printf("The value of x is %d in the Parent\n", x);
}
printf("The final value of x is %d\n", x);
return 0;
}
