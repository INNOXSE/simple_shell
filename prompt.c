#include "main.h"

/**
 * prompt - displays the command prompt
 *
 * Description: This function prints the command prompt if the standard input
 * is associated with a terminal.
 *
 * Return: void
 */
void prompt(void)
{
    if (isatty(STDIN_FILENO))
        write(STDOUT_FILENO, "$ ", strlen("$ "));
}
