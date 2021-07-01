#include <stdio.h>

int
main (int argc, const char *argv[])
{
  for (;;)
    if (argc < 2)
      puts ("y");
    else
    {
      int i;
      for (i = 1; i < argc; i++)
      {
        printf ("%s", argv[i]);
        if (i != argc - 1)
          printf (" ");
      }
      puts ("");
    }
}
