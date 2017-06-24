#include <stdio.h>
#include <stdlib.h>
#include "rvector.h"
#include "rvector.c"

void run_example();

int main(int argc, char* argv[])
{
  run_example();
  return 0;
}

void run_example()
{
  printf("Run examples\n");

  RVector* v = rvector_new(2);
  rvector_push(v, 1);
  rvector_push(v, 2);
  rvector_push(v, 3);
  rvector_push(v, 4);
  rvector_push(v, 5);
  rvector_push(v, 6);

  print_vector(v);
  rvector_destroy(v);
}
