#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - Inserts a number into a sorted singly linked list.
 * @head: Double pointer to the head of the list.
 * @number: The number to insert.
 *
 * Return: Address of the new node, or NULL if it failed.
 */

listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new_node;

    new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
        return NULL;
    
    new_node->n = number;
    new_node->next = NULL;

    // if the list is empty or if the new number will be inserted at the beginning
    if (*head == NULL || (*head)->n >= number)
    {
        new_node->next = *head;
        *head = new_node;
        return new_node;
    }

    listint_t *current = *head;
    while (current->next != NULL && current->next->n < number)
    {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;

    return new_node;
}