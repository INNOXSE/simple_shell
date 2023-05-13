#include "shell.h"

/**
 * main test files - execs. the cmd list all including hiden
 * ls -l /tmp in 5 diff. chi. procs.
 * Return: 0 on all successes
 */
int main(void)
{
	pident_t ch_pident;
	char *fname = "/bin/ls";
	char *newargu[] = { "-l", "/tmp", NULL };
	char *newenv[] = { NULL };
	int stat = 0;
	unsigned int k;

	k = 0;
	while (k < 5)
	{
		ch_pident = fork();
		if (ch_pident == -1)
		{
			perror("Error:");
			return (1);
		}
		if (ch_pident == 0)
		{
			exec(fname, newargu, newenv);
		}	wait(&stat);
		i++;
	}
	return (0);
}
