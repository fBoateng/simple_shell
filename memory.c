#include "shell.h"

/**
 * bfree : frees  pointer and NULLs address
 * @ptr: address of pointer to be free
 *
 * Return: 1 for freed, 0 otherwise .
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
