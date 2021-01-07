#include <sys/utsname.h>
#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>

#define CMD_M 0x1
#define CMD_N 0x2
#define CMD_R 0x4
#define CMD_S 0x8
#define CMD_V 0x10

static int
decode_flags(int argc, char *argv[])
{
	int             opt;
	int             flags;

	flags = 0;
	while ((opt = getopt(argc, argv, "amnrsv")) != -1)
	{
		switch (opt)
		{
		 case 'a':
			 return (CMD_M | CMD_N | CMD_R | CMD_S | CMD_V);
		 case 'm':
			 flags |= CMD_M;
			 break;
		 case 'n':
			 flags |= CMD_N;
			 break;
		 case 'r':
			 flags |= CMD_R;
			 break;
		 case 's':
			 flags |= CMD_S;
			 break;
		 case 'v':
			 flags |= CMD_V;
			 break;
		 default:
			 break;
		}
	}

	if (flags == 0)
		flags = CMD_S;
	return (flags);
}

static void
print_data(char *str)
{
	static char     has_previous = 0;

	if (has_previous)
		putchar(' ');
	fputs(str, stdout);
	has_previous = 1;
}

int
main(int argc, const char *argv[])
{
	struct utsname  u;
	int             flags;

	flags = decode_flags(argc, (char **)argv);
	if (uname(&u) < 0)
	{
		perror("uname");
		return (EXIT_FAILURE);
	}
	if (flags & CMD_M)
		print_data(u.machine);
	if (flags & CMD_N)
		print_data(u.nodename);
	if (flags & CMD_R)
		print_data(u.release);
	if (flags & CMD_S)
		print_data(u.sysname);
	if (flags & CMD_V)
		print_data(u.version);
	putchar('\n');
	return (EXIT_SUCCESS);
}
