#include <stdlib.h>
#include <stdio.h>
#include <libgen.h>

int
main(int argc, const char *argv[])
{
	char *str;

	if (argc == 1)
		return (EXIT_FAILURE);
	str = dirname((char *)argv[1]);
	puts(str);
	return (EXIT_SUCCESS);
}