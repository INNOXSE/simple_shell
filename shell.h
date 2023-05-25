#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>

#define PROMPT "# "
#define TRUE 1
#define BUFFER 1024
/* error str */
#define ERR_FORK "Unable to fork and create child process\n"
#define ERR_MALLOC "Unable to malloc space\n"
#define ERR_PATH "No such file or dir.\n"
extern char **environ;

/**
 * struct list_s -list linked var
 * @value -vl
 * @next: Next node
 *
 * Descrip.: generic linked list for variables.
**/

typedef struct list_s
{
	char *value;
	struct list_s *next;
} list_s;

/**
 * struct built_s -builts listnlinked
 * @class: builtin
 * @fp: func. of pointer
 * Descrip.: struct for builtin func.
**/
typedef struct built_s
{
	char *class;
	int (*p)(void);
} built_s;

void prompt(int fp, struct stat buf);
char *_getline(FILE *pf);
char **tokenizer(char *str);
char *_convert(char *command, char *fulldir, char *location);
int child(char *fulldir, char **toks, char **env);
void errors(int error);

/* text_processoing */
void _puts(char *str);
char *_strcpy(char *endpoint, char *src);
int _strlen(char *s);
int _strcmp(char *class, char *var, unsigned int length);
int _strncmp(char *class, char *var, unsigned int length);

/* shell_env shell_exit prototypes */
int shell_env(void);
int shell_exit(void);
int builtin_exe(char **toks);
int shell_digit_builtins(built_s builtin[]);

/* helper function prototype for linked list location */
char *_getenv(const char *class);
char **copy_env(char **environ_copy, unsigned int environ_length);
list_s *locationlist(char *var, list_s *head);

/* prototypes for free func. */
void free_all(char **toks, char *location, char *line, char *fulldir, int time);
void free_dp(char **array, unsigned int length);
#endif /* MAIN_H */
