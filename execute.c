#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * main - executes the command ls -l /tmp in 5 child processes
 * @command: the command.
 * @args:the argumetns
 * @envp:Environment variables, can be NULL if not needed
 * Return: 0
 */
int main(void)
{
	int num_children = 5;
	pid_t pid;
	int i;

	char *command = "/bin/ls";
	char *args[] = {"ls", "-l", "/tmp", NULL};
	char *envp[] = {NULL};

	for (i = 0; i < num_children; i++)
	{
		pid = fork();

		if (pid < 0)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}

		if (pid == 0)
		{
			execve(command, args, envp);

			perror("execve");
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
		}
	}

	return (0);
}
