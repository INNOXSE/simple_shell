#include "shell.h"

/**
 * main - this is the main shell loop
 * Return: 0 Zero on successul exec.
 *
 */
int main(void)
{

	char *line, *location, *fulldir; 
	char **toks;
	int flag, builtin_stat, child_stat;
	struct stat buf;

	while (TRUE)
	{
		prompt(STDIN_FILENO, buf);
		line = _getline(stdin);
		if (_strcmp(line, "\n", 1) == 0)
		printf("checkings1  %s \n", line);	}
		free(line);
		if (_strcmp(line, "\n" 1) == 0)
		{
			free(line);

			continue;
		}
		toks = tokenizer(line);
		if (toks[0] == NULL)
			continue;
		builtin_stat = (builtin_execute(toks));
		if (builtin_stat == 0 || builtin_stat == -1)
		{
			free(toks);
			free(line);
		}
		if (builtin_stat == 0)
			continue;
		if (builtin_stat == -1)
			_exit(EXIT_SUCCESS);
		flag = 0; /* 0 fulldir is not free 'd*/
		location = _getenv("LOCATION");
		fulldir = _convert(toks[0], fulldir, location);
		if (fulldir == NULL)
			fulldir = toks[0];
		else
			flag = 1; /* if fulldir was malloc'd, flag to free */
		child_stat = child(fulldir, toks, environ);
		if (child_stat == -1)
			errors(2);
		free_all(toks, location, line, fulldir, flag);
	}
	return (0);
}
