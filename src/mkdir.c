#include <stdlib.h>
#include <sys/stat.h>

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
		mkdir(argv[idx], S_IRUSR | S_IWUSR | S_IRGRP);
	}
	return (EXIT_SUCCESS);
}
