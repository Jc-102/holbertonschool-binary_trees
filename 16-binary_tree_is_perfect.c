#include "binary_trees.h"

/**
 * tree_height - measures the height of a tree (edges, leaf = 0)
 * @tree: pointer to the node to measure
 *
 * Return: the height of the tree
 */

int tree_height(const binary_tree_t *tree)
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
 * tree_size - counts the total number of nodes in a tree
 * @tree: pointer to the root node of the tree
 *
 * Return: the number of nodes
 */
size_t tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height;
	size_t size;
	size_t expected_size;

	if (tree == NULL)
		return (0);

	height = tree_height(tree);
	size = tree_size(tree);
	expected_size = (size_t)(1UL << (height + 1)) - 1;

	return (size == expected_size);
}
