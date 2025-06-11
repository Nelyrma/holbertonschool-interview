#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - merges the copied array into the original one
 * @array: updated array of integers to sort
 * @arrCopy: copy of the array
 * @left: beginning of array;
 * @right: end of array;
 * @mid: half point between left and right
 *
 * return: nothing
 */
void merge(int *array, int *arrCopy, int left, int right, int mid)
{
	int start, end, i = left;

	start = left;
	end = mid;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(arrCopy + left, mid - left);
	printf("[right]: ");
	print_array(arrCopy + mid, right - mid);
	while (start < mid && end < right)
	{
		if (arrCopy[start] < arrCopy[end])
		{
			array[i] = arrCopy[start];
			start++;
		} else
		{
			array[i] = arrCopy[end];
			end++;
		}
		i++;
	}
	while (start < mid)
	{
		array[i] = arrCopy[start];
		i++;
		start++;
	}
	while (end <= right)
	{
		array[i] = arrCopy[end];
		i++;
		end++;
	}
	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * split - splits the array in half and calls merge()
 * @array: array to sort
 * @arrCopy: copy of the array to sort
 * @left: beggining of the array
 * @right: end of the array
 *
 * return: nothing
 */
void split(int *array, int *arrCopy, int left, int right)
{
	int mid = left + (right - left) / 2;

	if (right - left <= 1)
		return;

	split(arrCopy, array, left, mid);
	split(arrCopy, array, mid, right);
	merge(array, arrCopy, left, right, mid);
}

/**
 * merge_sort - sorts an array of integers in ascending order
 * @array: array of integers to sort
 * @size: size of the array
 *
 * return: nothing
 */
void merge_sort(int *array, size_t size)
{
	int *arrCopy;
	size_t i = 0;

	if (!array || size < 2)
		return;

	arrCopy = malloc(size * sizeof(int));
	if (!arrCopy)
		return;
	for (; i < size; i++)
		arrCopy[i] = array[i];

	split(array, arrCopy, 0, size);
	free(arrCopy);
}