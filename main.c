#include "shell.h"
#include <string.h>
/**
 * main - This is the entry point for the shell
 *
 * Description: Displays a prompt and waits for the user to input a command.
 *
 * Return: 0 on success, or exit status on failure
 */
int main(void)
{
	char *input_line = NULL;
	size_t len = 0;
	ssize_t read;
	bool through_pipe = false;
	pid_t spid;
	int *sstatus;

	while (1 && !through_pipe)
	{
		if (isatty(STDIN_FILENO) == 0)
			through_pipe = true;

		write(STDOUT_FILENO, "#cisfun$ ", strlen("#cisfun$ "));
		read = getline(&input_line, &len, stdin);

		if (read == -1)
		{
			perror("Error: Buffer emtpy");
			free(input_line);
			exit(EXIT_FAILURE);

		}
		spid = fork();
		if (spid == 0)
			execve(input_line, &sstatus, 0);
		if (waitpid(spid, &sstatus, 0) == -1)
		{	perror("Error: From forking");
		       exit(EXIT_FAILURE);
		}	       
	}	
	free(input_line);
	return (0);
}
