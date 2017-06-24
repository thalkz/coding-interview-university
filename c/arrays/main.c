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
  printf("Run examples : \n\n");

  RVector* v = rvector_new();

  for(int i = 0; i < 30; i++)
  {
    rvector_push(v, i);
  }

  print_vector(v);
  printf("Size is : %d\n", rvector_size(v));
  printf("Capacity is : %d\n", rvector_capacity(v));
  if(rvector_isempty(v))
  {
    printf("RVector is empty\n");
  } else
  {
    printf("RVector is not empty\n");
  }
  printf("5th item is : %d\n", rvector_at(v, 5));

  printf("Insert 100 at 5th position and 200 at 7th position\n");
  rvector_insert(v, 100, 5);
  rvector_insert(v, 200, 7);
  print_vector(v);

  printf("Prepend 300\n");
  rvector_prepend(v, 300);
  print_vector(v);

  printf("Pop 28 items\n");
  for(int i = 0; i < 28; i++)
  {
    rvector_pop(v);
  }
  print_vector(v);

  printf("Delete item at position 1\n");
  rvector_delete(v, 1);
  print_vector(v);

  printf("Prepend 3 and remove all 3s\n");
  rvector_prepend(v, 3);
  rvector_remove(v, 3);
  print_vector(v);

  rvector_destroy(v);
}
