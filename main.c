#include "shell.c"
/*
 * main - Entry point
 *
 * Return: returns 0
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		display_prompt();
		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			printf("\nExiting simple_shell.\n");
			break;
		}
		size_t command_length = strlen(command);

		if (command_length > 0 && command[command_length - 1] == '\n')
		{
			command[command_length - 1] = '\0';
		}
		execute_command(command);
	}
	return (0);
}
