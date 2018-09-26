// SPDX-License-Identifier: GPL-2.0+
// Lab 2: Brandon Carl

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

/* Question 7:
 * Nothing is printed, as the normal stdout to the terminal has been closed.
 * The child is unable to write anything after this point unless a new stdout
 * file pointer is set.
 */

int main(void)
{
int f = fork();

if (f < 0) {
		fprintf(stderr, "Fork failed.\n");
		exit(1);
} else if (f == 0) {
		close(STDOUT_FILENO);
		printf("Can you hear me?\n");
} else {
		int wc = wait(NULL);
}
return 0;
}
