#include "binary_trees.h"

/**
 * tree_height - measures the height of a tree, treating NULL as -1
 * @tree: pointer to the node to measure
 *
 * Return: the height, or -1 if tree is NULL
 */

static int tree_height(const binary_tree_t *tree)
{
	int left_height;
	int right_height;

	if (tree == NULL)
		return (-1);

	left_height = tree_height(tree->left);
	right_height = tree_height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);

	return (right_height + 1);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure
 *
 * Return: the balance factor, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (tree_height(tree->left) - tree_height(tree->right));
}
