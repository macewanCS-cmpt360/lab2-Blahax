// SPDX-License-Identifier: GPL-2.0+
// Lab 2: Brandon Carl

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* Question 3:
 * The sleep function can be subbed in for wait, however it is not as
 * efficient as just using the wait command.
 */

int main(void)
{
int f = fork();

if (f < 0) {
		fprintf(stderr, "Fork failed.\n");
		exit(1);
} else if (f == 0) {
		printf("Hello\n");
} else {
		sleep(1);
		printf("Goodbye\n");
}
return 0;
}
