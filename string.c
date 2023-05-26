#include "main.h"

/**
 * rev_string - Reverses a string.
 * @str: The string to reverse.
 *
 * Description: This function reverses the characters in the string @str in place.
 *
 * Return: void.
 */
void rev_string(char *str)
{
    int i, len;
    char tmp;

    len = 0;
    while (str[len] != '\0')
        len++;
    len--;
    for (i = 0; i < len; i++, len--)
    {
        tmp = str[i];
        str[i] = str[len];
        str[len] = tmp;
    }
}

/**
 * _itoa - Converts an integer to a string.
 * @command_num: The number to convert.
 *
 * Description: This function converts the integer @command_num to its string representation.
 * It dynamically allocates memory for the resulting string and performs a digit-by-digit conversion,
 * storing the digits in reverse order. The resulting string is then reversed to obtain the correct order.
 *
 * Return: The converted string.
 */
char *_itoa(size_t command_num)
{
    char *str = malloc(sizeof(char) * (32 + 1));
    int i = 0;

    do {
        str[i++] = command_num % 10 + '0';
        command_num /= 10;
    } while (command_num > 0);
    str[i] = '\0';
    rev_string(str);

    return (str);
}
