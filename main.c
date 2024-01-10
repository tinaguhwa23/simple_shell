#include "head.h"

/**
 * free_data - This frees data structure
 *
 * @shdata: Its a data structure
 *
 * Return: Does not return anything
 */
void free_data(shell_data *shdata)
{
	unsigned int i;

	for (i = 0; shdata->_environ[i]; i++)
	{
		free(shdata->_environ[i]);
	}

	free(shdata->_environ);
	free(shdata->pid);
}

/**
 * set_data - This will initialize data structure
 *
 * @shdata: data structure
 * @vector: argument vector
 *
 * Return: no return
 */
void set_data(shell_data *shdata, char **vector)
{
	unsigned int i;

	shdata->vector = vector;
	shdata->input = NULL;
	shdata->args = NULL;
	shdata->status = 0;
	shdata->counter = 1;

	for (i = 0; environ[i]; i++)
		;

	shdata->_environ = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		shdata->_environ[i] = _strdup(environ[i]);
	}

	shdata->_environ[i] = NULL;
	shdata->pid = _itoa(getpid());
}

/**
 * main - This is an entry point
 *
 * @ac: Its an argument count
 * @vector: argument vector
 *
 * Return: returns 0 upon success.
 */
int main(int ac, char **vector)
{
	shell_data shdata;
	(void)ac;

	signal(SIGINT, get_sigint);
	set_data(&shdata, vector);
	shell_loop(&shdata);
	free_data(&shdata);
	if (shdata.status < 0)
		return (255);
	return (shdata.status);
}
