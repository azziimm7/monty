#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"
/**
 * substring - extarct a substinrng from a given string
 * @src: the original string
 * @start: start index of substring
 * @end: end index of substring
 * Return: pointer to substring
 */

char *substring(char *src, int start, int end)
{
	char *extract = malloc((end - start + 2) * sizeof(char));
	int i;

	for (i = start; i <= end; i++)
	{
		extract[i - start] = src[i];
	}
	extract[end - start + 1] = '\0';
	return (extract);
}

/**
 * word_count - couts number of words in a string
 * @str: source strin
 * Return: number of words in string
 */

int word_count(char *str)
{
	int len = strlen(str);
	int count;
	int i;

	if (len == 0)
	{
		return (0);
	}
	count = (str[0] != ' ');
	for (i = 1; i < len; i++)
	{
		count += (str[i - 1] == ' ' && str[i] != ' ');
	}
	return (count);
}

/**
 * split_str - splits strings in whitespacce
 * @str: string to spkit
 * Return: poinet to array containing splits
 */

char **split_str(char *str)
{
	int len = strlen(str);
	int start = -1;
	int count = word_count(str);
	int index = 0;
	int i;
	char **splits;

	splits = malloc((count + 1) * sizeof(char *));
	for (i = 0; i < len; i++)
	{
		if (str[i] == ' ')
		{
			if (start != -1)
			{
				splits[index++] = substring(str, start, i - 1);
				start = -1;
			}
		}
		else
		{
			if (start == -1)
			{
				start = i;
			}
		}
	}
	if (start != -1)
	{
		splits[index++] = substring(str, start, i - 1);
	}
	splits[index] = NULL;
	return (splits);
}
/**
 * free_str_arr - free dynamically allocated array of strings
 * @str_arr: the array to dellocate
 */

void free_str_arr(char **str_arr)
{
	char **start = str_arr;

	while (*start)
	{
		free(*start);
		start++;
	}
	free(str_arr);
}

/**
 * valid_int - checks if string can be converted to integer
 * @str: source string
 * Return: True oR false
 */

bool valid_int(char *str)
{
	if (*str && *str == '-')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (false);
		str++;
	}
	return (true);
}
