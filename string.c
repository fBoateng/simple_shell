#include "shell.h"

/**
 * _strlen -it returns the length of a string
 * @s: this is a string whose length to checks
 * Return:the integer length of string
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - it performs lexicogarphic comparison of two strangs.
 * @s1: is a first strang
 * @s2: is a second strang
 * Return:if it is negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}
/**
 * starts_with - it checks if needle starts with haystack
 * @haystack:this is a string to search
 * @needle: is a substring to find
 * Return:an address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat -it is a concatenates two strings
 * @dest: this destination buffer
 * @src: this source buffer
 * Return:it is a pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

