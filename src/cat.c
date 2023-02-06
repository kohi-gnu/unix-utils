#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void
read_fp(FILE * fp)
{
	int c;

	while ((c = fgetc(fp)) != EOF)
	{
		putchar(c);
	}
}

static int
process_file(const char *name, int unbuffered)
{
	FILE *fp;

	if (strcmp(name, "-") == 0)
	{
		fp = stdin;
	}
	else
	{
		fp = fopen(name, "rb");
	}

	if (fp == NULL)
	{
		perror("cat");
		return (-1);
	}

	if (unbuffered)
	{
		if (setvbuf(fp, NULL, _IONBF, 0) != 0)
		{
			perror("cat");
			return (-1);
		}
	}

	read_fp(fp);
	fclose(fp);
	return (0);
}

int
main(int argc, const char *argv[])
{
	int idx;
	int unbuffered;

	if (argc == 1)
	{
		read_fp(stdin);
		return (EXIT_SUCCESS);
	}
	idx = 1;
	unbuffered = 0;
	if (strcmp(argv[idx], "-u") == 0)
	{
		unbuffered = 1;
		idx++;
	}
	for (; idx < argc; idx++)
	{
		if (process_file(argv[idx], unbuffered) != 0)
		{
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
