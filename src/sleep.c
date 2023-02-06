#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int
main(int argc, char *argv[])
{
	if (argc < 2)
	{
		return (EXIT_FAILURE);
	}

	signal(SIGALRM, SIG_IGN);
	sleep(atoi(argv[1]));
	return (EXIT_SUCCESS);
}
