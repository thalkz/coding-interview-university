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

  RVector* vector = rvector_new(16);
  print_vector(vector);
  rvector_destroy(vector);
}
