#include "shell.h"

/**
 * display_prompt - prints the prompt to standard output
 * @prompt: prompt to be printed
 *
 * Return: 0 in interactive mode and 1 in non interactive mode
 */
int display_prompt(char *prompt)
{
	if (isatty(0))
		_fputstr(1, prompt);

	return (0);
}
