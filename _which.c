#include "main.h"
/**
 * is_valid_path - Check if a filename has a valid path format.
 * @filename: The filename to check.
 *
 * Description: This function checks if the filename has a valid path format.
 * It returns 1 if the filename starts with "../", "./", or "/", indicating an
 * executable path. Otherwise, it returns 0.
 *
 * Return: 1 if the filename has a valid path format, 0 otherwise.
 */
int is_valid_path(char *filename)
{
	size_t length = strlen(filename);

	if (length >= strlen("../") && strncmp(filename, "../", strlen("../")) == 0)
		return (1);
	if (length >= strlen("./") && strncmp(filename, "./", strlen("./")) == 0)
		return (1);
	if (length >= strlen("/") && strncmp(filename, "/", strlen("/")) == 0)
		return (1);
	return (0);
}

/**
 * filepath_creator - Create a file path using a directory and filename.
 * @file_path: Pointer to store the created file path.
 * @array_of_tokens: Array of path directories.
 * @filename: The filename to append to the directory.
 * @token_index: Index of the directory to use.
 *
 * Description: This function creates a file path by combining a directory
 * from the array_of_tokens with the filename. The resulting file path is
 * stored in the file_path parameter.
 *
 * Return: void.
 */
void filepath_creator(char **file_path, char **array_of_tokens,
		char *filename, int token_index)
{
	malloc_char(file_path,
			(strlen(array_of_tokens[token_index]) + strlen(filename) + 2),
			"_which Error: malloc failed for file_path");
	strcpy(*file_path, array_of_tokens[token_index]);
	strcat(*file_path, "/");
	strcat(*file_path, filename);
	strcat(*file_path, "\0");
}

/**
 * _which - Find the full path of an executable file.
 * @filename: The filename to search for.
 *
 * Description: This function searches for the full path of the executable file
 * specified by the filename. It first checks the directories listed in the
 * "PATH" environment variable. If the file is found, the full path is returned.
 * If the file is not found in the directories, the function checks if the filename
 * has a valid path format (starts with "../", "./", or "/"). If it does, the filename
 * itself is returned as the full path. If the file is not found and the filename does
 * not have a valid path format, NULL is returned.
 *
 * Return: The full path of the executable file, or NULL if not found.
 */
char *_which(char *filename)
{
	struct stat sb;
	char *path_var, *delimiter, *file_path;
	char **array_of_tokens;
	int token_index, file_path_exist;

	delimiter = ":";
	path_var = _getenv("PATH");
	if (path_var != NULL)
	{
		array_of_tokens = array_maker(path_var, delimiter);
		if (array_of_tokens != NULL)
		{
			for (token_index = 0; array_of_tokens[token_index]; token_index++)
			{
				filepath_creator(&file_path, array_of_tokens, filename, token_index);
				file_path_exist = stat(file_path, &sb);
				if (file_path_exist == 0)
				{
					free_which(&path_var, array_of_tokens);
					return (file_path);
				}
				free(file_path);
        }
			free_which(&path_var, array_of_tokens);
		}
		else
			free(path_var);
	}
	file_path_exist = stat(filename, &sb);
	if (file_path_exist == 0 && is_valid_path(filename))
		return (strdup(filename));
	return (NULL);
}
			
