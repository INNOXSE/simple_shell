#include "shell.h"

char **environ; /* Definition of environ variable */

int main(void)
{
    char *line, **toks;
    struct stat buf;
    int fp, stat;

    fp = STDIN_FILENO;
    prompt(fp, buf);

    while ((line = _getline(stdin)) != NULL)
    {
        toks = tokenizer(line);
        if (toks != NULL && toks[0] != NULL)
        {
            struct built_t builtin[] = {
                {"exit", shell_exit},
                {"env", shell_env},
                {NULL, NULL}
            };

            if (builtin_execute(toks, struct built_t builtin) == 1)
            {
                char *command = toks[0];
                char *location = _getenv("PATH");
                char *fulldir = NULL;

                fulldir = _convert(command, fulldir, location);
                if (fulldir != NULL)
                    child(fulldir, toks, environ);
                else
                    errors(4);

                free(fulldir);
            }
        }

        free_all(toks, NULL, line, NULL, 0);
        prompt(fp, buf);
    }

    free(line);
    return (stat);
}
