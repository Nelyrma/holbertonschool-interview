#include "list.h"
#include <stdio.h>

/**
 * add_node_end - Adds a new node to the end of
 * a double circular linked list.
 *
 * @list: the list to modify
 * @str: the string to copy into the new node
 *
 * Return: the address of the new node.
 */

List *add_node_end(List **list, char *str)
{
	List *new_node, *last_node;

	if (!list)
		return (NULL);

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);

	new_node->str = strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}

	if (!(*list))
	{
		new_node->next = new_node->prev = new_node;
		*list = new_node;
		return (new_node);
	}

	last_node = (*list)->prev;
	new_node->next = *list;
	new_node->prev = last_node;
	(*list)->prev = new_node;
	last_node->next = new_node;

	return (new_node);
}

/**
 * add_nodeadd_node_begin_end - Adds a new node to the beginning
 * of a double circular linked list.
 *
 * @list: the list to modify
 * @str: the string to copy into the new node
 *
 * Return: the address of the new node, or NULL on failure.
 */
List *add_node_begin(List **list, char *str)
{
	List *new_node, *last_node;

	if (!list)
		return (NULL);

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);

	new_node->str = strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}

	if (!(*list))
	{
		new_node->next = new_node->prev = new_node;
		*list = new_node;
		return (new_node);
	}

	last_node = (*list)->prev;
	new_node->prev = last_node;
	new_node->next = (*list);
	(*list)->prev = new_node;
	last_node->next = new_node;
	(*list) = new_node;

	return (new_node);
}
