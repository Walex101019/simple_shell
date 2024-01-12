#include "shell.h"

/**
 * _calloc - allocates memory to an array
 * @narry: number of array elements
 * @size: size of bytes to be alloctated to each nmemb elements
 * Return: a pointer to the allocated memory.
*/
void *_calloc(unsigned int narry, unsigned int size)
{
	 void *arr_alloc;
	 unsigned int i;

	if (narry == 0 || size == 0)
		return (NULL);

	arr_alloc = malloc(narry * size);
	if (!arr_alloc)
		return (NULL);

	for (i = 0; i < (narry * size); i++)
		((char *) (arr_alloc))[i] = 0;

	return (arr_alloc);
}
