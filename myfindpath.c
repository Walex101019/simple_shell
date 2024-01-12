#include "shell.h"

/**
 * findpath - searches through the directories to find a command
 *
 * Return: absolute path to the command if found, else NULL
 */
char *findpath(void)
{
	int i = 0;
	char *path_str = _getenv("PATH");
	char **path_dir, *abs_path;

	if (_strncmp(command[0], "./", 2) == 0 ||
			command[0][0] == '/' ||
			_strncmp(command[0], "../", 3) == 0)
	{
		if (access(command[0], F_OK) == 0)
			return (_strdup(command[0]));
	}

	if (!path_str)
		return (NULL);

	path_dir = strarr(path_str, ':');

	for (i = 0; path_dir[i]; i++)
	{
		abs_path = malloc(1024);
		_strcpy(abs_path, path_dir[i]);
		_strcat(abs_path, "/");
		_strcat(abs_path, command[0]);

		if (access(abs_path, F_OK) == 0)
		{
			free_arr(path_dir);
			return (abs_path);
		}
		free(abs_path);
	}
	free_arr(path_dir);

	return (NULL);
}
