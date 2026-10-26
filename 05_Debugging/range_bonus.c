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

typedef struct Range
{
  int start;
  int stop;
  int step;
  int i;
} range;

void argparse(int argc, char* argv[], int* start, int* stop, int* step)
{
  switch (argc)
  {
  case 2:
    *start = 0;
    *stop = atoi(argv[1]);
    *step = 1;
    break;
  case 3:
    *start = atoi(argv[1]);
    *stop = atoi(argv[2]);
    *step = 1;
    break;
  case 4:
    *start = atoi(argv[1]);
    *stop = atoi(argv[2]);
    *step = atoi(argv[3]);
    break;
  default: {
    help();
    exit(1);
  }
  }
}

void range_init(range* r)
{
  r->i = r->start;
}

int range_run(const range* r)
{
  if (r->step > 0)
    return r->i < r->stop;
  else
    return r->i > r->stop;
}

void range_next(range* r)
{
  r->i += r->step;
}

int range_get(const range* r)
{
  return r->i;
}

int main(int argc, char* argv[])
{
  range I;
  argparse(argc, argv, &I.start, &I.stop, &I.step);
  for (range_init(&I); range_run(&I); range_next(&I))
    printf("%d\n", range_get(&I));
  return 0;
}
