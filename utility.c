#include "main.h"

/**
 * malloc_char - Allocates memory for a character string.
 * @string: Pointer to the string reference.
 * @size_of_malloc: Size of memory to allocate.
 * @error_message: Error message to display in case of failure.
 *
 * Description: This function dynamically allocates memory for a character string
 * with the specified size. It assigns the allocated memory to the reference @string.
 * If the allocation fails, it displays the error message and returns NULL.
 *
 * Return: Pointer to the allocated memory if successful, NULL otherwise.
 */
char *malloc_char(char **string, size_t size_of_malloc, char *error_message)
{
    *string = (char *) malloc(sizeof(char) * size_of_malloc);
    if (*string == NULL)
    {
        perror(error_message);
        return (NULL);
    }
    return (*string);
}

/**
 * malloc_array - Allocates memory for an array of strings.
 * @array: Pointer to the array reference.
 * @size_of_malloc: Size of memory to allocate.
 * @error_message: Error message to display in case of failure.
 *
 * Description: This function dynamically allocates memory for an array of strings
 * with the specified size. It assigns the allocated memory to the reference @array.
 * If the allocation fails, it displays the error message and returns NULL.
 *
 * Return: Pointer to the allocated memory if successful, NULL otherwise.
 */
char **malloc_array(char **array, size_t size_of_malloc, char *error_message)
{
    array = (char **) malloc(sizeof(char *) * size_of_malloc);
    if (array == NULL)
    {
        perror(error_message);
        return (NULL);
    }
    return (array);
}

/**
 * copy_array - Copies an array of strings.
 * @destination: Pointer to the destination array.
 * @source: Pointer to the source array.
 *
 * Description: This function copies the strings from the source array to the destination array.
 * It dynamically allocates memory for each string in the destination array and performs the copy.
 * If the memory allocation fails, it displays an error message and frees the previously allocated memory.
 *
 * Return: 0 if successful, -1 if memory allocation fails.
 */
int copy_array(char **destination, char **source)
{
    size_t new_env_index, free_new_env_index;

    for (new_env_index = 0; source[new_env_index]; new_env_index++)
    {
        destination[new_env_index] = malloc(sizeof(char) * strlen(source[new_env_index]));
        if (destination[new_env_index] == NULL)
        {
            perror("_setenv() Error: new_environ[new_env_index] malloc failed");
            for (free_new_env_index = 0; free_new_env_index < new_env_index; free_new_env_index++)
                free(destination[new_env_index]);
            free(destination);
            return (-1);
        }
        strcpy(destination[new_env_index], source[new_env_index]);
    }
    return (0);
}

/**
 * _env_name_exists - Checks if an environment variable name exists.
 * @name: Name string to search for.
 *
 * Description: This function checks if the specified environment variable @name exists.
 * It searches through the __environ array for a matching name. If found, it returns the
 * index of the matching entry; otherwise, it returns -1.
 *
 * Return: Index of the matching entry if found, -1 otherwise.
 */
int _env_name_exists(const char *name)
{
    int env_index, is_found;

    is_found = -1;
    for (env_index = 0; __environ[env_index]; env_index++)
    {
        if (strncmp(__environ[env_index], name, strlen(name)) == 0)
            is_found = env_index;
    }
    return (is_found);
}

/**
 * _env_length - Get the length of the environment variables.
 *
 * Description: This function calculates the length of the environment variables
 * by counting the number of elements in the __environ array.
 *
 * Return: The length of the environment variables.
 */
int _env_length(void)
{
    unsigned int env_length;

    for (env_length = 0; __environ[env_length]; env_length++)
    {
        /* Empty loop body */
    }
    return (env_length);
}
