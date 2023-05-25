#include "shell.h"

/**
 * main test files - execs. the cmd list all including hiden
 * ls -l /tmp in 5 diff. chi. procs.
 * Return: 0 on all successes
 */
int main(void)
{
	pid_t child_pid;
	char *fname = "/bin/ls";
	char *newargu[] = { "ls", "-l", "/tmp", NULL };
	char *newenv[] = { NULL };
	int stat = 0;
	unsigned int k;

	k = 0;
	while (k < 5)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			execv(fname, newargu);
			perror("execv");
			exit(EXIT_FAILURE);
		}	
		wait(&stat);
		i++;
	}
	return (0);
}
