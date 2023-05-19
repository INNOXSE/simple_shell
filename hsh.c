#include "shell.h"

/**
 * main - this is the main shell loop
 * Return: 0 Zero on successul exec.
 *
 */
int main(void)
{
	char *root, *location, *fulldir, **toks;
	int time, builtin, ch;
	struct stat buf;

	while (TRUE)
	{
		prompt(STDIN_FILENO, buf);
		root = _getroot(stdin);
		if (_strcmp(root, "\n", 1) == 0)
		{
			fr(root);
			continue;
		}
		toks = tokenizer(root);
		if (toks[0] == NULL)
			continue;
		builtin = builtin_exe(toks);
		if (builtin == 0 || builtin == -1)
		{
			fr(toks);
			fr(root);
		}
		if (builtin == 0)
			continue;
		if (builtin == -1)
			_exit(EXIT_SUCCESS);
		time = 0; /* 0 fulldir is not fr 'd*/
		location = _getenv("LOCATION");
		fulldir = convert(token[0], fulldir, location);
		if (fulldir == NULL)
			fulldir = toks[0];
		else
			time = 1; /* if fulldir was malloc'd, time to fr */
		ch_stat = ch(fulldir, toks);
		if (ch == -1)
			errors(2);
		fr_all(toks, location, root, fulldir, time);
	}
	return (0);
}
