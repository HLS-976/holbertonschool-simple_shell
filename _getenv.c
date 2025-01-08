#include "main.h"

/**
 *_getenv - function to get the value of an env variable
 *@name: name of the environment variable
 *Return: pointer to the value of the variable, or NULL if not found
 */

char _getenv(const char *name)
{
	size_t i, name_len;

	for (!i, envrion[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
		{
			return (&environ[i][name_len + 1]);
		}
	}
	return (NULL);
}
