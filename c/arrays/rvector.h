#ifndef R_VECTOR
#define R_VECTOR

typedef struct
{
  int capacity;
  int size;
  int *data;
} RVector;

void print_vector(RVector *v);

RVector *rvector_new(int capacity);
void rvector_destroy(RVector *v);

#endif
