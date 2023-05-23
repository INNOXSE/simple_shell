#include "shell.h"
/**
 * child - func for child process
 * @fulldir: fulldir of exec
 * @token: tokenized user input
 * Return: 0 on success
 */
int child(char *fulldir, char **toks)
{
        pid_t child_pid_t;
        int stat;
        int exec_stat;
        char **envp = env;

        child_pid_t = fork();
        if (child_pid_t == -1)
        {
                errors(1);
                exit(EXIT_FAILURE);
        }
        if (child_pid_t == 0)
        {
                exec_stat = execve(fulldir, toks, envp);
                if (exec_stat == -1)
                        return (-1);
        }
        else
                wait(&stat);
	return(0);
}
