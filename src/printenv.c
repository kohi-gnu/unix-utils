#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int
main (int argc, const char *argv[])
{
  if (argc == 1)
    {
      char **env;
      for (env = environ; *env != NULL; ++env)
        puts (*env);
    }
  else
    {
      int i = 1;
      while (i < argc)
        {
          char *var;
          var = getenv (argv[i++]);
          if (var != NULL)
            puts ((char *)var);
        }
    }
  return (EXIT_SUCCESS);
}
