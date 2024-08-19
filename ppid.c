#include <stdio.h>
#include <unistd.h>

/**
 * main - ppid
 * Return : 0.
 */
int main(void)
{
    pid_t parent_pid;

    parent_pid = getppid();

    printf("Parent Process ID (PID): %d\n", parent_pid);

    return (0);
}
