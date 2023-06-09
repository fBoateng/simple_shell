#include "shell.h"

/**
 * bfree -it frees a pointer and NULLs the address
 * @ptr:this is an address of the pointer to free
 * Return: 1 if it is freed, otherwise 0.
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
