#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int
main(int argc, const char *argv[])
{
	int             idx;
	int             nflag;

	nflag = 0;
	idx = 1;
	if (strcmp(argv[idx], "-n") == 0)
	{
		nflag = 1;
		idx++;
	}

	while (idx < argc)
	{
		if (idx > 1)
			putchar(' ');
		fputs(argv[idx++], stdout);
	}
	if (!nflag)
	{
		putchar('\n');
	}
	return (EXIT_SUCCESS);
}
