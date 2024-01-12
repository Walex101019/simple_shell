#include "shell.h"
/*
 * execute_command - Entry point
 * @command: command passed
 */
void execute_command(const char *input)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execlp(input, input, NULL) == -1);
		{
			perror("./hsh");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
	}
}
