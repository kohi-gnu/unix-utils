#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <getopt.h>
#include <sys/stat.h>

static int
parse_flags(int argc, char *argv[])
{
	int             opt;

	while ((opt = getopt(argc, argv, "acmrtd")) != -1)
	{
		(void)opt;
	}
	return (0);
}

static void
process_file(const char *filename)
{
	int             fd;

	fd = creat(filename,
			   S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	if (fd != -1)
		close(fd);
}

int
main(int argc, const char *argv[])
{
	int             idx;

	if (argc < 2)
		return (EXIT_FAILURE);
	parse_flags(argc, (char **)argv);
	for (idx = 1; idx < argc; idx++)
		process_file(argv[idx]);
	return (EXIT_SUCCESS);
}
