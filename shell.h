#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ; /* Declaration of environ variable */

#define BUFFER 1024
#define PROMPT "$ "
#define ERR_FORK "Error: fork failed\n"
#define ERR_MALLOC "Error: malloc failed\n"
#define ERR_PATH "Error: empty PATH variable\n"

/* Struct for built-in functions */
typedef struct built_s
{
    char *name;
    int (*p)(void);
} struct built_t;

/* Prompt */
void prompt(int fp, struct stat buf);
void _puts(char *str);

/* Input */
char *_getline(FILE *fp);

/* Tokenizer */
char **tokenizer(char *str);

/* Built-in Execution */
int builtin_execute(char **toks, struct built_t builtin);
int shell_digit_builtins(struct built_t builtin[]);

/* Child Process */
int child(char *fulldir, char **toks, char **environ);

/* Error Handling */
void errors(int error);

/* Text Processing */
int _strcmp(char *name, char *var, unsigned int length);
int _strncmp(char *name, char *var, unsigned int length);
char *_strcpy(char *endpoint, char *src);
unsigned int _strlen(char *str);

/* Exit and Environment */
int shell_exit(void);
int shell_env(void);

/* Freeing Memory */
void free_all(char **toks, char *location, char *line, char *fulldir, int time);
void free_dp(char **array, unsigned int length);

/* Helper Functions */
char *_convert(char *command, char *fulldir, char *location);
char *_getenv(const char *class);
char **copy_env(char **environ_copy, unsigned int environ_length);

#endif /* SHELL_H */
