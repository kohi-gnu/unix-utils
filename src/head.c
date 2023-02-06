/* TODO: remove getline & _GNU_SOURCE */
#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void
process_file(FILE * fp, int nflag)
{
	char *line;
	size_t len;
	int read;

	line = NULL;
	len = 0;
	while ((read = getline(&line, &len, fp)) != -1 && nflag-- > 0)
	{
		fwrite(line, read, 1, stdout);
	}
	free(line);
}

int
main(int argc, char *argv[])
{
	int idx;
	int nflag;
	int has_nflag;
	FILE *fp;

	has_nflag = 0;
	nflag = 10;
	idx = 1;
	if (argc > 1 && strcmp(argv[idx], "-n") == 0)
	{
		if (argc < 3)
		{
			return (EXIT_FAILURE);
		}
		nflag = atoi(argv[2]);
		idx += 2;
		has_nflag = 1;
	}

	if (idx >= argc)
	{
		process_file(stdin, nflag);
	}

	while (idx < argc)
	{
		fp = fopen(argv[idx++], "r");
		if (fp == NULL)
		{
			perror("head");
			return (EXIT_FAILURE);
		}
		if ((has_nflag && argc > 4) || (!has_nflag && argc > 2))
		{
			printf("\n==> %s <==\n", argv[idx-1]);
		}
		process_file(fp, nflag);
		fclose(fp);
	}
	return (EXIT_SUCCESS);
}
