#include "shell.h"
/*
 * execute_command - Entry point
 * @command: command passed
 */
void execute_command(const char *command)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
	}
	else if (pid == 0)
	{
		execlp(command, command, NULL);
		perror("exec");
		exit(EXIT_FAILURE);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			if (WEXITSTATUS(status) != 0)
			{
				fprintf(stderr, "Error: Command '%s' f%d\n", command, WEXITSTATUS(status));
			}
		}
		else
		{
			fprintf(stderr, "Error: Command '%s' did not terminate\n", command);
		}
	}
}
