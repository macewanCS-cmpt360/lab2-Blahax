#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void)
{

	char *cmdline;
	char *token = NULL;
	int i, rc;
	char *args[10];

	cmdline = calloc(1, 1024);
	i = 0;

	printf("prompt> ");
	fgets(cmdline, 1024, stdin);
	fprintf(stderr, "[debug] cmdline = *%s*\n", cmdline);

	token = strtok(cmdline, "\n ");
	while (token != NULL) {
		//printf("%s\n", token);
		args[i++] = strdup(token);
		token = strtok(NULL, "\n ");
	}
	args[i] = NULL;

    int f = fork();

    if (f < 0) {
		fprintf(stderr, "Fork failed.\n");
		exit(1);
    } else if (f == 0) {
		close(STDOUT_FILENO);
		printf("Can you hear me?\n");
        } else {
		int hm = wait(NULL);
    }

	free(cmdline);

}