#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>

static int all = 0;

void
decode_flags (int argc, char *argv[])
{
  int optidx, c;
  struct option long_options[] = {
    { "all", no_argument, &all, 1 },
  };
  all = 0;
  optidx = 0;

  while ((c = getopt_long (argc, argv, "a", long_options, &optidx)) != -1)
    switch (c)
      {
      case 'a':
        all = 1;
        break;
      case '?':
        exit (EXIT_FAILURE);
      default:
        break;
      }
}

int
main (int argc, const char *argv[])
{
  int nprocs;
  decode_flags (argc, (char **)argv);
  nprocs = all ? get_nprocs_conf () : get_nprocs ();
  printf ("%d\n", nprocs);
  return (EXIT_SUCCESS);
}
