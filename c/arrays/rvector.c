#include <stdio.h>

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

void print_vector(RVector* v)
{
  printf("[ ");
  for(int i = 0; i < v->size; i++)
  {
    printf("%d ", v->data[i]);
  }
  printf("]\n(capacity : %d, size : %d)\n", v->capacity, v->size);
}

void rvector_push(RVector* v, int item)
{
  if(v->size == v->capacity)
  {
    rvector_resize(v, v->size * 2);
  }
  v->data[v->size] = item;
  v->size++;
}

void rvector_resize(RVector* v, int new_capacity)
{
  int* new_data = (int *)malloc(sizeof(int) * new_capacity);
  for(int i = 0; i < v->size; i++)
  {
    new_data[i] = v->data[i];
  }

  free(v->data);
  v->data = new_data;
  v->capacity = new_capacity;
}
