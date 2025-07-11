#include "sort.h"
#include <stdlib.h>

/**
 * get_max - finds the max value in the table
 */
static int get_max(int *array, size_t size)
{
    int max = array[0];
    for (size_t i = 1; i < size; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}

/**
 * counting_sort_digit - sort by count according to a specific digit
 */
static void counting_sort_digit(int *array, size_t size, int exp)
{
    int *output = malloc(size * sizeof(int));
    int count[10] = {0};

    if (!output)
        return;

    // Count occurrences of digit (array[i] / exp) % 10
    for (size_t i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    // Sum of counts
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build sorted array
    for (ssize_t i = size - 1; i >= 0; i--)
    {
        int digit = (array[i] / exp) % 10;
        output[count[digit] - 1] = array[i];
        count[digit]--;
    }

    // Copy to original array
    for (size_t i = 0; i < size; i++)
        array[i] = output[i];

    free(output);
}

/**
 * radix_sort - sort the array using radix sort
 */
void radix_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    int max = get_max(array, size);

    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        counting_sort_digit(array, size, exp);
        print_array(array, size); // Display for each significant digit
    }
}
