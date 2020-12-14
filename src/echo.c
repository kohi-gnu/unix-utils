#include <stdlib.h>
#include <stdio.h>

int
main(int argc, const char *argv[])
{
	int idx;

	for (idx = 1; idx < argc; idx++)
	{
		if (idx > 1)
			putchar(' ');
		fputs(argv[idx], stdout);
	}
	putchar('\n');
	return (EXIT_SUCCESS);
}
