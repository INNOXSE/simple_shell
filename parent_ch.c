#include "shell.h"

/**
 * child - function for parent_ch.c process
 * @fulldir: fulldir of executable
 * @token: tokenized user input
 * Return: 0 on success
 */
int child(char *fulldir, char **token)
{
	pid_t child_pid;
	int status;
	int execve_status;
	char **envp = env;

	child_pid = fork();
	if (child_pid == -1)
	{
		errors(1);
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		execve_status = execve(fulldir, token, envp);
		if (execve_status == -1)
			return (-1);
	}
	else
		wait(&status);

	return (0);
}
