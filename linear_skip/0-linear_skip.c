#include "search.h"

/* Constants for messages */
#define CHECKED_VALUE "Value checked at index [%lu] = [%d]\n"
#define FOUND_BETWEEN_INDEXES "Value found between indexes [%lu] and [%lu]\n"

/**
 * linear_skip - Searches for a value in a sorted skip list.
 * @list: A pointer to the head of the skip list.
 * @value: The value to search for.
 *
 * Return: A pointer to the first newNode where value is located,
 * or NULL if value is not present or list is NULL.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	if (!list)
		return (NULL);

	skiplist_t *newNode = list, *express = list->express, *last = newNode;

	while (express != NULL && express->n < value)
	{
		printf(CHECKED_VALUE, express->index, express->n);
		newNode = express;
		express = express->express;
	}
	if (express != NULL)
	{
		printf(CHECKED_VALUE, express->index, express->n);
	}
	else 
	{
		last = newNode;
		while (last->next != NULL)
			last = last->next;
	}
	if (express != NULL)
	{
		printf(FOUND_BETWEEN_INDEXES, newNode->index, express->index);
	}
	else
	{
		printf(FOUND_BETWEEN_INDEXES, newNode->index, last->index);
	}
	while (newNode != NULL && newNode->n < value)
	{
		printf(CHECKED_VALUE, newNode->index, newNode->n);
		newNode = newNode->next;
	}

	if (newNode != NULL && newNode->n == value)
	{
		printf(CHECKED_VALUE, newNode->index, newNode->n);
		return (newNode);
	}
	return (NULL);
}
