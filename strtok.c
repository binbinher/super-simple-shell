#include <stdio.h>
#include <string.h>
/**
 * main - seperate the string into each word.
 * Return: 0 success.
 */
int main(void)
{
	char str[] = "This is a test string, smile on it : )";
	char *token;

	token = strtok(str, " ");

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}
	return (0);
}
