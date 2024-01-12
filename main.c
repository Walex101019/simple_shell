#include "shell.h"
/*
 * main - Entry point
 *
 * Return: returns 0
 */
int main(void)
{
	char input[MAX_INPUT_SIZE];

	while (1)
	{
		display_prompt();
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			printf("\n");
			break;
		}
		input[strcspn(input, "\n")] = '\0':
	}
	return (0);
}
