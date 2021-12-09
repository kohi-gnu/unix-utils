#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

/* XXX: fix me */
#ifndef PATH_MAX
# define PATH_MAX 4096
#endif /*!PATH_MAX*/

int
logical_pwd(void)
{
	char *pwd;

	pwd = getenv("PWD");
	if (pwd == NULL)
	{
		return (0);
	}

	if (*pwd != '/' || strlen(pwd) > PATH_MAX)
	{
		return (0);
	}

	if (strstr(pwd, "/..") != NULL)
	{
		return (0);
	}
	puts(pwd);
	return (1);
}

int
main(int argc, char *argv[])
{
	char buff[PATH_MAX];
	int idx;
	int logical; /* -L */

	logical = 1; /* POSIX default to -L */
	if (argc > 1)
	{
		for (idx = 1; idx < argc; idx++)
		{
			if (strcmp(argv[idx], "-L") == 0)
			{
				logical = 1;
			}
			else if (strcmp(argv[idx], "-P") == 0)
			{
				logical = 0;
			}
		}
	}

	if (logical && logical_pwd())
	{
		return (EXIT_SUCCESS);
	}

	if (getcwd(buff, sizeof(buff)) == NULL)
	{
		perror("pwd");
		return (EXIT_FAILURE);
	}
	puts(buff);
	return (EXIT_SUCCESS);
}
