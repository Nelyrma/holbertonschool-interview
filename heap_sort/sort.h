#ifndef HEAP_SORT_H
#define HEAP_SORT_H
#include <stdlib.h>
#include <stdio.h>
void heap_sort(int *array, size_t size);
void heapify(int *array, size_t size, size_t root, size_t size_init);
void print_array(const int *array, size_t size);
#endif
