#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int
main(void)
{
	char *tty;

	tty = ttyname(STDIN_FILENO);
	if (tty == NULL)
	{
		perror("tty");
		return (EXIT_FAILURE);
	}
	puts(tty);
	return (EXIT_SUCCESS);
}
