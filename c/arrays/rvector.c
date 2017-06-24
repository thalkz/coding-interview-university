#include <stdio.h>

void print_vector(RVector* v)
{
  printf("Vector\n");
  printf("Size : %d\n", v->size);
  printf("Capacity : %d\n", v->capacity);
}

RVector *rvector_new(int capacity)
{
  RVector *v = malloc(sizeof(RVector));

  if (v == NULL)
  {
    printf("Unable to allocate memory.\n");
    exit(EXIT_FAILURE);
  }

  v->size = 0;
  v->capacity = capacity;
  v->data = (int *)malloc(sizeof(int) * capacity);

  if (v->data == NULL)
  {
    printf("Unable to allocate memory.\n");
    exit(EXIT_FAILURE);
  }

  return v;
}

void rvector_destroy(RVector* v)
{
  free(v->data);
  free(v);
}
