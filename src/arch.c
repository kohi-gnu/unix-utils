#include <sys/utsname.h>
#include <stdlib.h>
#include <stdio.h>

int
main (void)
{
  struct utsname *buf = malloc (sizeof (struct utsname));
  if (buf == NULL)
    return (EXIT_FAILURE);
  if (uname (buf) != 0)
  {
    free (buf);
    return (EXIT_FAILURE);
  }
  puts (buf->machine);
  free (buf);
  return (EXIT_SUCCESS);
}
