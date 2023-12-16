#include <string.h>
#include "monty.h"
/**
 * rem_coms - remove commetns from string
 * @s: input string
 */

void rem_coms(char *s)
{
	int len = strlen(s);
	int i;

	for (i = 0; i < len; i++)
	{
		if (s[i] == '#')
		{
			s[i] = '\0';
			break;
		}
		else if (s[i] != ' ')
		{
			break;
		}
	}
}

/**
 * printable_ascii - @ is a printble ascii or not
 * @c: input character
 * Return: true if c is printable ascii
 */

bool printable_ascii(int c)
{
	return (c >= 32 && c <= 127);
}
