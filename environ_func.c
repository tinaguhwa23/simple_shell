#include "head.h"

/**
 * cmp_env_name - This compares env variables names
 * with the name passed.
 * @nenv: name of the environment variable
 * @name: name passed
 *
 * Return: 0 if are not equal. Another value if they are.
 */
int cmp_env_name(const char *nenv, const char *name)
{
	int i;

	for (i = 0; nenv[i] != '='; i++)
	{
		if (nenv[i] != name[i])
		{
			return (0);
		}
	}

	return (i + 1);
}

/**
 * _getenv - This will get an environment variable
 * @name: name of the environment variable
 * @_environ: environment variable
 *
 * Return: value of the environment variable if is found.
 * In other case, returns NULL.
 */
char *_getenv(const char *name, char **_environ)
{
	char *ptr_env;
	int i, mov;

	/* Initialize ptr_env value */
	ptr_env = NULL;
	mov = 0;
	/* Compare all environment variables */
	/* environ is declared in the header file */
	for (i = 0; _environ[i]; i++)
	{
		/* If name and env are equal */
		mov = cmp_env_name(_environ[i], name);
		if (mov)
		{
			ptr_env = _environ[i];
			break;
		}
	}

	return (ptr_env + mov);
}

/**
 * _env - This will print the evironment variables
 *
 * @shdata: data relevant.
 * Return: 1 on success.
 */
int _env(shell_data *shdata)
{
	int i, j;

	for (i = 0; shdata->_environ[i]; i++)
	{

		for (j = 0; shdata->_environ[i][j]; j++)
			;

		write(STDOUT_FILENO, shdata->_environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	shdata->status = 0;

	return (1);
}
