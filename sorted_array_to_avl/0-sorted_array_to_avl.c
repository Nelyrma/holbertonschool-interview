#include "binary_trees.h"

/**
 * binary_search - recursive function
 * @array: pointer to array
 * @start: first element
 * @end: last element
 * @parent: parent node
 * Return: a pointer or NULL
 **/
avl_t *binary_search(int *array, int start, int end, avl_t *parent)
{
	int middle;
	avl_t *node;

	if (start > end)
		return (NULL);

	middle = (start + end) / 2;

	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);

	node->n = array[middle];
	node->parent = parent;
	node->left = binary_search(array, start, middle - 1, node);
	node->right = binary_search(array, middle + 1, end, node);

	return (node);
}

/**
 * sorted_array_to_avl - Sorted array to avel function
 * @array: is a pointer
 * @size: is the number of element in the array
 * Return: a pointer or NULL
 **/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	return (!array ? NULL : binary_search(array, 0, size - 1, NULL));
}
