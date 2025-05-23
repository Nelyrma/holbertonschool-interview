#include "sort.h"
/**
 * check_tree - swiftdown check
 * @array: pointer to array
 * @size: size of the pointer
 * @size_init: original size of the array
 * @i: index as a root of the tree
 *
 **/
void check_tree(int *array, size_t size_init, size_t size, size_t i)
{

	int n, branch1, branch2;
	size_t branch_size_1, branch_size_2;

	branch_size_1 = i * 2 + 1;
	branch_size_2 = branch_size_1 + 1;
	branch1 = array[branch_size_1];
	branch2 = array[branch_size_2];
	if (((branch_size_1 < size) && (branch_size_2 < size) &&
				(branch1 >= branch2 && branch1 > array[i]))
			|| ((branch_size_1 == size - 1) && branch1 > array[i]))
	{
		n = array[i];
		array[i] = branch1;
		array[branch_size_1] = n;
		print_array(array, size_init);
	}
	else if ((branch_size_1 < size) && (branch_size_2 < size) &&
			(branch2 > branch1 && branch2 > array[i]))
	{
		n = array[i];
		array[i] = branch2;
		array[branch_size_2] = n;
		print_array(array, size_init);
	}
	if (branch_size_1 < size - 1)
		check_tree(array, size_init, size, branch_size_1);
	if (branch_size_2 < size - 1)
		check_tree(array, size_init, size, branch_size_2);
}

/**
 * heap_sort - sorts an array of integers
 * in ascending order using the Heap
 * sort algorithm
 * @array: pointer to array
 * @size: size of the pointer
 *
 **/
void heap_sort(int *array, size_t size)
{
	size_t i, size_init = size;
	int n;

	if (!array)
		return;
	for (i = 0; i < size / 2 ; i++)
	{
		check_tree(array, size_init, size, size / 2 - 1 - i);
	}
	for (i = 0; i < size_init - 1; i++)
	{
		n = array[0];
		array[0] = array[size - 1 - i];
		array[size - 1 - i] = n;
		print_array(array, size_init);
		check_tree(array, size_init, size - i - 1, 0);
	}

}
