#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int
main(void)
{
	char           *buff;

	buff = getcwd(NULL, 0);
	printf("%s\n", buff);
	free(buff);
	return (EXIT_SUCCESS);
}
