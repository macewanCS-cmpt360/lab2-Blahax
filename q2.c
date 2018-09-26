// SPDX-License-Identifier: GPL-2.0+
// Lab 2: Brandon Carl

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

/* Question 2:
 * File was not being created. Unsure why. Both the parent and child
 * should be able to access the document from the file desc and change
 * it. This is why in the demos from class, the parent was made to just
 * wait instead of editing anything, so as to not create problems. With
 * both writing to the file, one should overwrite the other (whichever
 * executes last will overwrite).
 */

int main(void)
{

int filedesc = open("./q2.output", O_RDWR | O_APPEND | O_TRUNC);
int f = fork();

write(filedesc, "Hello from the outside\n", 50);
if (f < 0) {
		fprintf(stderr, "Fork failed.\n");
		exit(1);
} else if (f == 0) {
		write(filedesc, "Hello child\n", 50);
} else {
		write(filedesc, "Hello parent\n", 50);
}
return 0;
}
