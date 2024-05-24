#include <stdlib.h>
#include "binary_trees.h"

/**
 * find_parent_node - search parent node of the next node to be inserted
 * @root: pointer to root node of the Heap
 * @height: height of the tree
 * Return: pointer to parent node
 */
heap_t *find_parent_node(heap_t *root, int height)
{
    if (root == NULL || height < 2)
        return (NULL);

    if (height == 2)
    {
        if (root->left == NULL || root->right == NULL)
            return (root);
        else
            return (NULL);
    }

    heap_t *parent = find_parent_node(root->left, height - 1);
    if (parent == NULL)
        parent = find_parent_node(root->right, height - 1);

    return (parent);
}

/**
 * swap_nodes - swaps the values of two nodes
 * @node1: pointer to the first node
 * @node2: pointer to the second node
 */
void swap_nodes(heap_t *node1, heap_t *node2)
{
    if (node1 == NULL || node2 == NULL)
        return;

    int temp = node1->n;
    node1->n = node2->n;
    node2->n = temp;
}

/**
 * height_tree - finds the height of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: height of the tree
 */
int height_tree(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    int left_height = height_tree(tree->left);
    int right_height = height_tree(tree->right);

    return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value to store in the node to be inserted
 * Return: pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    if (root == NULL)
        return (NULL);

    heap_t *new_node = binary_tree_node(NULL, value);
    if (new_node == NULL)
        return (NULL);

    if (*root == NULL)
    {
        *root = new_node;
        return (new_node);
    }

    int height = height_tree(*root);
    heap_t *parent = find_parent_node(*root, height);
    if (parent == NULL)
    {
        heap_t *move = *root;
        while (move->left != NULL)
            move = move->left;
        parent = move;
    }

    if (parent->left == NULL)
        parent->left = new_node;
    else
        parent->right = new_node;

    new_node->parent = parent;

    while (new_node->parent != NULL && new_node->n > new_node->parent->n)
    {
        swap_nodes(new_node, new_node->parent);
        new_node = new_node->parent;
    }

    return (new_node);
}
