RVector *rvector_new()
{
  int capacity = MIN_CAPACITY;
  RVector* v = malloc(sizeof(RVector));

  if (v == NULL)
  {
    printf("Error : Unable to allocate memory.\n");
    exit(EXIT_FAILURE);
  }

  v->size = 0;
  v->capacity = capacity;
  v->data = (int *)malloc(sizeof(int) * capacity);

  if (v->data == NULL)
  {
    printf("Error : Unable to allocate memory.\n");
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
  printf("]\n(capacity : %d, size : %d)\n\n", v->capacity, v->size);
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

int rvector_size(RVector* v)
{
  return v->size;
}

int rvector_capacity(RVector* v)
{
  return v->capacity;
}

bool rvector_isempty(RVector* v)
{
  return v->size == 0;
}

int rvector_at(RVector* v, int index)
{
  if(index >= 0 && index < v->size)
  {
    return v->data[index];
  } else
  {
    printf("Error : Cannot get item at index : %d\n", index);
    exit(EXIT_FAILURE);
  }
}

int rvector_pop(RVector* v)
{
  int poped_item = 0;
  if(v->size > 0)
  {
    if(v->size < v->capacity / 4 && v->capacity >= MIN_CAPACITY * 2)
    {
      rvector_resize(v, v->capacity / 2);
    }
    poped_item = v->data[v->size];
    v->data[v->size] = 0;
    v->size--;
  } else
  {
    printf("Error : Cannot pop empty RVector\n");
    exit(EXIT_FAILURE);
  }
  return poped_item;
}

void rvector_insert(RVector* v, int item, int index)
{
  if(index >= 0 && index < v->size)
  {
    rvector_push(v, item);

    for(int i = v->size - 1; i > index; i--)
    {
      rvector_exchange(v, i, i - 1);
    }
  } else
  {
    printf("Error : Cannot insert item at index : %d\n", index);
    exit(EXIT_FAILURE);
  }
}

void rvector_exchange(RVector* v, int i, int j)
{
  int temp = v->data[i];
  v->data[i] = v->data[j];
  v->data[j] = temp;
}

void rvector_prepend(RVector* v, int item)
{
  rvector_insert(v, item, 0);
}

int rvector_delete(RVector* v, int index)
{
  if(index >= 0 && index < v->size)
  {
    int deleted_item = v->data[index];
    v->data[index] = 0;
    for(int i = index; i < (v->size - 1); i++)
    {
      rvector_exchange(v, i, i + 1);
    }
    if(v->size < v->capacity / 4 && v->capacity >= MIN_CAPACITY * 2)
    {
      rvector_resize(v, v->capacity / 2);
    }
    v->size--;
    return deleted_item;
  } else
  {
    printf("Error : Cannot delete item at index : %d (size is %d)\n", index, v->size);
    exit(EXIT_FAILURE);
  }
}

void rvector_remove(RVector* v, int item)
{
  int index_to_delete = rvector_find(v, item);
  while(index_to_delete != -1)
  {
    rvector_delete(v, index_to_delete);
    index_to_delete = rvector_find(v, item);
  }
}

int rvector_find(RVector* v, int item)
{
  for(int i = 0; i < v->size; i++)
  {
    if(v->data[i] == item)
    {
      return i;
    }
  }
  return -1;
}
