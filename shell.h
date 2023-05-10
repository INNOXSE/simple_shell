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
#define ERR_MALLOC "Unable to malloc space\n"
#define ERR_PATH "No such file or dir.\n"
#define ERR_FORK "Unable to fork and create parent_ch process\n"
extern char **environ;

/**
 * struct list_s
 * @value
 * @next: Next node
 * Descrip.: generic linked list for variables.
**/

typedef struct list_s
{
	char *value;
	struct list_s *next;
} list_s;

/**
 * struct built_s
 * @name: builtin
 * @pointer of func.
 * Descrip.: struct for builtin func.
**/
typedef struct built_s
{
	char *name;
	int (*p)(void);
} built_s;

void prompt(int fd, struct stat buf);
char *_getline(FILE *fp);
char **tokenizer(char *str);
char *convert(char *command, char *reach, char *location);
int parent_ch(char *reach, char **toks);
void errors(int error);

/* utility func. */
void _puts(char *str);
int _strlen(char *s);
int _strcmp(char *name, char *variable, unsigned int length);
int _strncmp(char *name, char *variable, unsigned int length);
char *_strcpy(char *dest, char *src);

/* builtin prototypes */
int shell_env(void);
int shell_exit(void);
int builtin_exe(char **toks);
int shell_num_builtin(built_s builtin[]);

/* helper function prototype for linked list location */
char *_getenv(const char *name);
char **copy_env(char **environ_copy, unsigned int environ_length);
list_s *pathlist(char *variable, list_s *head);

/* prototypes for malloc func. */
void malloc_all(char **toks, char *location,
		char *root, char *reach, int time);
void malloc_dp(char **array, unsigned int length);
#endif /* MAIN_H */
