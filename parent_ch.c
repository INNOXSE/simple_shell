#include "shell.h"

/**
 * ch - func for parent_ch.c process
 * @fulldir: fulldir of exec
 * @token: tokenized user input
 * Return: 0 on success
 */
int ch(char *fulldir, char **token)
{
	pid_t ch_pid;
	int stat;
	int execve_stat;
	char **envp = env;

	ch_pid = fork();
	if (ch_pid == -1)
	{
		errors(1);
		exit(EXIT_FAILURE);
	}
	if (ch_pid == 0)
	{
		execve_stat = execve(fulldir, token, envp);
		if (execve_stat == -1)
			return (-1);
	}
	else
		wait(&stat);

	return (0);
}
