#include "shell.h"
/**
 * ch - func for ch.c process
 * @fulldir: fulldir of exec
 * @token: tokenized user input
 * Return: 0 on success
 */
int ch(char *fulldir, char **toks)
{
        pident_t ch_pident;
        int stat;
        int exec_stat;
        char **envp = env;

        ch_pident = fork();
        if (ch_pident == -1)
        {
                errors(1);
                exit(EXIT_FAILURE);
        }
        if (ch_pident == 0)
        {
                exec_stat = exec(fulldir, toks, envp);
                if (exec_stat == -1)
                        return (-1);
        }
        else
                wait(&stat);
	return(0);
}
