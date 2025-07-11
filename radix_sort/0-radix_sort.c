#include "sort.h"
#include <stdlib.h>

/**
 * get_max - Finds the maximum value in an array
 * @array: Array of integers
 * @size: Size of the array
 *
 * Return: The maximum value
 */
static int get_max(int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort_digit - Sorts an array based on a specific digit
 * @array: Array to sort
 * @size: Size of the array
 * @exp: Exponent (1, 10, 100, etc.) to extract the digit
 */
static void counting_sort_digit(int *array, size_t size, int exp)
{
	int count[10] = {0};
	int *output;
	size_t i;
	int digit;

	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	for (i = 0; i < size; i++)
	{
		digit = (array[i] / exp) % 10;
		count[digit]++;
	}

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size; i > 0; i--)
	{
		digit = (array[i - 1] / exp) % 10;
		output[count[digit] - 1] = array[i - 1];
		count[digit]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * radix_sort - Sorts an array using LSD Radix Sort algorithm
 * @array: Array of integers
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (!array || size < 2)
		return;

	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort_digit(array, size, exp);
		print_array(array, size);
	}
}
