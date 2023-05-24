#include "shell.h"

/**
 * main - this is the main shell loop
 * Return: 0 Zero on successul exec.
 *
 */
extern char **env;
int main(void)
{

	char *line, *location,  *fulldir, **toks;
	int time, builtin, lstat;
	struct stat buf;

	while (TRUE)
	{
		prompt(STDIN_FILENO, buf);
		line = _getline(stdin);
		if (_strcmp(line, "\n", 1) == 0)
		{
			free(line);
			continue;
		}
		toks = tokenizer(line);
		if (toks[0] == NULL)
			continue;
		builtin = builtin_exe(toks);
		if (builtin == 0 || builtin == -1)
		{
			free(toks);
			free(line);
		}
		if (builtin == 0)
			continue;
		if (builtin == -1)
			_exit(EXIT_SUCCESS);
		time = 0; /* 0 fulldir is not free 'd*/
		location = _getenv("LOCATION");
		fulldir = _convert(toks[0], fulldir, location);
		if (fulldir == NULL)
			fulldir = toks[0];
		else
			time = 1; /* if fulldir was malloc'd, time to free */
		lstat = child(fulldir, toks, **env);
		if (lstat == -1)
			errors(2);
		free_all(toks, location, line, fulldir, time);
	}
	return (0);
}
