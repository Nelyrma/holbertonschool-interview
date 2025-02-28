#include "lists.h"
#include <stddef.h>

/**
 * validate_palindrome - Recursively checks if a singly linked list is a palindrome.
 * @front: Double pointer to the head of the list.
 * @back: Pointer to the current node in recursion (moving towards tail).
 *
 * Return: 1 if it's a palindrome, 0 otherwise.
 */
int validate_palindrome(listint_t **front, listint_t *back)
{
    int is_valid;

    if (!back)
        return (1);

    is_valid = validate_palindrome(front, back->next);

    if (!is_valid || (*front)->n != back->n)
        return (0);

    *front = (*front)->next;

    return (1);
}

/**
 * is_palindrome - Determines if a singly linked list is a palindrome.
 * @head: Double pointer to the head of the list.
 *
 * Return: 1 if it's a palindrome, 0 otherwise.
 */
int is_palindrome(listint_t **head)
{
    if (!head || !*head)
        return (1);

    return (validate_palindrome(head, *head));
}
