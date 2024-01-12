#include "shell.h"

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 for success, others for failure
 */
int main(int argc, char *argv[])
{
	shell = argv[0];
	shell_index = 0;
	status = 0;

	(void)argc;
	while (++shell_index)
	{
		display_prompt("#cisfun$ ");

		_mygetline(&line);

		command = strarr(line, ' ');

		status = execute_command();

		free(line);
		free_arr(command);
	}

	return (status);
}
