#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

int
main(int argc, char *argv[])
{
	int idx;

	if (argc < 2)
	{
		return (EXIT_FAILURE);
	}
	for (idx = 1; idx < argc; idx++)
	{
		if (mkfifo(argv[idx], S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) != 0)
		{
			perror("mkfifo");
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
