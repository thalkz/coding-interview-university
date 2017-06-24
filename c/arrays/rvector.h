#ifndef R_VECTOR
#define R_VECTOR

#include <stdbool.h>

const int MIN_CAPACITY = 16;

typedef struct
{
  int capacity;
  int size;
  int *data;
} RVector;

RVector *rvector_new();

void rvector_destroy(RVector* v);

void print_vector(RVector* v);

void rvector_push(RVector* v, int item);

void rvector_resize(RVector* v, int new_capacity);

int rvector_size(RVector* v);

int rvector_capacity(RVector* v);

bool rvector_isempty(RVector* v);

int rvector_at(RVector* v, int index);

int rvector_pop(RVector* v);

void rvector_insert(RVector* v, int item, int index);

void rvector_exchange(RVector* v, int i, int j);

void rvector_prepend(RVector* v, int item);

int rvector_delete(RVector* v, int index);

void rvector_remove(RVector* v, int item);

int rvector_find(RVector* v, int item);

#endif
