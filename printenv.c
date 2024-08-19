#include <stdio.h>
#include <stdlib.h>

/**
 * main - print the environment using the global varialbe
 * @environ: the global variable environ.
 * Return: 0
 */
extern char **environ;

int main(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}

	return (0);
}
