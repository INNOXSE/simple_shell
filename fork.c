#include "main.h"

/**
 * _fork - Creates a child process and executes a command.
 *
 * Description: This function creates a child process using the `fork` system
 * call and executes a command within the child process using `execve`.
 *
 * @command: String command.
 * @array_of_tokens: Array of tokens.
 *
 * Return: The return status of the command execution.
 */
int _fork(char *command, char **array_of_tokens)
{
	pid_t pid;
	int status, is_execve_error;

	pid = fork();
	if (pid == -1)
	{
		perror("_fork() Error: fork child unable to create");
		return (-1);
	}
	if (pid == 0)
	{
		is_execve_error = execve(command, array_of_tokens, __environ);
		if (is_execve_error == -1)
		{
			perror("execve: ");
			return (-1);
		}
	}
	else
	{
		wait(&status);
		free(command);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
		if (!isatty(STDIN_FILENO))
			return (status);
	}
	return (0);
}
