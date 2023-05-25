#include "shell.h"
/**
 * child - func for child process
 * @fulldir: fulldir of exec
 * @toks: tokenized user input
 * Return: 0 on success
 */
int child(char *fulldir, char **toks, char **env)
{
        pid_t child_pid_t;
	int stat;
        int execve_stat;
        char **envp = environ;

        child_pid_t = fork();
        if (child_pid_t == -1)
        {
                errors(1);
                exit(EXIT_FAILURE);
        }
        if (child_pid_t == 0)
        {
                execve_stat = execve(fulldir, toks, envp);
                if (execve_stat == -1)
                        return (-1);
        }
        else
                wait(&stat);
	return(0);
}
