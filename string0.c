#include "shell.h"

/**
 * _strcpy :a copies a string
 * @dest:destination
 * @src: source
 * Return: pointer to desti
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	if (dest == src || src == 0)
		return (dest);
	for (i = 0;src[i];i++)
	{
		dest[i] = src[i];
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _strdup : duplicate string
 * @str:a  string to duplicate
 * Return:a pointer to  duplicated string
 */
char *_strdup(const char *str)
{
	int lengt = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		lengt++;
	ret = malloc(sizeof(char) * (lengt + 1));
	if (!ret)
		return (NULL);
	for (lengt++; lengt--;)
		ret[lengt] = *--str;
	return (ret);
}

/**
 * _puts : prints input string
 * @str: string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	int i;

	if (!str)
		return;
	for (i = 0;str[i] != '\0';i++)
	{
		_putchar(str[i]);
	}
}

/**
 * _putchar - writes  character c to stdout
 * @c: characters to print
 * Return: 1 success .
 * On error, -1 is returned and no error is set appropriately.
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
