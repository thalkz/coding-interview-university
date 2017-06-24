#ifndef R_VECTOR
#define R_VECTOR

typedef struct
{
  int capacity;
  int size;
  int *data;
} RVector;

RVector *rvector_new(int capacity);

void rvector_destroy(RVector *v);

void print_vector(RVector *v);

void rvector_push(RVector *v, int item);

void rvector_resize(RVector *v, int new_capacity);

#endif
