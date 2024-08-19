#include <stdio.h>
#include <stdlib.h>

/**
 * main - to print $ wait for the user to enter a command
 * @line: pointer to hold the input line
 * @len: variable to hold the buffer size.
 * @numofread:variable to store the number of characters read.
 * Return: 0 if success -1 if an error or end of file.
 */

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t numofread;

	while (1)
	{
		printf("$");
		numofread = getline(&line, &len, stdin);
		if (numofread == -1)
		{
			break;
		}

		printf("%s", line);
	}
	free(line);

	return (0);
}
