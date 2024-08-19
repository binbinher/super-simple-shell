#include <stdio.h>
/**
 * main - aa
 * @argc: the amount of arguments
 * @av:array of the arguments
 * Return: 0.
 */

int main(int argc, char *av[])
{
	(void)argc;

	char **arg = av;

	while (*arg != NULL)
	{
		printf("%s\n", *arg);
		arg++;
	}
	return (0);
}
