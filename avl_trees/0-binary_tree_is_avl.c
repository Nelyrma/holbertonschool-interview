#include "binary_trees.h"

/**
 * height - calculates the height of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: height of the tree
 */
int height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = height(tree->left);
	right_height = height(tree->right);

	return (left_height > right_height ? left_height + 1 : right_height + 1);
}

/**
 * is_bst - checks if a binary tree is a valid Binary Search Tree (BST)
 * @tree: pointer to the root node of the tree to check
 * @min: minimum value allowed
 * @max: maximum value allowed
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (is_bst(tree->left, min, tree->n) &&
			is_bst(tree->right, tree->n, max));
}

/**
 * is_avl - checks if a binary tree is a valid AVL tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise
 */
int is_avl(const binary_tree_t *tree)
{
	int left_height, right_height, balance_factor;

	if (tree == NULL)
		return (1);

	if (!is_bst(tree, INT_MIN, INT_MAX))
		return (0);

	left_height = height(tree->left);
	right_height = height(tree->right);
	balance_factor = left_height - right_height;

	if (balance_factor > 1 || balance_factor < -1)
		return (0);

	return (is_avl(tree->left) && is_avl(tree->right));
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_avl(tree));
}
