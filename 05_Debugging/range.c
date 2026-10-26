#include <stdio.h>
#include <stdlib.h>

void help()
{
  printf(
    "Usage: range N\n"
    "       range M N\n"
    "       range M N S\n"
    "Print an arithmetic progression, one number per line, like Python's range().\n");
  exit(0);
}

int main(int argc, char* argv[])
{
  int start = 0, end, step = 1;
  switch (argc)
  {
  case 2:
    end = atoi(argv[1]);
    break;
  case 3:
    start = atoi(argv[1]);
    end = atoi(argv[2]);
    break;
  case 4:
    start = atoi(argv[1]);
    end = atoi(argv[2]);
    step = atoi(argv[3]);
    break;
  default:
    help();
    return 1;
  }

  if (step == 0)
  {
    fprintf(stderr, "Error: step cannot be 0\n");
    return 1;
  }

  for (int i = start; (step > 0) ? i < end : i > end; i += step)
    printf("%d\n", i);

  return 0;
}
