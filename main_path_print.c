#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - uses path_print to print var in path dir
 * Return: 0
 */
int main(void)
{
	path_print()
{
    char *path_env = getenv("PATH");  
    if (path_env == NULL)
    {
        printf("PATH environment variable not found\n");
        return;
    }

    char *path_copy = strdup(path_env);  
    if (path_copy == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    char *directory = strtok(path_copy, ":");  
    while (directory != NULL)
    {
        printf("%s\n", directory); 
        directory = strtok(NULL, ":");
    }

    free(path_copy);  
}
    path_print();

    return 0;
}
