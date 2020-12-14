#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>

static void
remove_suffix(char *str, char *suffix)
{
	char *suffix_end;
	char *str_end;

	suffix_end = suffix + strlen(suffix);
	str_end = str + strlen(str);

	for (; suffix_end > suffix && str_end > str; suffix_end--, str_end--)
	{
		if (*suffix_end != *str_end)
			return;
	}

	if (str_end > str)
		*str_end = '\0';
}

int
main(int argc, const char *argv[])
{
	char *str;

	if (argc == 1)
		return (EXIT_FAILURE);
	str = basename((char *)argv[1]);
	if (argc > 2)
		remove_suffix(str, (char *)argv[2]);
	puts(str);
	return (EXIT_SUCCESS);
}
