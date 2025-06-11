#ifndef MEEGE_SORT
#define MEEGE_SORT

void merge_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void merge(int *array, int *copy, int left, int right, int mid);
void split(int *array, int *copy, int left, int right);

#endif
