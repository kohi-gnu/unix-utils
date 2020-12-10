#include <stdlib.h>
#include <stdio.h>

static void
read_fp(FILE *fp)
{
	int c;

	while ((c = fgetc(fp)) != EOF)
	{
		putchar(c);
	}
}

int
main(int argc, const char *argv[])
{
	int idx;
	FILE *fp;

	if (argc == 1)
	{
		read_fp(stdin);
		return (EXIT_SUCCESS);
	}
	for (idx = 1; idx < argc; idx++)
	{
		fp = fopen(argv[idx], "rb");
		if (fp == NULL)
		{
			perror("cat");
			return (EXIT_FAILURE);
		}
		read_fp(fp);
		fclose(fp);
	}
	return (EXIT_SUCCESS);
}
