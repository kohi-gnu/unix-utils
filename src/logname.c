#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int
main(void)
{
	char *logname;

	logname = getlogin();
	if (logname == NULL)
	{
		perror("logname");
		return (EXIT_FAILURE);
	}
	puts(logname);
	return (EXIT_SUCCESS);
}