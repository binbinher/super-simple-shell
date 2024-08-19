#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_PATH_LENGTH 1024

/**
 * file_exists - check if a file exists in the given directory.
 * Return:1 if file exists, 0 otherwise
 */

int file_exists(const char *directory, const char *filename)
{
	char path[MAX_PATH_LENGTH];
	snprintf(path, sizeof(path), "%s/%s", directory, filename);
	struct stat buffer;
	return (stat(path, &buffer) == 0);
}

/**
 * find_file - find a file in the directories listed in PATH
 * Return: nothing
 */
void find_file(const char *filename)
{
	const char *path_env = getenv("PATH");
	if (path_env == NULL)
	{
		fprintf(stderr, "Error: PATH environment variable not set.\n");
		return;
	}

	char path[MAX_PATH_LENGTH];
	char *token = strtok(strcpy(path, path_env), ":");

	while (token != NULL)
	{
		if (file_exists(token, filename))
		{
			printf("%s/%s\n", token, filename);
		}
		token = strtok(NULL, ":");
	}
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s filename ...\n", argv[0]);
		return EXIT_FAILURE;
	}

	for (int i = 1; i < argc; i++)
	{
		find_file(argv[i]);
	}

	return EXIT_SUCCESS;
}
gcc m