#include "simishell.h"

/**
 * getfunc - a function which selects a function based on the commands
 * @str: a command string pointer
 *
 * Return: returns 1 in success and -1 if it fails.
 */

int (*getfunc(char *str))(char **line)
{
	int i = 0;
	selecte selector[] = {
		{"ls", lister},
		{"l", lister},
		{"ll", lister},
		{"exit", exitor},
		{"echo", echorr},
		{"cd", changedire},
		{"cat", cater},
		{"pwd", pwder},
		{"env", envir},
		{"printenv", envir},
		{"/bin/printenv", envir},
		{"/bin/env", envir},
		{"mkdir", maker},
		{NULL, NULL}};

	while (!strcomp(selector[i].command, str) && (selector[i].command != NULL))
	{
		i++;
	}

	if (selector[i].command == NULL)
	{
		return (NULL);
	}

